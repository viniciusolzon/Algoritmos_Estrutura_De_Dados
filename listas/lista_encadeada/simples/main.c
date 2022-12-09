#include "linked_list.h"
#include <stdio.h>

int main(){

    no *head; // Cria a lista
    head = NULL; // Ainda não aponta pra ninguém pois está vazia

    insert_start(&head);
    insert_start(&head);

    show_list(head);

    return 0;
}
