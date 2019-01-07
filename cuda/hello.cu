#include <stdio.h>

__global__ void mykernel(void){

}

int main(void){
    int deviceCount;
    mykernel<<<1,1>>>();
    cudaGetDeviceCount(&deviceCount);
    printf("Hello World! Total Device: %d\n", deviceCount);
    return 0;
}
