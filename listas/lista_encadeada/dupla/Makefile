
output: main.o double_linked_list.o
	gcc main.o double_linked_list.o -o output

main.o: main.c
	gcc -c main.c

double_linked_list.o: double_linked_list.c double_linked_list.h
	gcc -c double_linked_list.c

clean:
	rm *.o output