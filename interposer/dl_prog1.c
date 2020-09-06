// gcc -rdynamic -o dl_prog1 dl_prog1.c -ldl
#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
 
void file1(int *i);
void file2(int *i);
int main(void)
{
    void *handler;
    int (*fn) (int *);
    int x;
    char *error;
    handler = dlopen("./libfile.so", RTLD_LAZY);
    if (!handler)
    {
        fprintf(stderr,"%s\n", dlerror());
        exit(1);
    }
    fn = dlsym(handler,"file1");     /* getting the handle of file1 through dlsym() */
    if ((error = dlerror()) != NULL) /* checking error through dlerror() */
    {
        fprintf(stderr,"%s\n", error);
        exit(1);
    }
    (*fn)(&x);                            /* Calling file1() to resolve x */
    printf("The value of x is %d\n", x);
    dlclose(handler);                 /* closing the file handle */
    return 0;
}
