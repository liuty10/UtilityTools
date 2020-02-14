#define PICTOR_LOG(fmt, ...)				\
	do { fprintf(stderr, "%s: "fmt , __func__,	\
		     ## __VA_ARGS__);} while (0);

