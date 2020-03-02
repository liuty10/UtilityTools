CC=gcc
TARGET=libinterceptgl.so
SOURCE=./interceptgl.c ./util.c ./perf_util.c

CFLAGS=-I$(PFM_PATH)/libpfm4/perf_examples/ -I$(PFM_PATH)/libpfm4/include/ -I$(PFM_PATH)/pfm_multi/ -I./ -shared -fPIC
LIBS=-lpthread -lrt /media/lty/newspace/pfm/libpfm4/lib/libpfm.a


all: ${TARGET}

${TARGET}:${SOURCE}
	$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY:
clean:
	rm ${TARGET}
