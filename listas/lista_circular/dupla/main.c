#include "circ_double_linked_list.h"

/*
    Aqui na lista circular com encadeamento único, precisamos ter atenção para alguns detalhes, primeiramente é necessário
    compreender que não utilizamos a nomenclatura "head" para inicializar e utilizar nas funções da lista, isso é devido
    ao fato de que o ponteiro agora não aponta mais para a "cabeça" (início) da lista, e sim para a "cauda" (final) da
    lista, por esse motivo usaremos o nome "tail". O motivo de apontarmos para o final da lista tem como razão o fato de 
    que para inserir no final novos nós no começo e final da lista não é necessário percorrê-la para chegar ao último
    elemento para ligá-lo ao novo nó, o que seria necessário com o ponteiro inicial apontado para o começo da lista, de
    forma que para obter o primeiro elemento, seja na hora da inserção, remoção ou na exibição dos elementos, basta
    utilizar tail->next, que nesse caso como se trata de uma lista circular, refere-se ao primeiro elemento da lista,
    dado que o último elemento aponta para o primeiro e o primeiro aponta para o último.
    Obs: O único momento que é necessário percorrer a lista é na exibição da lista.
*/

// LISTA CIRCULAR ( com encadeamento único )
int main(){

    no *tail;
    tail = NULL; // Começa vazia

    insert_end(&tail);

    remove_end(&tail);

    show_list(tail);

    return 0;
}
