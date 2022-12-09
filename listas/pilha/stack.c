#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int push(no **head){ // INSERE O ELEMENTO NO TOPO DA PILHA
    // Cria o nó a ser inserido
    no *new_one;
    new_one = (no*)malloc(sizeof(no));
    new_one->next = NULL;
    scanf("%d", &new_one->data);

    if(*head == NULL){ // Checa se está vazia
        *head = new_one; // Primeiro nó inserido
        return 1;
    }
    
    new_one->next = *head; // Faz o novo nó apontar para o primeiro nó da pilha
    *head = new_one; // Insere no topo da pilha

    return 1;
}

int pop(no **head){ // REMOVE O ELEMENTO NO TOPO DA PILHA
    if(*head == NULL){
        printf("A pilha esta vazia.\n");
        return 0;
    }

    no *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);

    return 1;
}

int peek(no **head){; // MOSTRA O ELEMENTO NO TOPO DA PILHA
    if(*head == NULL){
        printf("A pilha esta vazia.\n");
        return 0;
    }
    
    printf("%d\n", (*head)->data);
}

int get_top(no **head){// RETORNA O ELEMENTO NO TOPO DA PILHA
    if(*head == NULL){
        printf("A pilha esta vazia.\n");
        return 0;
    }

    return (*head)->data;
}

// int show_stack(no **head){ // MOSTRA OS ELEMENTOS DA PILHA
//     if(*head == NULL){
//         printf("A pilha esta vazia.\n");
//         return 0;
//     }

//     printf("\nElementos da pilha:\n");
//     while(*head != NULL){ // Mostra o elemento do topo, após isso ele é removido da pilha. Faz isso até esvaziar
//         peek(head);
//         pop(head);
//     }

//     return 1;
// }

int show_stack(no **head){ // MOSTRA OS ELEMENTOS DA PILHA DE FORMA RECURSIVA
    if(*head == NULL)
        return 1;
    
    printf("%d\n", (*head)->data);
    show_stack(&((*head)->next));
}

int isEmpty(no **head){ // RETORNA SE A PILHA ESTÁ VAZIA OU NÃO
    if(*head == NULL)
        return 1;
    
    return 0;
}

// int clear_stack(no **head){ // ESVAZIA A PILHA
//     while(*head != NULL)
//         pop(head);
    
//     return 1;
// }

int clear_stack(no **head){ // ESVAZIA A PILHA DE FORMA RECURSIVA
    if(*head == NULL)
        return 1;

    clear_stack(&((*head)->next));
    free(*head);
    *head = NULL;
}
