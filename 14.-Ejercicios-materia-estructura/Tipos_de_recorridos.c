//
//  main.c
//  DEDA_U3_A3_SACS
//
//  Created by saul corona on 13/03/22.
//

#include <stdio.h>
#include <stdlib.h>

//16, 11, 5, 2, 7, 13, 12, 15, 21, 18, 16, 20, 28, 25, 30

// estructura para crear el nodo
struct node {
    int data;
    struct node *derecha;
    struct node *izquierda;
};

typedef struct bin_tree node;

// Prototipos
struct node *CrearArbol(struct node *, int);
void inOrder(struct node *);
void preOrder(struct node *);
void posOrder(struct node *);


// estructura para crear nodos del arbol
struct node *CrearArbol(struct node *root, int item){
    if (root == NULL){
        root = (struct node *)malloc(sizeof(struct node));
        root -> izquierda = root -> derecha = NULL;
        root -> data = item;
        return  root;
    }
    else {
        if(item < root -> data)
            root -> izquierda = CrearArbol(root -> izquierda, item);
        else if (item > root ->data)
            root -> derecha = CrearArbol(root -> derecha, item);
        else
            printf("\nHay un elemento duplicado\n");
        return (root);
    }
}

// Metodo inOrder
void inOrder(struct node *root){
    if (root != NULL){
        inOrder(root -> izquierda);
        printf("%d ", root -> data);
        inOrder(root -> derecha);
    }
}

// Metodo preOrder
void preOrder(struct node *root){
    if(root != NULL){
        printf("%d ", root -> data);
        preOrder(root -> izquierda);
        preOrder(root -> derecha);
    }
}

// Metodo posOrder
void posOrder(struct node *root){
    if(root != NULL){
        posOrder(root -> izquierda);
        posOrder(root -> derecha);
        printf("%d ", root -> data);
    }
}

// Métodos para buscar un elemento del arbol
struct node* search(struct node *root, int numero){
    if(root==NULL || root->data == numero)
        return root;
    else if(numero > root->data)
        return search(root-> izquierda, numero);
        else //
            return search(root-> derecha, numero);
}





int main(){
    struct node *root = NULL;
    struct node *p;
    int option, item, n, i, numero;
    
    do {
        printf("\nArbol de busqueda binaria\n");
        printf("\n1.Crear arbol\n");
        printf("\n2.Recorrido In Orden\n");
        printf("\n3.Recorrido Pre Orden\n");
        printf("\n4.Recorrido Pos Orden\n");
        printf("\n5.Buscar\n");
        printf("\n0.Salir\n");
        printf("\nIngresa opcion\n");
        scanf("%d", &option);
        
        switch(option){
            case 1:
                root = NULL;
                printf("\n\n Agraga la cantidad de nodos que se necesitan: ");
                scanf("%d", &n);
                for (i = 1; i <= n; i++) {
                    printf("Ingresa el valor para el nodo %d \t", i);
                    scanf("%d", &item);
                    root = CrearArbol(root, item);
                }
                printf("\El arbol se creo");
                break;
            case 2:
                printf("\nBusqueda In Orden \n");
                inOrder(root);
                break;
            case 3:
                printf("\nBusqueda Pre Orden \n");
                preOrder(root);
                break;
            case 4:
                printf("\nBusqueda Pos Orden \n");
                posOrder(root);
                break;
            case 5:
                printf("\nIngresa el elemento a buscar:\n");
                scanf("%d", &numero);
                p = search(root, numero);
                if(p){
                    printf("\nSe encontro en: %p\n", p);
                } else
                    printf("\nNo se encuentra el elemento\n");
                break;
            case 0:
                printf("\nsalir\n");
                break;
            default:
                printf("Opcion invalida");
                break;
        }
    }while(option != 0);
    return 0;
}
