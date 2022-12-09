
output: main.o avl_tree.o
	gcc main.o avl_tree.o -o output

main.o: main.c
	gcc -c main.c

avl_tree.o: avl_tree.c avl_tree.h
	gcc -c avl_tree.c

clean:
	rm *.o output