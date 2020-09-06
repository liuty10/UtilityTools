TARGET=main
SOURCE=./main.c

#TARGET=pthread_example
#SOURCE=./pthread_example.c

CFLAGS=-I$(PFM_PATH)/libpfm4/perf_examples/ -I$(PFM_PATH)/libpfm4/include/ -I/media/lty/newspace/pfm/pfm_multi/ -I/media/lty/newspace/pfm/libpfm4/include/perfmon -I./include
LIBS=-lpthread -lrt $(PFM_PATH)/libpfm4/lib/libpfm.a -L./lib -linterceptglxx

all: ${TARGET}
${TARGET}:${SOURCE}
	gcc ${CFLAGS} -o ${TARGET} ${SOURCE} ${LIBS}

clean:
	rm ${TARGET}
