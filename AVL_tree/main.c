#include "avl_tree.h"
#include <stdio.h>

int main(){

    tree *root;
    root = NULL;

    int num;
    
    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento
    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    scanf("%d", &num);
    root = insert_tree(root, num);
    // root = balance(root); // A cada inserção/remoção é feito o balanceamento

    show_prefix(root);
    printf("\n");

    show_infix(root);
    printf("\n");

    show_posfix(root);
    printf("\n");

    // root = clear_tree(root);
    
    // show_infix(root);


    return 0;
}
