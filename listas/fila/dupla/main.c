#include "queue.h"
#include <stdio.h>

/*
    FILA -> TIPO DE LISTA COM RESTRIÇÃO DE ACESSO AO INICIO E FINAL.
    FIFO -> Fifo In First Out.
*/

int main(){
    /*
        Inicializa a fila com os ponteiros que apontam para a "cabeça" e "cauda" da fila com o valor de NULL,
        ou seja, ainda não apontam pra nada. 
    */
    fila *queue;
    queue->head = NULL;
    queue->tail = NULL;

    enqueue_rear(&queue);
    enqueue_rear(&queue);
    enqueue_rear(&queue);
    enqueue_rear(&queue);

    printf("Queue Front : %d \n", front(queue));
    printf("Queue Rear : %d\n", rear(queue));

    show_queue(&queue);


    return 0;
}
