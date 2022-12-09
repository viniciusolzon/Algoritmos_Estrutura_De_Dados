#include "circ_linked_list.h"

int insert_start(no **tail){
    // Cria nó a ser inserido
    no *new_one;
    new_one = (no *)malloc(sizeof(no));
    if(!new_one){
        printf("Erro ao alocar memoria!\n\n");
        return 0;
    }
    new_one->next = 0;
    scanf("%d", &new_one->data);
    // Insere na lista
    if(!*tail){// Se estiver vazia
        *tail = new_one;
        new_one->next = new_one;
        return 1;
    }
    // Se não estiver vazia
    new_one->next = (*tail)->next; // Nó a ser inserido aponta pra o último, primeiro aponta para o último de forma circular. 
    (*tail)->next = new_one;

    return 1;
}

int insert_end(no **tail){
    // Cria nó a ser inserido
    no *new_one;
    new_one = (no *)malloc(sizeof(no));
    if(!new_one){
        printf("Erro ao alocar memoria!\n\n");
        return 0;
    }
    new_one->next = 0;
    scanf("%d", &new_one->data);
    // Insere na lista
    if(!*tail){// Se estiver vazia
        *tail = new_one;
        new_one->next = new_one;
        return 1;
    }
    // Se não estiver vazia
    new_one->next = (*tail)->next;
    (*tail)->next = new_one;
    *tail = new_one;

    return 1;
}

int remove_start(no **tail){
    // Checa se está vazia
    if(!*tail){
        printf("A lista esta vazia.\n");
        return 0;
    }
    // Checa se tem só um elemento
    if((*tail)->next == *tail){
        free(*tail);
        *tail = NULL;
        return 1;
    }
    no *temp;
    temp = (*tail)->next; // Nó inicial
    (*tail)->next = temp->next; // Último nó passa a pontar para o próximo do primeiro

    free(temp); // Deleta o primeiro nó

    return 1;
}

int remove_end(no **tail){
    // Checa se está vazia
    if(!*tail){
        printf("A lista esta vazia.\n");
        return 0;
    }
    // Checa se tem só um elemento
    if((*tail)->next == *tail){
        free(*tail);
        *tail = NULL;
        return 1;
    }
    no *temp;
    temp = (*tail)->next; // Nó inicial
    while(temp->next != *tail){ // Vai até o pénúltimo elemento
        temp = temp->next;
    }
    temp->next = (*tail)->next; // Faz o penúltimo elemento apontar para o primeiro, fechando o ciclo
    
    free(*tail); // Deleta o último nó
    
    *tail = temp; // Atualiza a "ponta" da lista

    return 1;
}

void show_list(no *tail){ // Aqui a ponta da lista é passada com cópia e não como referência pois não precisamos alterar o seu conteúdo, apenas mostrar
    // Checa se não está vazia
    if(!tail){
        printf("A lista esta vazia.\n");
        return;
    }
    if(!tail->next){ // Se tiver só um elemento
        printf("Eis a sua lista:\n");
        printf("%d\n", tail->next->data);
        return;
    }

    no *p;
    printf("Eis a sua lista:\n");
    for(p = tail->next; p != tail; p = p->next) // Printa do ultimo(tail) até chegar nele de novo
        printf("%d -> ", p->data);
    printf("%d\n\n", p->data);

}

int clear_list(no **tail){
    // Checa se está vazia
    if(!tail){
        printf("A lista esta vazia.\n");
        return 0;
    }
    no *temp;
    temp = (*tail);
    while(*tail != (*tail)->next)
        remove_end(tail);
    
    free(*tail); // Libera o último nó existente na lista
    *tail = NULL; // O faz apontar para 0/NULL

    return 1;
}
