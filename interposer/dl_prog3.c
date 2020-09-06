// gcc -shared -ldl -fPIC dl_prog3.c -o libdl_prog3.so
#define __USE_GNU
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
 
extern void *__libc_dlsym (void *, const char *);
void *dlsym(void *handle, const char *symbol)
{
    printf("Ha Ha...dlsym() Hooked\n");
    void* result = __libc_dlsym(handle, symbol); /* now, this will call dlsym() library function */
    return result;
}
