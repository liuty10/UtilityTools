# g++ -shared -fPIC interceptglx.cpp -o libinterceptglx.so
CC=g++
TARGET=libinterceptgl.so
SOURCE=./interceptgl.cpp ./util.cpp ./perf_util.cpp

CFLAGS=-I$(PFM_PATH)/libpfm4/perf_examples/ -I$(PFM_PATH)/libpfm4/include/ -I$(PFM_PATH)/pfm_multi/ -I./ -shared -fPIC -Wl,--no-as-needed
LIBS=-lrt -ldl /media/lty/newspace/pfm/libpfm4/lib/libpfm.a


all: ${TARGET}

${TARGET}:${SOURCE}
	$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@ $(LIBS)

.PHONY:
clean:
	rm ${TARGET}
