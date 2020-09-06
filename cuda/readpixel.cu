// g++ readpixel.cpp -o readpixel -lGL -lglut

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cuda_gl_interop.h>

#define WIDTH 800
#define HEIGHT 600

int mx = 0, my = 0;
GLuint pbo=0;
char * bits = NULL;
int usepbo = 1;
struct cudaGraphicsResource *cuda_pbo_dest_resource;

#define cutilSafeCall(err)  __cudaSafeCall(err,__FILE__,__LINE__)
inline void __cudaSafeCall(cudaError err,
                           const char *file, const int line){
  if(cudaSuccess != err) {
    printf("%s(%i) : cutilSafeCall() Runtime API error : %s.\n",
           file, line, cudaGetErrorString(err) );
    exit(-1);
  }
}

__global__ void rgb2yuv420Kernel(unsigned char* rgbImg, unsigned char* yuv420){
    unsigned char r, g, b;
    unsigned char y, cb, cr;
 
    int index,i,j;
    index = threadIdx.x + blockIdx.x * blockDim.x;
    i = index/WIDTH;
    j = index%WIDTH;
    
    r = rgbImg[index*3 + 0];
    g = rgbImg[index*3 + 1];
    b = rgbImg[index*3 + 2];
     
    y  = (unsigned char)( 0.299*r + 0.587*g +  0.114*b);
    cb = (unsigned char)(-0.147*r - 0.289*g +  0.463*b + 128);
    cr = (unsigned char)( 0.615*r - 0.515*g - 0.1*b + 128);
     
    rgbImg[index*3 + 0] = y;
    rgbImg[index*3 + 1] = cb;
    rgbImg[index*3 + 2] = cr;

    yuv420[index + 0] = y;
    if(i%2 == 0 && j%2 == 0){
        yuv420[(i/2)*(WIDTH/2) + (j/2) + WIDTH*HEIGHT] = cb;
        yuv420[(i/2)*(WIDTH/2) + (j/2) + WIDTH*HEIGHT*5/4] = cr;
    }
}

void nv_encoding(){
    m_cuContext->SetCurrent(); // Make Clients context current
    MapInputResource(id); //Map the CudaInputResource
    NV_ENC_PIC_PARAMS temp;
    memset(&temp, 0, sizeof(NV_ENC_PIC_PARAMS));
    temp.version = NV_ENC_PIC_PARAMS_VER;
    unsigned int currentBufferAndEvent = m_counter % m_registeredEvents.size(); //Counter is inc'ed in every Frame
    temp.bufferFmt = m_currentlyMappedInputBuffer.mappedBufferFmt;
    temp.inputBuffer = m_currentlyMappedInputBuffer.mappedResource; //got set by MapInputResource
    temp.completionEvent = m_registeredEvents[currentBufferAndEvent];
    temp.outputBitstream = m_registeredOutputBuffers[currentBufferAndEvent];
    temp.inputWidth = m_width;
    temp.inputHeight = m_height;
    temp.inputPitch = m_width;
    temp.inputTimeStamp = m_counter;
    temp.pictureStruct = NV_ENC_PIC_STRUCT_FRAME; // According to samples
    temp.qpDeltaMap = NULL;
    temp.qpDeltaMapSize = 0;

    EventWithId latestEvent(currentBufferAndEvent,
                  m_registeredEvents[currentBufferAndEvent]);
    PushBackEncodeEvent(latestEvent); // Store the Event with its ID in a Queue

    CheckApiError(m_apiFunctions.nvEncEncodePicture(m_Encoder, &temp));
    m_counter++;
    UnmapInputResource(id); // Unmap
}

void display()
{
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -10, 10, -10, 10, -1, 1 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glScalef( 5, 5, 5 );
    glBegin( GL_TRIANGLES );
    glColor3ub( 255, 0, 0 );
    glVertex2f( -1, -1 );
    glColor3ub( 0, 255, 0 );
    glVertex2f( 1, -1 );
    glColor3ub( 0, 0, 255 );
    glVertex2f( 0, 1 );
    glEnd();

    // 4 bytes per pixel (RGBA), 1x1 bitmap
    if(!usepbo){
        unsigned char pixels[ 1 * 1 * 3 ] = { 0 };
        glReadPixels( mx, my, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixels );
        printf("r: %d\n", pixels[ 0 ] );
        printf("g: %d\n", pixels[ 1 ] );
        printf("b: %d\n", pixels[ 2 ] );
    }else{
        glReadBuffer(GL_FRONT);
        glBindBuffer(GL_PIXEL_PACK_BUFFER, pbo);
        glReadPixels(0, 0, WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_BYTE, 0);
        unsigned char* pboBits = NULL;
        pboBits = (unsigned char *)glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
        if(!pboBits){printf("Could not map pboBits\n"); return;}
        printf("r: %d\n", pboBits[(my*WIDTH+ mx)*3 + 0 ] );
        printf("g: %d\n", pboBits[(my*WIDTH+ mx)*3 + 1 ] );
        printf("b: %d\n", pboBits[(my*WIDTH+ mx)*3 + 2 ] );
        glUnmapBuffer(GL_PIXEL_PACK_BUFFER_EXT);

        cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_dest_resource));
        size_t size = 0;
        void* device_ptr = NULL;
        cutilSafeCall( cudaGraphicsResourceGetMappedPointer(&device_ptr, &size, cuda_pbo_dest_resource) );
        glBindBuffer(GL_PIXEL_PACK_BUFFER_EXT, 0);

        unsigned char* d_yuvOut;
        cudaMalloc((void**)&d_yuvOut, WIDTH*HEIGHT*3/2);
        rgb2yuv420Kernel<<<WIDTH*HEIGHT/256,256>>>((unsigned char*)device_ptr, d_yuvOut);
        cudaDeviceSynchronize();
        cutilSafeCall( cudaGraphicsUnmapResources(1, &cuda_pbo_dest_resource) );

        
        glBindBuffer(GL_PIXEL_PACK_BUFFER, pbo);
        pboBits = NULL;
        pboBits = (unsigned char *)glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
        if(!pboBits){printf("Could not map pboBits\n"); return;}
        printf("y: %d\n", pboBits[(my*WIDTH+ mx)*3 + 0 ] );
        printf("Cb: %d\n", pboBits[(my*WIDTH+ mx)*3 + 1 ] );
        printf("Cr: %d\n", pboBits[(my*WIDTH+ mx)*3 + 2 ] );
        glUnmapBuffer(GL_PIXEL_PACK_BUFFER_EXT);
        glBindBuffer(GL_PIXEL_PACK_BUFFER_EXT, 0);

    }

    glutSwapBuffers();
}

