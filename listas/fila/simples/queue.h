#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// STRUCT DA FILA SIMPLES ( Implementada com lista simples )
typedef struct fila{
    struct no *head;
    struct no *tail;
}fila;

// STRUCT DO NÓ
typedef struct no{
    int data;
    struct no *next;
}no;

int enqueue(fila **queue); // INSERE O ELEMENTO NO FINAL DA FILA
int dequeue(fila **queue); // REMOVE O ELEMENTO NO INICIO DA FILA
int front(fila *queue); // RETORNA O ELEMENTO NO INICIO DA FILA
int rear(fila *queue); // RETORNA O ELEMENTO NO FINAL DA FILA

int show_queue(fila **queue); // MOSTRA TODOS OS ELEMENTOS DA FILA
int clear_queue(fila **queue); // ESVAZIA A FILA
int isEmpty(fila *queue); // VERIFICA SE A FILA ESTÁ VAZIA

#endif
