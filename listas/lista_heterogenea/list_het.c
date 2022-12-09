#include "list_het.h"
#include <stdio.h>
#include <stdlib.h>

int add_node(node **head){
    // Cria o novo nó e o preenche
    node *novo;
    novo = (node *)malloc(sizeof(node));
    if(!novo){
        printf("Erro ao alocar memoria.\n");
        return 0;
    }
    novo->next = NULL;
    // Informa o tipo do dado que será anexado ao nó
    printf("Informe o tipo do dado que será anexado nesse novo nó:\n");
    printf("(1) para int\n(2) para char\n(3) para float\n-> ");
    scanf("%d", &novo->id);
    // Cria o tipo do dado informado
    switch(novo->id){
    case 1:
        novo->data = malloc(sizeof(int));
        if(!novo->data){
            printf("Erro ao alocar memoria\n.");
            return 0;
        }
        int i;
        scanf("%d", &i);
        *(int*)novo->data = i;

        break;
    case 2:
        novo->data = malloc(sizeof(char));
        if(!novo->data){
            printf("Erro ao alocar memoria\n.");
            return 0;
        }
        getchar(); // captura a quebra de linha
        char c;
        c = getchar();
        *(char*)novo->data = c;

        break;
    case 3:
        novo->data = malloc(sizeof(float));
        if(!novo->data){
            printf("Erro ao alocar memoria\n.");
            return 0;
        }
        float f;
        f = scanf("%f", &f);
        *(float*)novo->data = f;

        break;
    default:
        printf("Valor invalido\n");
    }

    // Se a lista estiver vazia
    if(*head == NULL){
        *head = novo; // Coloca o primeiro nó
        return 1;
    }
    node *aux;
    aux = *head;
    for(; aux->next != NULL; aux = aux->next); // Percorre até o último elemento da lista
    aux->next = novo; // Coloca o novo nó no final da lista

    return 1;
}

int rmv_node(node **head){
    if(*head == NULL){
        printf("A lista ja esta vazia\n");
        return 0;
    }
    if((*head)->next == NULL){ // Se tiver só um elemento
        node *temp;
        temp = *head;
        *head = NULL;
        free(temp);
        
        return 1;
    }
    node *aux;
    aux = *head;
    while(aux->next->next != NULL) // Percorre até o penúltimo elemento
        aux = aux->next;
    node *temp;
    temp = aux->next; // Salva o último nó
    
    node *temp2;
    temp2 = aux->next->data;
    aux->next->data = NULL;
    free(temp2);

    aux->next = NULL;
    free(temp);

    return 1;
}

// FALTA ARRUMAR O FLOAT, TA BUGADO

int show_nodes(node **head){
	node* aux;
    aux = *head;
	for(; aux != NULL; aux = aux->next){
	    switch(aux->id) {
            case 1:
		 		printf ("%d ", *(int*)aux->data);
				break;
			case 2:
				printf ("%c ", *(char*)aux->data);
				break;
			case 3:
				printf ("%f ", *((float*)aux->data));
				break;
           }
    }
    printf("\n");

    return 1;
}
