#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int insert_start(no **head){
    // cria nó
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    novo->next = NULL;
    scanf("%d",&novo->data);

    // no *temp;
    // temp = *head;

    // preenche nó
    novo->next = *head;

    // insere nó
    *head = novo;

    return 1;
}

int remove_start(no **head){
    no *aux;
    aux = *head; // nó auxiliar ganha o primeiro nó da lista

    if(aux){ // se ela não estiver vazia, pq se estiver a função já retorna
        *head = (*head)->next; // faz o conteúdo de head apontar para o próximo do conteúdo de head, ou seja, faz o ponteiro inicial apontar pro segundo nó, mesmo que esse esteja aterrado
        // *head = aux->next;// faz a mesma coisa da linha de cima
        free(aux);
    }

    return 1;
}

int insert_sorted(no **head){
    /* cria novo elemento*/
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria\n");
        return 0;
    }
    scanf("%d", &novo->data);

    /* procura posição para inserir */
    no *anterior, *p;
    anterior = NULL;
    p = *head;
    while(p != NULL && p->data < novo->data){
        anterior = p;
        p = p->next;
    }
    /* encadeia elemento */
    if(anterior == NULL){ // insere elemento no início
        novo->next = *head;
        *head = novo;
    }
    else{ // insere elemento no meio
        novo->next = anterior->next;
        anterior->next = novo;
    }
    return 1;
}


int insert_end(no **head){
    // cria nó
    no *novo;
    novo = (no*)malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria\n");
        return 0;
    }

    // preenche nó
    novo->next = 0; // aterrando o proximo nó
    scanf("%d", &novo->data);

    //se a lista estiver vazia: insere logo no primeiro
    if(!*head){
        *head = novo;
        return 1;
    }
    else{ // senão:

        // insere nó
        no *aux;
        for(aux = *head; aux->next != 0; aux = aux->next); // vai pro último elemento da lista pra ligar ele com o novo nó
        aux->next = novo;

        return 1;
    }
}

int remove_end(no **head){
    // Checa se está vazia
    if(!*head){
        printf("A lista esta vazia.\n");
        return 0;
    }
    if((*head)->next == NULL){ // Se tiver só um elemento
        free(*head);
        *head = NULL;
        return 1;
    }
    no *temp;
    temp = *head;
    while(temp->next->next != NULL) // Percorre até o penúltimo elemento
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;

    return 1;
}

// void show_list(no *head){
//     if(head){ // lista não está vazia
//         printf("Eis a sua lista!\n\n");
//         for(; head->next!=0; head = head->next)
//             printf("%d -> ", head->data);
//         printf("%d\n\n", head->data);
//     }
//     else
//         printf("A lista esta vazia\n\n");
// }

void show_list(no *head){
    if(head== NULL) // lista não está vazia
        return;

    printf("%d\n", head->data);
    show_list(head->next);
}

int list_compare(no **head1, no **head2){
    no *p1, *p2;

    for(p1=*head1, p2=*head2; p1!=NULL && p2!=NULL; p1 = p1->next, p2 = p2->next){
        if(p1->data != p2->data)
            return 0;
    }
    return p1 == p2; // ou return 0;
}

// int clear_list(no **head){
//     while(*head != NULL)
//         remove_start(head);

//     return 1;
// }

int clear_list(no **head){
    if(*head == NULL) // Se não estiver vazia
        return 0;

    clear_list(&((*head)->next));
    free(*head); // Libera o nó
    *head = NULL; // Aterra pra não ficar com lixo de memória    
}
