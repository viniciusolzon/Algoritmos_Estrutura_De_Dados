#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

int insert_start(no **head){
    // cria o novo nó a ser inserido
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria!\n\n");
        return 0;
    }
    scanf("%d", &novo->data);
    novo->prev = 0;
    novo->next = 0;

    // se a lista estiver vazia, insere no começo logo pois é o primeiro elemento:
    if(!*head){
        *head = novo;
        novo->prev = *head;
        return 1;
    }
    // se não estiver vazia:
    else{
        novo->prev = *head;
        novo->next = *head;
        (*head)->prev = novo;
        *head = novo;
    }
}

int insert_end(no **head){
    // cria o nó a ser inserido
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria!\n\n");
        return 0;
    }
    scanf("%d", &novo->data);
    novo->prev = 0;
    novo->next = 0;   

    // se a lista estiver vazia, insere no começo logo pois é o primeiro elemento:
    if(!*head){
        *head = novo;
        novo->prev = *head;
        return 1;
    }
    // se não estiver vazia:
    else{
        no *aux;
        for(aux = *head; aux->next;/* Mesma coisa que (aux->next != 0) */aux = aux->next); // vai até o último elemento da lista pra inserir no final
        aux->next = novo;
        novo->prev = aux;
        
        return 1;
    }
}

int remove_start(no **head){
    // se a lista estiver vazia, a função já retorna
    if(*head){
        no *aux;
        aux = *head;
        *head = (*head)->next;
        if(aux->next) // se tiver só um nó na lista ele será removido e o ponteiro inicial da lista apontará pra zero, ou seja, não tem como fazer esse o zero->prev = 0;, por isso há o uso desse if, para fazer tal verificação 
            (*head)->prev = NULL;
        free(aux);
    }

    return 1;
}

int remove_end(no **head){
    // Checa se está vazia
    if(*head){
        no *aux;
        no *aux2;
        for(aux = *head; aux->next; aux = aux->next); // vai até o último nó da lista
        if(!(*head)->next){ // se tiver só um nó na lista:
            free((*head)->next);
            *head = NULL;
        }
        else{ // se tiver mais de um nó na lista
            aux2 = aux->prev; // salva o penúltimo
            aux2->next = NULL;
            free(aux);
        }
    }

    return 1;
}

// void show_list(no *head){
//     // observe que não passamos como referência a lista, e sim como cópia, pq não é preciso alterar nada, apenas mostrar elementos
//     // verifica se a lista está vazia
//     if(head){
//         printf("\nEis a sua lista:\n\n");
//         for(; head->next!=0; head = head->next)
//             printf("%d -> ", head->data);
//         printf("%d\n\n", head->data);
//     }
//     else{
//         printf("A lista esta vazia.\n\n");
//         return;
//     }
// }

void show_list(no *head){
    if(head== NULL) // lista não está vazia
        return;

        printf("%d\n", head->data);
        show_list(head->next);
}

// int clear_list(no **head){
//     no *temp;

//     temp = *head;
//     while(temp != 0){
//         temp = temp->next;
//         free(*head);
//         *head = temp;
//     }

//     if(*head == NULL){
//         printf("\nLista esvaziada com sucesso.\n");
//         return 1;
//     }
//     else{
//         printf("\nProblema ao esvaziar a lista.\n");
//         return 0;
//     }
// }

int clear_list(no **head){
    if(*head == NULL) // Se não estiver vazia
        return 1;

    clear_list(&((*head)->next));
    // Faz tudo abaixo assim que a condição de parada é atingida
    free(*head); // Libera o nó
    *head = NULL; // Aterra pra não ficar com lixo de memória    
}
