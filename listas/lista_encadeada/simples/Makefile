
output: main.o linked_list.o
	gcc main.o linked_list.o -o output

main.o: main.c
	gcc -c main.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm *.o output