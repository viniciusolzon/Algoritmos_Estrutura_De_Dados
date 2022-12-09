#include "stack.h"
#include <stdio.h>

/*
    PILHA -> TIPO DE LISTA COM RESTRIÇÃO DE ACESSO AO TOPO.
    LIFO -> Last In First Out.
*/

int main(){

    no *head;
    head = 0;

    push(&head);
    push(&head);
    push(&head);
    push(&head);
    push(&head);

    printf("\nElementos da pilha:\n");
    show_stack(&head);

    clear_stack(&head);

    printf("\nElementos da pilha:\n");
    show_stack(&head);

    return 0;
}
