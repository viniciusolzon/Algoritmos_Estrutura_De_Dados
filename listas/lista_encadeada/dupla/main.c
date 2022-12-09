#include "double_linked_list.h"
#include <stdio.h>

int main(){

    no *head; // Cria a lista
    head = NULL; // Ainda não aponta pra ninguém pois está vazia

    insert_end(&head);
    insert_end(&head);
    insert_end(&head);

    printf("\n");
    printf("%d\n", head->data);
    printf("%d\n", head->next->data);
    printf("%d\n", head->next->next->data);
    no *last;
    last = head->next->next;
    printf("\n");
    printf("%d\n", last->data);
    printf("%d\n", last->prev->data);
    printf("%d\n", last->prev->prev->data);
    printf("\n");

    show_list(head);

    clear_list(&head);
    show_list(head);

    return 0;
}
