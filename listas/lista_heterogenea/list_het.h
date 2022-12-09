#ifndef LIST_HET_H
#define LIST_HET_H

// Lista Heterogênea ( Implementada com lista de encadeamento único )
/*
A lista terá um identificador que serve para identificar o tipo do dado que está anexado/pendurado no atual nó que 
estamos analisando, isso ocorre pois como não sabemos qual o tipo do dado que será anexado no nó em questão, é necessário
o uso de um ponteiro pra void (void *ptr), haja vista que ele é enxergado como ponteiro genérico, e como não temos como
acessar o contéudo apontado pelo ponteiro de void (justamente pq não sabemos para o que ele aponta) precisamos que um
identificador que nos diga qual o tipo de dado com o qual estamos trabalhando, para então acessá-lo com corretamente.
*/

// STRUCT DA LISTA HETEROGÊNEA (Encadeamento único)
typedef struct node{
    int id;
    /* Ponteiro de void -> é um ponteiro genérico, vamos usar ele pq não sabemos para o que ele irá apontar, 
    dessa forma nós mantemos a integridade do código.  */
    void *data;
    struct node *next;
}node;

/* Para inserir e remover nós */
int add_node(node **head);
int rmv_node(node **head);

/* Para exibir a lista */
int show_nodes(node **head);

#endif
