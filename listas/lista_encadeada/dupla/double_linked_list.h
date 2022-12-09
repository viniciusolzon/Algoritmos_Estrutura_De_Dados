#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

// STRUCT DA LISTA DUPLA ( Lista com encadeamento duplo )
typedef struct no{
    struct no *prev;
    int data;
    struct no *next;
}no;

// FUNCOES PARA INSERIR
int insert_start(no **head); // INSERE NÓ COMECO
// int insert_sorted(no **head); // falta essa INSERE O VALOR (X) DE FORMA ORDENADA
int insert_end(no **head); // INSERE NÓ FINAL 

// FUNCOES PARA REMOVER
int remove_start(no **head); // REMOVE O PRIMEIRO NÓ
int remove_end(no **head); // REMOVE O ULTIMO NÓ

// FUNCOES PARA EXIBIR E LIMPAR A LISTA
void show_list(no *aux); // MOSTRA TODOS OS ELEMENTOS DA LISTA DE FORMA RECURSIVA
int clear_list(no **head); // ESVAZIA A LISTA DE FORMA RECURSIVA

#endif
