// gcc -shared -ldl -fPIC file1.c file2.c -o libfile.so 
/* file1.c */
void file1(int *i)
{
    *i=100;
}
