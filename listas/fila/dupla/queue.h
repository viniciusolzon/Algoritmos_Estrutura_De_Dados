#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// STRUCT DA FILA DUPLA (Implementada com lista dupla)
typedef struct fila{
    struct no *head;
    struct no *tail;
}fila;

// STRUCT DO NÓ (Implementada com lista dupla)
typedef struct no{
    struct no *prev;
    int data;
    struct no *next;
}no;

int enqueue_front(fila **queue); // INSERE O ELEMENTO NA PONTA DA ESQUERDA DA FILA
int enqueue_rear(fila **queue); // INSERE O ELEMENTO NA PONTA DA DIREITA DA FILA
int dequeue_front(fila **queue); // REMOVE O ELEMENTO NA PONTA DA ESQUERDA DA FILA
int dequeue_rear(fila **queue); // REMOVE O ELEMENTO NA PONTA DA DIREITA DA FILA
int front(fila *queue); // RETORNA O ELEMENTO NO "INICIO" DA FILA
int rear(fila *queue); // RETORNA O ELEMENTO NO "FINAL" DA FILA

int show_queue(fila **queue); // MOSTRA TODOS OS ELEMENTOS DA FILA
int clear_queue(fila **queue); // ESVAZIA A FILA
int isEmpty(fila *queue); // VERIFICA SE A FILA ESTÁ VAZIA

#endif
