#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

tree *insert_tree(tree *root, int info){ // Insere um elemento de forma ordenada na árvore
    if(root == NULL){ // Verifica se chegou na folha para inserir o novo elemento
        //Cria e preenche a nova sub-árvore
        tree *new_root;
        new_root = (tree *)malloc(sizeof(tree));
        if(!new_root){
            printf("Erro ao alocar memoria\n");
            return NULL;
        }
        new_root->info = info;
        new_root->left = NULL;
        new_root->right = NULL;

        // O balanceamento é efetuado se necessário
        // root = balance(root);
        
        return new_root;
    }
    else{ // Buscando a folha correta para a inserção
        // Se o valor for menor ou igual que a raíz da sub-árvore, a busca continua na sub-árvore à esquerda
        if(info <= root->info)
            root->left = insert_tree(root->left, info);
        // Se o valor for maior que a raíz da sub-árvore, a busca continua na sub-árvore à direita
        else
            root->right = insert_tree(root->right, info);

        return root;
    }
}

tree *binary_search(tree *root, int info){ // Procura um elemento na árvore
    // Verifica se a árvore está vazia
    if(root == NULL){
    }
    // Se o valor for encontrado, a função retorna
    if(root->info == info){
        return root;
    }
    // Se o valor for menor ou igual que a raíz da sub-árvore, a procura continua na sub-árvore à esquerda
    else if(info <= root->info)
        return binary_search(root->left, info);
    // Se o valor for maior que a raíz da sub-árvore, a procura continua na sub-árvore à direita
    else
        return binary_search(root->right, info);
}


tree *balance(tree *root){ // Balanceia a árvore -> usa balanceamentro simples ou duplo aonde for necessário
    // Se o fator de balanceamento é igual a 2
    if(height(root->left) - height(root->right) == 2){
        if(height(root->left->left) - height(root->left->right) == -1)
            root->left = rotateLeft(root->left);
        root = rotateRight(root);
    }
    else if(height(root->left)  - height(root->right) == -2){
            if(height(root->right->left) - height(root->right->right) == 1)
                root->right = rotateRight(root->right);
            root = rotateLeft(root);
    }

    return root;
}

tree *rotateLeft(tree *root){ // Rotaciona à esquerda
    // Cria uma sub-árvore auxiliar para fazer a rotação
    tree *aux;
    
    aux = root->right;
    root->right = aux->left;
    aux->left = root;
    root = aux;

    return root;
}

tree *rotateRight(tree *root){ // Rotaciona à esquerda
    // Cria uma sub-árvore auxiliar para fazer a rotação
    tree *aux;

    aux = root->left;
    root->left = aux->right;
    aux->right = root;
    root = aux;

    return root;
}

int height(tree *root){ // Retorna a altura da árvore 
    // Verifica se a árvore está vazia
    if(root == NULL){
        return 0;
    }

    if(height(root->left) > height(root->right))
        return height(root->left) + 1;
    else
        return height(root->right) + 1;

}

int nodes_count(tree *root){ // Retorna a quantia de nós na árvore
    // Verifica se a árvore está vazia
    if(root == NULL){
        return 0;
    }

    return nodes_count(root->left) + nodes_count(root->right) + 1;
}

void show_prefix(tree *root){ // Exibe a árvore de forma préfixada
    // Verifica se a árvore está vazia
    if(root == NULL){
        return ;
    }

    printf("%d ", root->info);
    show_prefix(root->left);
    show_prefix(root->right);
}

void show_infix(tree *root){ // Exibe a árvore de forma infixada -> mostra em ordem crescente (dados do menor para o maior)
    // Verifica se a árvore está vazia
    if(root == NULL){
        return;
    }

    show_infix(root->left);
    printf("%d ", root->info);
    show_infix(root->right);
}

void show_posfix(tree *root){ // Exibe a árvore de forma pósfixada
    // Verifica se a árvore está vazia
    if(root == NULL){
        return ;
    }

    show_posfix(root->left);
    show_posfix(root->right);
    printf("%d ", root->info);
}

tree *clear_tree(tree *root){ // Libera todos os elementos da árvore
    // Verifica se a árvore está vazia
    if(root == NULL){
        return NULL;
    }

    // Vai até as extremidades da árvore e volta liberando as sub-árvores
    clear_tree(root->left);
    clear_tree(root->right);
    free(root);
    root = NULL; // Aterra o ponteiro para ele não apontar para lixo de memória ao liberar as sub-árvores
    return root;
}
