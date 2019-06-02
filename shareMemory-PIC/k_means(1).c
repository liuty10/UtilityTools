/*
 * Skeleton function for CS6643 Parallel Processing, 
 * Assignment 2: K-Means Algorithm (Sequential)
 *
 * To students: You should finish the implementation of k_means function
 * 
 * Author:
 *     Wei Wang <wei.wang@utsa.edu>
 */
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "k_means.h"
/*
 * k_means: k_means clustering algorithm implementation.
 *
 * Input parameters:
 *     struct point p[]: array of data points
 *     int m           : number of data points in p[]
 *     int k           : number of clusters to find
 *     int iters       : number of clustering iterations to run
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
	    int c[MAX_POINTS])
{
	int i, j, l; /* To Students: add your local variables */
        double MAX_DOUBLE = 1000000000000.0;
	/* randomly initialized the centers */
	#pragma omp parallel for
	for(j = 0; j < k; j++)
		u[j] = random_center(p); /* DO NOT change this random generator! */
	/* 
	 * To students: please implment K-Means algorithm here 
	 * Your K-means implementation should do "iters" rounds of clustering. After 
	 * all iterations finish, array u[MAX_CENTERS] should have the coordinations 
	 * of your centers, and array c[MAX_POINTS] should have the cluster assignment
	 * for each point.
	 */
        #pragma omp barrier
        for(l=0; l< iters; l++){
        	/* find nearest center to each pointer */
                #pragma omp parallel private(i)
		{
		#pragma omp for
		for(j=0; j<m; j++){
                	double min_dist = MAX_DOUBLE;
			for(i=0; i<k; i++){
				double dist = (p[j].x-u[i].x)*(p[j].x-u[i].x)+(p[j].y-u[i].y)*(p[j].y-u[i].y);
                        	if(dist < min_dist){
					min_dist = dist;
					c[j] = i;
				}
			}
		}//endfor
		}
		#pragma omp barrier
		/*based on the cluster asignment, update the center for each cluster*/
		#pragma omp parallel private(i)
		{
		#pragma omp for
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
		#pragma omp barrier
        }
	return;
}
