#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int enqueue_front(fila **queue){ // INSERE O ELEMENTO NA PONTA DA ESQUERDA DA FILA
    // Cria o nó a ser inserido
    no *novo;
    novo = (no*)(malloc(sizeof(no)));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    // Preenche o nó a ser inserido
    scanf("%d", &novo->data);
    novo->prev = NULL;
    novo->next = NULL;

    if((*queue)->tail == NULL){ // Se a fila estiver vazia
        (*queue)->tail = novo; // Ponteiro para a ponta é atualizado com o novo elemento
        (*queue)->head = novo; // Ponteiro para o começo é atualizado com o novo elemento
        return 1;
    }

    novo->next = (*queue)->head; // Faz o novo nó apontar para o "primeiro" nó da lista
    (*queue)->head->prev = novo; // Faz o ponteiro de trás do "primeiro" nó da lista apontar para o novo nó

    return 1;
}

int enqueue_rear(fila **queue){ // INSERE O ELEMENTO NA PONTA DA DIREITA DA FILA
    // Cria o nó a ser inserido
    no *novo;
    novo = (no*)(malloc(sizeof(no)));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    // Preenche o nó a ser inserido
    scanf("%d", &novo->data);
    novo->prev = NULL;
    novo->next = NULL;

    if((*queue)->tail == NULL){ // Se a fila estiver vazia
        (*queue)->tail = novo; // Ponteiro para a ponta é atualizado com o novo elemento
        (*queue)->head = novo; // Ponteiro para o começo é atualizado com o novo elemento
        return 1;
    }

    novo->prev = (*queue)->tail;
    (*queue)->tail->next = novo; // Insere o novo nó no final da lista
    (*queue)->tail = novo; // Atualiza o ponteiro que aponta para o final da lista

    return 1;
}

int dequeue_front(fila **queue){ // REMOVE O ELEMENTO NA PONTA DA ESQUERDA DA FILA
    // Verifica se a lista já não está vazia
    if((*queue)->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    // Cria um nó temporário para guardar o primeiro nó da lista
    no *temp;
    temp = (*queue)->head;

    // Faz o ponteiro prox do "primeiro" nó apontar para o seu sucessor, se for NULL quer dizer que ele era o único
    // Logo, precisamos alterar o ponteiro que marca o "final" da lista também
    (*queue)->head = (*queue)->head->next;
    if((*queue)->head == NULL){
        (*queue)->tail = NULL;
        return 1;
    }
    
    // Se não era o único elemento arruma o ponteiro de trás desse nó para ele não apontar para lixo de memória
    // após deletarmos o nó em questão
    (*queue)->head->prev = NULL;
    // Libera o nó
    free(temp);

    return 1;
}

int dequeue_rear(fila **queue){ // REMOVE O ELEMENTO NA PONTA DA DIREITA DA FILA
    // Verifica se a lista já não está vazia
    if((*queue)->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    // Cria um nó temporário para guardar o último nó da lista
    no *temp;
    temp = (*queue)->tail;

    // Faz o ponteiro prox do "primeiro" nó apontar para o seu antecessor, se for NULL quer dizer que ele era o único
    // Logo, precisamos alterar o ponteiro que marca o "início" da lista também
    (*queue)->tail = (*queue)->tail->prev;
    if((*queue)->tail == NULL){
        (*queue)->head = NULL;
        return 1;
    }
    
    // Se não era o único elemento arruma o ponteiro da frente desse nó para ele não apontar para lixo de memória
    // após deletarmos o nó em questão
    (*queue)->tail->next = NULL;
    // Libera o nó
    free(temp);

    return 1;
}

int front(fila *queue){ // RETORNA O ELEMENTO NO "INICIO" DA FILA
    // Verifica se a lista não está vazia
    if(queue->head == NULL){
        printf("A fila esta vazia.\n");
        return 0;
    }

    return queue->head->data; // Retorna a informação do primeiro nó da lista
}

int rear(fila *queue){ // RETORNA O ELEMENTO NO "FINAL" DA FILA
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
        dequeue_front(queue); // Retira o primeiro elemento
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
        dequeue_front(queue); // Retira o primeiro elemento
    
    return 1;
}

int isEmpty(fila *queue){ // VERIFICA SE A FILA ESTÁ VAZIA
    // Retorna se a lista está vazia ou não
    return queue->head == NULL;
}
