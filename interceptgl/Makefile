TARGET=libinterceptgl.so
SOURCE=./interceptgl.c ./util.h ./util.c

all: ${TARGET}
${TARGET}:${SOURCE}
	gcc -shared -ldl -fPIC ${SOURCE} -o ${TARGET}

#app:./pic.c
#	gcc pic.c -o pic -lX11

#run:
#	LD_PRELOAD=./libmyxputimage.so ./pic

clean:
	rm ${TARGET}
#    gcc hi.c -o hi -lX11
#    gcc hi.c -o hi -I /usr/include/X11 -L /usr/X11/lib -lX11
#    gcc hi.c -o hi -I /sowhere/else -L /who/knows/where -lX11 
