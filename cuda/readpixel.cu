// g++ readpixel.cpp -o readpixel -lGL -lglut
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include <stdio.h>
#include <cuda_gl_interop.h>

int mx = 0, my = 0;
int WIDTH=800, HEIGHT=600;
GLuint pbo=0;
char * bits = NULL;
int usepbo = 1;
struct cudaGraphicsResource *cuda_pbo_dest_resource;

// Some dummy kernel to prevent optimizations
__global__ void kernel(char* in)
{
    int index = threadIdx.x + blockIdx.x*blockDim.x;
    in[index] = in[index]-1;
}

#define cutilSafeCall(err)  __cudaSafeCall(err,__FILE__,__LINE__)
inline void __cudaSafeCall(cudaError err,
                           const char *file, const int line){
  if(cudaSuccess != err) {
    printf("%s(%i) : cutilSafeCall() Runtime API error : %s.\n",
           file, line, cudaGetErrorString(err) );
    exit(-1);
  }
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
        unsigned char pixels[ 1 * 1 * 4 ] = { 0 };
        glReadPixels( mx, my, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, pixels );
        printf("r: %d\n", pixels[ 0 ] );
        printf("g: %d\n", pixels[ 1 ] );
        printf("b: %d\n", pixels[ 2 ] );
        printf("a: %d\n", pixels[ 3 ] );
    }else{
        glReadBuffer(GL_FRONT);
        glBindBuffer(GL_PIXEL_PACK_BUFFER, pbo);
        glReadPixels(0, 0, WIDTH, HEIGHT, GL_BGRA, GL_UNSIGNED_BYTE, 0);
        //unsigned char* pboBits = NULL;
        //pboBits = (unsigned char *)glMapBuffer(GL_PIXEL_PACK_BUFFER, GL_READ_ONLY);
        //if(!pboBits){printf("Could not map pboBits\n"); return;}
        //printf("r: %d\n", pboBits[(my*WIDTH+ mx)*4 + 0 ] );
        //printf("g: %d\n", pboBits[(my*WIDTH+ mx)*4 + 1 ] );
        //printf("b: %d\n", pboBits[(my*WIDTH+ mx)*4 + 2 ] );
        //printf("a: %d\n", pboBits[(my*WIDTH+ mx)*4 + 3 ] );
        //glUnmapBuffer(GL_PIXEL_PACK_BUFFER_EXT);

        cutilSafeCall(cudaGraphicsMapResources(1, &cuda_pbo_dest_resource));
        size_t size = 0;
        void* device_ptr = NULL;
        cutilSafeCall( cudaGraphicsResourceGetMappedPointer(&device_ptr, &size, cuda_pbo_dest_resource) );
        glBindBuffer(GL_PIXEL_PACK_BUFFER_EXT, 0);

        kernel<<<size/512,512>>>((char*)device_ptr);
        cudaDeviceSynchronize();
        cutilSafeCall( cudaGraphicsUnmapResources(1, &cuda_pbo_dest_resource) );

    }

    glutSwapBuffers();
}

void mouse( int x, int y )
{
    mx = x;
    my = glutGet( GLUT_WINDOW_HEIGHT ) - y;
    glutPostRedisplay();
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
