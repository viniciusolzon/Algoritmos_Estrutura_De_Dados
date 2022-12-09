
output: main.o circ_linked_list.o
	gcc main.o circ_linked_list.o -o output

main.o: main.c
	gcc -c main.c

circ_linked_list.o: circ_linked_list.c circ_linked_list.h
	gcc -c circ_linked_list.c

clean:
	rm *.o output