#include <execinfo.h>
#define MY_LOG(fmt, ...)				\
	do { fprintf(stderr, "%s: "fmt , __func__,	\
		     ## __VA_ARGS__);} while (0);

long long gettime_nanoTime(void);
void MY_TRACE(void);
