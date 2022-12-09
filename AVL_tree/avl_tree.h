#ifndef avl_tree_H
#define avl_tree_H
/* 
            Árvores
-> Estrutura de dados não linear
-> Estrutura de dados hierárquica
-> Armazenamento e acesso hierárquico
-> Ideia de nós pais e nós filhos
-> Ideia de subconjunto/recursão (subárvores)
-> Árvore é composta por sub-árvores/nós
-> Nó sem nenhum antecessor/pai = Raíz
-> Nó sem nenhuma ramificação/filho = Folha
-> Cada nó (exceto a raíz) tem exatamente um antecessor imediato ou pai
-> Existe apenas um caminho entre a raíz e cada um dos nós da árvore
-> Inserção sempre nas folhas
-> Altura de uma árvore = maior distância (nível) de um nó até a raíz + 1
-> Grau de um vértice/nó = número de sub-árvores o vértice/nó possui
-> Nível de um nó = nível de seu pai + 1
*/

/*
            Árvore de Busca Binária / Árvore Ordenada
-> Cada nó pode ter até no máximo 2 filhos
-> Filho à esquerda menor que a raíz
-> Filho à direita maior que a raíz
-> Lembre de considerar o conceito de sub-árvore
-> Vantagens:
 - Se balanceada, busca é ultra eficiente
-> Dificuldade:
 - Manter o balanceamento
*/

/*
            AVL (Adelson Velsky e Landis)
-> Árvore binária em que a cada alteração é feito o balanceamento da árvore.
-> Árvore balanceada = "Para cada nó, a diferença de altura de suas sub-árvores deve ser no máximo 1".
-> Manter o balanceamento na árvore binária é a parte complicada/difícil da árvore binária AVL, todavia se for mantido
tal balanceamento a busca se torna super eficiente.
-> Fator de balanceamento = (altura da sub-árvore à esquerda) - (altura da sub-árvore à direita)
-> No balanceamento existem rotações à esquerda e à direita
-> O balanceamento, caso seu uso seja necessário, pode ser simples ou duplo (uma ou duas rotações na árvore),
tal balanceamento ocorre no primeiro nó com diferença de sub-árvore maior que 1
*/

// STRUCT DA ÁRVORE DE BUSCA BINÁRIA AVL (Adelson Velsky e Landis)
typedef struct tree{
    struct tree *left; /* Menor */
    int info;
    struct tree *right; /* Maior */
}tree;

tree *insert_tree(tree *root, int info); // Insere um elemento de forma ordenada na árvore
tree *binary_search(tree *root, int info); // Procura um elemento na árvore

tree *balance(tree *root); // Balanceia a árvore -> usa balanceamentro simples ou duplo aonde for necessário
tree *rotateLeft(tree *root); // Rotaciona à esquerda
tree *rotateRight(tree *root); // Rotaciona à esquerda

int height(tree *root); // Retorna a altura da árvore 
int nodes_count(tree *root); // Retorna a quantia de nós na árvore

void show_prefix(tree *root); // Exibe a árvore de forma préfixada
void show_infix(tree *root); // Exibe a árvore de forma infixada -> mostra em ordem crescente (dados do menor para o maior)
void show_posfix(tree *root); // Exibe a árvore de forma pósfixada

tree *clear_tree(tree *root); // Libera todos os elementos da árvore

#endif
