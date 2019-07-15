#include <stdio.h>
int main(){
    int a = 0x7fffffff;
    long b = 0x7fffffffffffffff;
    long long c = 3;
    unsigned int a2 = 4;
    unsigned long b2 = 0x7fffffffffffffff;
    unsigned long long c2 = 6;
    printf("int  	 	size:%d\n",sizeof(a));
    printf("long 	 	size:%d\n",sizeof(b));
    printf("long long 	 	size:%d\n",sizeof(c));
    printf("unsigned int 	size:%d\n",sizeof(a2));
    printf("unsigned long 	size:%d\n",sizeof(b2));
    printf("unsigned long long 	size:%d\n",sizeof(c2));
    printf("int b: %d\n",b);
    printf("long b: %ld\n",b);
    printf("unsigned long b: %lu\n",b2);
    printf("unsigned long b: %llu\n",b2);
    return 0;
}
