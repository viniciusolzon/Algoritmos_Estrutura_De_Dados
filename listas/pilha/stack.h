#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// STRUCT DA PILHA ( Implementada com lista simples )
typedef struct no{
    int data;
    struct no *next;
}no;

int push(no **head); // INSERE O ELEMENTO NO TOPO DA PILHA
int pop(no **head); // REMOVE O ELEMENTO NO TOPO DA PILHA
int peek(no **head); // MOSTRA O ELEMENTO NO TOPO DA PILHA
int get_top(no **head); // RETORNA O ELEMENTO NO TOPO DA PILHA
int show_stack(no **head); // MOSTRA TODOS OS ELEMENTOS DA PILHA DE FORMA RECURSIVA
int isEmpty(no **head); // VERIFICA SE A PILHA ESTÁ VAZIA
int clear_stack(no **head); // ESVAZIA A PILHA DE FORMA RECURSIVA

#endif