void mouse( int x, int y )
{
    mx = x;
    my = glutGet( GLUT_WINDOW_HEIGHT ) - y;
    glutPostRedisplay();
}

void nvenc_init(){
    InitParams* ip = new InitParams();
    m_initParams = ip;
    memset(ip, 0, sizeof(InitParams));
    ip->version = NV_ENC_INITIALIZE_PARAMS_VER;
    ip->encodeGUID = m_encoderGuid;  //Used Codec
    ip->encodeWidth = width; // Frame Width
    ip->encodeHeight = height; // Frame Height
    ip->maxEncodeWidth = 0; // Zero means no dynamic res changes
    ip->maxEncodeHeight = 0; 
    ip->darWidth = width; // Aspect Ratio
    ip->darHeight = height; 
    ip->frameRateNum = 60; // 60 fps
    ip->frameRateDen = 1; 
    ip->reportSliceOffsets = 0; // According to programming guide
    ip->enableSubFrameWrite = 0;
    ip->presetGUID = m_presetGuid; // Used Preset for Encoder Config

    NV_ENC_PRESET_CONFIG presetCfg; // Load the Preset Config
    memset(&presetCfg, 0, sizeof(NV_ENC_PRESET_CONFIG));
    presetCfg.version = NV_ENC_PRESET_CONFIG_VER;
    presetCfg.presetCfg.version = NV_ENC_CONFIG_VER;
    CheckApiError(m_apiFunctions.nvEncGetEncodePresetConfig(m_Encoder,
                             m_encoderGuid, m_presetGuid, &presetCfg));
    memcpy(&m_encodingConfig, &presetCfg.presetCfg, sizeof(NV_ENC_CONFIG));
    // And add information about Bitrate etc
    m_encodingConfig.rcParams.averageBitRate = 500000;
    m_encodingConfig.rcParams.maxBitRate = 600000;
    m_encodingConfig.rcParams.rateControlMode = NV_ENC_PARAMS_RC_MODE::NV_ENC_PARAMS_RC_CBR;
    ip->encodeConfig = &m_encodingConfig;
    ip->enableEncodeAsync = 1; // Async Encoding
    ip->enablePTD = 1; // Encoder handles picture ordering

    // Registration of CudaResource
    m_cuContext->SetCurrent(); // Make the clients cuCtx current
    NV_ENC_REGISTER_RESOURCE res;
    memset(&res, 0, sizeof(NV_ENC_REGISTER_RESOURCE));
    NV_ENC_REGISTERED_PTR resPtr; // handle to the cuda resource for future use
    res.bufferFormat = m_inputFormat; // Format is ARGB
    res.height = m_height;
    res.width = m_width;
    // NOTE: I've set the pitch to the width of the frame, because the resource is a non-pitched 
    //cudaArray. Is this correct? Pitch = 0 would produce no output.
    res.pitch = pitch; 
    res.resourceToRegister = (void*) (uintptr_t) resourceToRegister; //CUdevptr to resource
    res.resourceType = NV_ENC_INPUT_RESOURCE_TYPE::NV_ENC_INPUT_RESOURCE_TYPE_CUDADEVICEPTR;
    res.version = NV_ENC_REGISTER_RESOURCE_VER;
    CheckApiError(m_apiFunctions.nvEncRegisterResource(m_Encoder, &res));
    m_registeredInputResources.push_back(res.registeredResource);
}

void init(){
        if(!pbo) {
             glGenBuffers(1, &pbo);
             glBindBuffer(GL_PIXEL_PACK_BUFFER_EXT, pbo);
             glBufferData(GL_PIXEL_PACK_BUFFER_EXT, WIDTH * HEIGHT * 4, NULL,GL_STREAM_READ);
             int size = 0;
             glGetBufferParameteriv(GL_PIXEL_PACK_BUFFER_EXT, GL_BUFFER_SIZE, &size);
             if(size != WIDTH * HEIGHT*4){
                 printf("Could not set PBO size\n");
                 return;
             }
             //bits = (char *)malloc(WIDTH*HEIGHT*4);
             cutilSafeCall( cudaGraphicsGLRegisterBuffer(&cuda_pbo_dest_resource, pbo, cudaGraphicsMapFlagsNone) );
        }
        nvenc_init();
}

void end(){
    // Unmap and unregister the graphics resource
    cutilSafeCall( cudaGraphicsUnregisterResource(cuda_pbo_dest_resource) );
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow( "glReadPixels() example" );
    glutDisplayFunc( display );
    glutPassiveMotionFunc( mouse );
    init();
    glutMainLoop();
    end();
    return 0;
}
