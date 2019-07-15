#include <stdio.h>
#include <stdlib.h>
 
int main(int argc,char* argv[]) {
    //char* user=getenv("USER");
    char* user=getenv("DISPLAY");
    if(user!=NULL)
	printf("USER='%s'\n",user);
    return 0;
}
