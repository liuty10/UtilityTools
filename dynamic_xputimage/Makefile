all: mylib app

mylib:./myxputimage.c
	gcc -shared -ldl -fPIC myxputimage.c -o libmyxputimage.so

app:./pic.c
	gcc pic.c -o pic -lX11

run:
	LD_PRELOAD=./libmyxputimage.so ./pic

clean:
	rm libmyxputimage.so pic
#    gcc hi.c -o hi -lX11
#    gcc hi.c -o hi -I /usr/include/X11 -L /usr/X11/lib -lX11
#    gcc hi.c -o hi -I /sowhere/else -L /who/knows/where -lX11 
