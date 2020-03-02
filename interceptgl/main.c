#include<stdio.h>
#include "util.h"

int main(){
	perf_start("instructions,cycles",0);
        printf("hello\n");	
	perf_end();
	return 0;
}
