#include <sys/types.h>
#include <unistd.h>
#include <time.h>

long long gettime_nanoTime(void)
{
    struct timespec __tv;
    clock_gettime(CLOCK_MONOTONIC,&__tv);
    return(long long)(__tv.tv_sec * 1e9 + __tv.tv_nsec);
}

void
MY_TRACE (void)
{
  void *array[10];
  size_t size;
  char **strings;
  size_t i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);

  MY_LOG ("Obtained %zd stack frames.\n", size);

  for (i = 0; i < size; i++)
     MY_LOG ("%s\n", strings[i]);

  free (strings);
}

