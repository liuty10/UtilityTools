
/*
 * Skeleton function for Parallel Computing Class, 
 * Assignment: K-Means Algorithm (CUDA)
 *
 * To students: You should finish the implementation of k_means algorithm.
 *              You should add device functions/kernels to perform k_means on 
 *              GPU. The "k_means" function in this file is just an interface
 *              for passing in basic parameters needed.. You need to add GPU 
 *              kernels and launch them in the "k_means" function.
 *
 *              Note that the "k_means" function has two input parameters for
 *              block count and thread count per block. Please use these two
 *              parameters when launching your kernels.
 * 
 * Author:
 *     Tianyi Liu <tianyi.liu@utsa.edu>
 */
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "k_means.h"
__global__ void assignClusters(struct point *d_p, struct point *d_u, int *d_c, int *d_m, int *d_k, int block, int threads){
      int i,j;
      double dist;
      int taskPerWorker = (*d_m)/(block*threads);
      int lastTask = (*d_m)%(block*threads);
      if(lastTask!=0) taskPerWorker+=1;
      int index = blockIdx.x * blockDim.x + threadIdx.x;//number of thread
      if(index >= (*d_m)) return;
      for(j=index*taskPerWorker; j<(index+1)*taskPerWorker && j<(*d_m); j++){
          double min_dist = 1000000000000.0;
          for(i=0; i<(*d_k); i++){
                  dist = (d_p[j].x-d_u[i].x)*(d_p[j].x-d_u[i].x)+
                         (d_p[j].y-d_u[i].y)*(d_p[j].y-d_u[i].y);
                  if(dist < min_dist){
                          min_dist = dist;
                          d_c[j] = i;
                  }
          }
      }
}

void computeNewCenter(struct point *p, struct point *u, int* c, int m, int k){
      int i,j;
      for(j=0; j<k; j++){
              double sum_x = 0.0;
              double sum_y = 0.0;
              int cluster_size = 0;
              for(i=0; i<m; i++){
                      if(c[i] == j){
                              sum_x += p[i].x;
                              sum_y += p[i].y;
                              cluster_size++;
                      }
              }
              if(cluster_size > 0){
                      u[j].x = sum_x/cluster_size;
                      u[j].y = sum_y/cluster_size;
              }else{
                      u[j] = random_center(p);
              }
      }
}
/*
 * k_means: k_means clustering algorithm implementation.
 *
 * Input parameters:
 *     struct point p[]: array of data points
 *     int m           : number of data points in p[]
 *     int k           : number of clusters to find
 *     int iters       : number of clustering iterations to run
 *     int block_cnt   : number of blocks to use
 *     int threads_per_block: number of threads per block
 *
 * Output parameters:   
 *     struct point u[]: array of cluster centers
 *     int c[]         : cluster id for each data points
 */
void k_means(struct point p[MAX_POINTS], 
	     int m, 
	     int k,
	     int iters,
	     struct point u[MAX_CENTERS],
	     int c[MAX_POINTS],
	     int block_cnt,
	     int threads_per_block)
{
	int j;
	
	/* randomly initialized the centers */
	for(j = 0; j < k; j++)
		u[j] = random_center(p);
	/*
	 * To students: This function is not a GPU kernel. You need to add your
	 * own kernel functions in this file. Block count and thread count per
	 * count are provided as parameters to this functions. Please use these
	 * two parameters when launching your kernels.
	 */
        int *d_m, *d_k;
        int *d_c;
        struct point *d_u, *d_p;
        cudaSetDevice(1);

        cudaMalloc((void**)&d_m, sizeof(int));
        cudaMalloc((void**)&d_k, sizeof(int));
        cudaMalloc((void**)&d_p, MAX_POINTS*sizeof(struct point));

        cudaMalloc((void**)&d_u, MAX_CENTERS*sizeof(struct point));
        cudaMalloc((void**)&d_c, MAX_POINTS*sizeof(int));

        cudaMemcpy(d_m, &m, sizeof(int), cudaMemcpyHostToDevice);
        cudaMemcpy(d_k, &k, sizeof(int), cudaMemcpyHostToDevice);
        cudaMemcpy(d_p, p, MAX_POINTS*sizeof(struct point), cudaMemcpyHostToDevice);
        int l;
        for(l=0; l< iters; l++){
                cudaMemcpy(d_c, c, MAX_POINTS*sizeof(int), cudaMemcpyHostToDevice);
                cudaMemcpy(d_u, u, MAX_CENTERS*sizeof(struct point), cudaMemcpyHostToDevice);
                assignClusters<<<block_cnt, threads_per_block>>>(d_p, d_u, d_c, d_m, d_k, block_cnt, threads_per_block);
                //assignClusters(p, u, c, m, k);

                cudaDeviceSynchronize();

                cudaMemcpy(c, d_c, MAX_POINTS*sizeof(int), cudaMemcpyDeviceToHost);
                computeNewCenter(p, u, c, m, k);
                //computeNewCenter<<<1,1>>>(d_p, d_u, d_c, d_m, d_k);
        }
        /*based on the cluster asignment, update the center for each cluster*/
        //cudaMemcpy(u, d_u, MAX_CENTERS*sizeof(struct point), cudaMemcpyDeviceToHost);
  	return;
}
