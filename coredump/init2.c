#include<stdio.h>
int main(){
  char *ptr = (char*)malloc(1024*4*1024);
  int i;
  for(i=0;i<1024*4*1024;i++)
      printf("%d\n",*(ptr+i));
  return 0;
}
