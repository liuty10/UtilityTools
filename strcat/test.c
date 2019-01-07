#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   char str1[10];
   char logpath[80] ={'/','t','m','p','/','v','g','l','/'};
   printf("befor: %s\n", logpath);
   sprintf(str1, "%d", 11);
   strcat(logpath, str1);
   printf("after: %s\n", logpath);

   FILE *fd = fopen(logpath, "a");

   printf("fd: %p\n", fd);
   fclose(logpath);
   return 0;
}

