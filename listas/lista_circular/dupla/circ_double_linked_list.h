#ifndef CIRC_DOUBLE_LINKED_LIST_H
#define CIRC_DOUBLE_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

// STRUCT DA LISTA CIRCULAR ( com encadeamento duplo )
typedef struct no{
    struct no *prev;
    int data;
    struct no *next;
}no;

int insert_start(no **tail); // INSERE NÓ COMECO
// int insert_sorted(no **tail); // INSERE DE FORMA ORDENADA
int insert_end(no **tail); // INSERE NÓ FINAL

int remove_start(no **tail); // REMOVE O PRIMEIRO NÓ
int remove_end(no **tail); // REMOVE O ULTIMO NÓ

void show_list(no *tail); // MOSTRA TODOS OS ELEMENTOS DA LISTA
// void show_list_rec(no *tail); // MOSTRA TODOS OS ELEMENTOS DA LISTA DE FORMA RECURSIVA
// int list_compare(no **tail1, no **tail2); // COMPARA SE DUAS LISTA SÃO IGUAIS
int clear_list(no **tail); // funcao extra ESVAZIA A LISTA

#endif