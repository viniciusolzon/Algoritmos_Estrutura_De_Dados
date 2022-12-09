#include "list_het.h"
#include <stdio.h>

int main(){

    node *head;
    head = NULL;

    add_node(&head);
    add_node(&head);
    add_node(&head);
    add_node(&head);

    rmv_node(&head);

    show_nodes(&head);


    return 0;
}
