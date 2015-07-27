all: cumd

cumd: cumd.c cumd.h
	gcc -o cumd cumd.c -lrt # -DDEBUG

example: example.c cumd.h
	gcc -o example example.c -lrt

.PHONY: clean
clean:
	rm -f example cumd
