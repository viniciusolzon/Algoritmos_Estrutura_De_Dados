
output: main.o list_het.o
	gcc main.o list_het.o -o output

main.o: main.c
	gcc -c main.c

list_het.o: list_het.c list_het.h
	gcc -c list_het.c

clean:
	rm *.o output