#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int enqueue(fila **queue){ // INSERE O ELEMENTO NO FINAL DA FILA
    // Cria o nó a ser inserido
    no *novo;
    novo = (no*)(malloc(sizeof(no)));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    // Preenche o nó a ser inserido
    scanf("%d", &novo->data);
    novo->next = NULL;

    if((*queue)->tail == NULL){ // Se a fila estiver vazia
        (*queue)->tail = novo; // Ponteiro para a ponta é atualizado com o novo elemento
        (*queue)->head = novo; // Ponteiro para o começo é atualizado com o novo elemento
        return 1;
    }

    (*queue)->tail->next = novo; // Insere o novo nó no final da lista
    (*queue)->tail = novo; // Atualiza o ponteiro que aponta para o final da lista

    return 1;
}

int dequeue(fila **queue){ // REMOVE O ELEMENTO NO FINAL DA FILA
    // Verifica se a lista já não está vazia
    if((*queue)->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    // Cria um nó temporário para guardar o primeiro nó da lista
    no *temp;
    temp = (*queue)->head;
    // Atualiza o ponteiro que aponta para o início da lista (apontando ele para o próximo)
    (*queue)->head = (*queue)->head->next;

    // Se agora o ponteiro para o início da lista é NULL, quer dizer que após a remoção não temos mais nenhum elemento, 
    // deesa forma é preciso autalizar o ponteiro para o final da lista para NULL também
    if((*queue)->head == NULL)
        (*queue)->tail = NULL;
    
    // Libera o nó temporário
    free(temp);

    return 1;
}

int front(fila *queue){ // RETORNA O ELEMENTO NO INICIO DA FILA
    // Verifica se a lista não está vazia
    if(queue->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    return queue->head->data; // Retorna a informação do primeiro nó da lista
}

int rear(fila *queue){ // RETORNA O ELEMENTO NO FINAL DA FILA
    // Verifica se a lista não está vazia
    if(queue->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    return queue->tail->data; // Retorna a informação do último nó da lista
}

int show_queue(fila **queue){ // MOSTRA TODOS OS ELEMENTOS DA FILA
    // Verifica se a lista não está vazia
    if((*queue)->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }
    /* Para mostrar todos os elementos da fila é preciso que sejam respeitadas as suas restrições de acesso.
       Ou seja, só podemos acessar o primeiro e último elemento da lista, em que o "meio" é inacessível.
       Para isso, vamos mostrar o primeiro elemento e após a sua exibição ele será retirado da lista, fazendo isso até
       que a lista esteja vazia
    */
    while((*queue)->head != NULL){ // Enquanto a fila não estiver vazia
        printf("%d\n", front(*queue)); // Printa o primeiro elemento
        dequeue(queue); // Retira o primeiro elemento
    }

    return 1;
}

int clear_queue(fila **queue){ // ESVAZIA A FILA
    // Verifica se a lista não está vazia
    if((*queue)->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    while((*queue)->head != NULL) // Enquanto a fila não estiver vazia
        dequeue(queue); // Retira o primeiro elemento
    
    return 1;
}

int isEmpty(fila *queue){ // VERIFICA SE A FILA ESTÁ VAZIA
    // Retorna se a lista está vazia ou não
    return queue->head == NULL;
}
