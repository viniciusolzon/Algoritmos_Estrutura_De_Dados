
output: main.o circ_double_linked_list.o
	gcc main.o circ_double_linked_list.o -o output

main.o: main.c
	gcc -c main.c

circ_double_linked_list.o: circ_double_linked_list.c circ_double_linked_list.h
	gcc -c circ_double_linked_list.c

clean:
	rm *.o output