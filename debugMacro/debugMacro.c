#include<stdio.h>

#ifdef DEBUG
 # define DBG(x) ((void)(x))
#else
 # define DBG(x) ((void)0)
#endif

int main(){
   printf("hello c from printf...\n");
   DBG(fprintf(stderr, "hello c from DBG...\n"));
   return 0;
}
