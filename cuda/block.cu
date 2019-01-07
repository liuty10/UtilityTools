#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <unistd.h>

__global__ void add(int *a, int *b, int *c){
	c[blockIdx.x] = a[blockIdx.x] + b[blockIdx.x];
}

#define N 512
int random_ints(int *p, int n){
	int i;
	for(i=0;i<n;i++)
		*p++ = rand();
	return 0;
}


int main(){
	int *a, *b, *c;
	int *d_a, *d_b, *d_c;
	int size = N*sizeof(int);

	cudaSetDevice(1);
	cudaMalloc((void**)&d_a, size);
	cudaMalloc((void**)&d_b, size);
	cudaMalloc((void**)&d_c, size);

	a = (int*)malloc(size);
	b = (int*)malloc(size);
	c = (int*)malloc(size);
	random_ints(a,N);
	random_ints(b,N);
	a[N-1] = 100;
	b[N-1] = 200;

	cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);
	add<<<N,1>>>(d_a, d_b, d_c);
	cudaDeviceSynchronize();
	cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);
	printf("result = %d\n",c[N-1]);

	free(a);
	free(b);
	free(c);
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);

	return 0;
}
