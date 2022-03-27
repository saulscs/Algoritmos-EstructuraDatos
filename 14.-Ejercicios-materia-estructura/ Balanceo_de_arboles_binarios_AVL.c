//
//  main.c
//  Balanceo de árboles binarios AVL
//
//  Created by saul corona on 22/03/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef struct nodo {
    int dato;
    int fe;        //factor de equilibrio
    struct nodo *izquierda;
    struct nodo  *derecha;
    
} AVL;

/* Cuenta el número de nodos en el árbol */
int contarNodos(AVL *p) {
    if(p == NULL)
        return(0);
    return(contarNodos(p->izquierda) + 1 + contarNodos(p->derecha));
}

/* Calcula la altura del árbol (factor de equilibrio)*/
int fe(AVL *p){
    if(p == NULL)
        return(-1);
    else
        return(p->fe);
}

/* Rotación simple a la izquierda*/
AVL *rotIzq(AVL *p) {
    AVL *q;
    q = p->izquierda;
    p->izquierda = q->derecha;
    q->derecha = p;
    p->fe = max(fe(p->izquierda), fe(p->derecha)) + 1;
    q->fe = max(fe(q->izquierda), p->fe) + 1;
    return(q); /* Nueva Raíz */
}

/* Rotación simple a la derecha */
AVL *rotDer(AVL *q){
    AVL *p;
    p = q->derecha;
    q->derecha = p->izquierda;
    p->izquierda = q;
    q->fe = max(fe(q->izquierda),fe(q->derecha)) + 1;
    p->fe = max(fe(p->derecha),q->fe) + 1;
    return(p); /* Nueva raíz*/
}

/* Rotación doble a la izquierda*/
AVL *rotDobIzq(AVL *k) {
    k->izquierda = rotDer(k->izquierda);
    return(rotIzq(k));
}

/* Rotación doble a la derecha*/
AVL *rotDobDer(AVL *q) {
    q->derecha = rotIzq(q->derecha);
    return(rotDer(q));
}

/*Insertar nodo*/
AVL *insertar(int dato, AVL *p) {
    if(p == NULL) {
        p = (AVL *)malloc(sizeof(AVL));
        p->dato = dato;
        p->fe = 0;
        p->izquierda = NULL;
        p->derecha = NULL;
    }
    else if(dato < p->dato) {
        p->izquierda = insertar(dato,p->izquierda);
        if(fe(p->izquierda) - fe(p->derecha) == 2)
            if(dato < p->izquierda->dato)
                p = rotIzq(p);
        else
            p = rotDobIzq(p);
    }
    else if(dato > p->dato) {
        p->derecha = insertar(dato,p->derecha);
        if(fe(p->derecha) - fe(p->izquierda) == 2)
            if(dato > p->derecha->dato)
                p = rotDer(p);
        else
            p = rotDobDer(p);
    }
    p->fe = max(fe(p->izquierda),fe(p->derecha)) + 1;
    return(p);
}

/*Devuelve el factor de equilibrio*/
int balancear(AVL *p) {
    if(!p)
        return 0;
    return fe(p->izquierda) - fe(p->derecha);
}


/*Devuelve el nodo con el dato menor del árbol*/
AVL * minValNodo(AVL *p) {
    AVL* current = p;
    while (p->izquierda != NULL)
        current = current->izquierda;
    return current;
}

/*Borra el nodo con el dato dado del árbol*/
AVL *borrarNodo(int key, AVL *p){
    if(!p)
        return p;
    if(key < p->dato)
        p->izquierda = borrarNodo(key, p->izquierda);
    else if(key > p->dato)
        p->derecha = borrarNodo(key, p->derecha);
    else {
        if((!(p->izquierda)) || (!(p->derecha))) {
            AVL *temp = p->izquierda ? p->izquierda : p->derecha;
            if (!temp) {
                temp = p;
                p = NULL;
            } else
                *p = *temp;
            free(temp);
        } else {
            AVL *temp = minValNodo(p->derecha);
            p->dato = temp->dato;
            p->derecha = borrarNodo(temp->dato, p->derecha);
        }
    }
    if(!p)
        return p;
    p->fe = 1 + max(fe(p->izquierda), fe(p->derecha));
    int balance = balancear(p);
    if (balance > 1 && balancear(p->izquierda) >= 0)
        return rotDer(p);
    if (balance > 1 && balancear(p->izquierda) < 0) {
        p->izquierda =  rotIzq(p->izquierda);
        return rotDer(p);
    }
    if (balance < -1 && balancear(p->derecha) <= 0)
        return rotIzq(p);
    if (balance < -1 && balancear(p->derecha) > 0) {
        p->derecha = rotDer(p->derecha);
        return rotIzq(p);
    }
    return p;
}

/* Recorre y muestra todos los nodos*/
void ver(int nivel,AVL *p) {
    int i;
    if(p != NULL) {
        ver(nivel + 1,p->derecha);
        printf("\n\n");
        for(i = 0;i < nivel;i++)
            printf("\t");
        printf("%d",p->dato);
        ver(nivel + 1,p->izquierda);
    }
}


/* Programa principal*/

int main(){
    int n,i,option,dato;
    AVL *p = NULL,*q;
    
    do{
        printf("\n\n\tBalanceo de árboles binarios AVL\n\n");
        printf("\n1.-Llenar un árbol\n");
        printf("\n2.- Contar Nodos y Altura\n");
        printf("\n3.- Borrar nodo\n");
        printf("\n4.- Ver árbol\n");
        printf("\n0.-Salir\n");
        printf("Ingresa una Opción : ");
        scanf("%d",&option);
        
        switch(option){
            case 1:
                printf("Numero de nodos del árbol: ");
                scanf("%d",&n);
                for(i = 0;i < n;i++) {
                    printf("\n\tElemento No. %d: ",i+1);
                    scanf("%d",&dato);
                    p = insertar(dato,p);
                }
                break;
            case 2:
                printf("\n\n\tNodos : %d\n\n\tAltura =%d",contarNodos(p),fe(p));
                break;
            case 3:
                printf("\n\tDato a borrar: ");
                scanf("%d",&dato);
                q = borrarNodo(dato, p);
                if(q)
                    printf("Se borró el dato %d",dato);
                else
                    printf("No se encontró el dato %d",dato);
                break;
            case 4:
                printf("Árbol AVL");
                ver(0,p);
                break;
            case 0:
                printf("\nSalir\n");
                break;
            default:
                printf("Opción no válida");
                break;
        }
    }while(option != 0);
    return 0;
}
