#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))

typedef struct nodo {
    int dato;
    int fe;         //factor de equilibrio
    struct nodo *izq, *der;
    
} AVL;

/* Cuenta el número de nodos en el árbol */
int cuenta_nodos(AVL *p) {
    if(p == NULL)
        return(0);
    return(cuenta_nodos(p->izq) + 1 + cuenta_nodos(p->der));
}

/* Borra todo el árbol AVL*/
void borrar_AVL(AVL *p) {
    if(p != NULL) {
        borrar_AVL(p->izq);
        borrar_AVL(p->der);
        free(p);
    }
}

/* Busca un dato en el árbol*/
AVL *buscar(int dato, AVL *p) {
    if(p == NULL)
        return(NULL);
    if(dato < p->dato)
        return(buscar(dato, p->izq));
    else if(dato > p -> dato)
        return(buscar(dato, p->der));
    else
        return(p);
}

/* Calcula la altura del árbol (factor de equilibrio)*/
int fe(AVL *p){
    if(p == NULL)
        return(-1);
    else
        return(p->fe);
}

/* Rotación simple a la izquierda*/
AVL *rot_izq(AVL *p) {
    AVL *q;
    q = p->izq;
    p->izq = q->der;
    q->der = p;
    p->fe = max(fe(p->izq), fe(p->der)) + 1;
    q->fe = max(fe(q->izq), p->fe) + 1;
    return(q); /* Nueva Raíz */
}

/* Rotación simple a la derecha */
AVL *rot_der(AVL *q){
    AVL *p;
    p = q->der;
    q->der = p->izq;
    p->izq = q;
    q->fe = max(fe(q->izq),fe(q->der)) + 1;
    p->fe = max(fe(p->der),q->fe) + 1;
    return(p); /* Nueva raíz*/
}

/* Rotación doble a la izquierda*/
AVL *rot_dob_izq(AVL *k) {
    k->izq = rot_der(k->izq);
    return(rot_izq(k));
}

/* Rotación doble a la derecha*/
AVL *rot_dob_der(AVL *q) {
    q->der = rot_izq(q->der);
    return(rot_der(q));
}


/* Inserta un dato en el árbol p*/
AVL *insertar(int dato, AVL *p) {
    if(p == NULL) {
        p = (AVL *)malloc(sizeof(AVL));
        p->dato = dato;
        p->fe = 0;
        p->izq = NULL;
        p->der = NULL;
    }
    else if(dato < p->dato) {
        p->izq = insertar(dato,p->izq);
        if(fe(p->izq) - fe(p->der) == 2)
            if(dato < p->izq->dato)
                p = rot_izq(p);
        else
            p = rot_dob_izq(p);
    }
    else if(dato > p->dato) {
        p->der = insertar(dato,p->der);
        if(fe(p->der) - fe(p->izq) == 2)
            if(dato > p->der->dato)
                p = rot_der(p);
        else
            p = rot_dob_der(p);
    }
    p->fe = max(fe(p->izq),fe(p->der)) + 1;
    return(p);
}


/* Recorre y muestra todos los nodos*/
void ver(int nivel,AVL *p) {
    int i;
    if(p != NULL) {
        ver(nivel + 1,p->der);
        printf("\n\n");
        for(i = 0;i < nivel;i++)
            printf("\t");
        printf("%d",p->dato);
        ver(nivel + 1,p->izq);
    }
}

/*Devuelve el factor de equilibrio*/
int getBalance(AVL *p) {
    if(!p)
        return 0;
    return fe(p->izq) - fe(p->der);
}

/*Devuelve el nodo con el dato menor del árbol*/
AVL * minValueNode(AVL *p) {
    AVL* current = p;
    while (p->izq != NULL)
        current = current->izq;
    return current;
}

/*Borra el nodo con el dato dado del árbol*/
AVL *deleteNode(int key, AVL *p){
    if(!p)
        return p;
    if(key < p->dato)
        p->izq = deleteNode(key, p->izq);
    else if(key > p->dato)
        p->der = deleteNode(key, p->der);
    else {
        if((!(p->izq)) || (!(p->der))) {
            AVL *temp = p->izq ? p->izq : p->der;
            if (!temp) {
                temp = p;
                p = NULL;
            } else
                *p = *temp;
            free(temp);
        } else {
            AVL *temp = minValueNode(p->der);
            p->dato = temp->dato;
            p->der = deleteNode(temp->dato, p->der);
        }
    }
    if(!p)
        return p;
    p->fe = 1 + max(fe(p->izq), fe(p->der));
    int balance = getBalance(p);
    if (balance > 1 && getBalance(p->izq) >= 0)
        return rot_der(p);
    if (balance > 1 && getBalance(p->izq) < 0) {
        p->izq =  rot_izq(p->izq);
        return rot_der(p);
    }
    if (balance < -1 && getBalance(p->der) <= 0)
        return rot_izq(p);
    if (balance < -1 && getBalance(p->der) > 0) {
        p->der = rot_der(p->der);
        return rot_izq(p);
    }
    return p;
}

/* Programa principal*/
void main() {
    int n,i,dato,op;
    AVL *p = NULL,*q;
    while(1){
        printf("\n\tOperaciones con Árboles AVL\n\n");
        printf("1. Llenar un árbol de forma aleatoria\n");
        printf("2. Llenar un árbol de forma manual\n");
        printf("3. Buscar un dato\n");
        printf("4. Contar Nodos y Altura\n");
        printf("5. Ver árbol\n");
        printf("6. Borrar nodo\n");
        printf("7. Salir\n");
        printf("Elija una Opción : ");
        scanf("%d",&op);
        switch(op) {
            case 1:
                printf("Numero de nodos del árbol: ");
                scanf("%d",&n);
                srand(time(NULL));
                for(i = 0;i < n;i++) {
                    printf("\n\tElemento No. %d: ",i + 1);
                    dato = rand()/100000000;
                    printf("%d",dato);
                    p = insertar(dato,p);
                }
                break;
            case 2:
                printf("Numero de nodos del árbol: ");
                scanf("%d",&n);
                for(i = 0;i < n;i++) {
                    printf("\n\tElemento No. %d: ",i+1);
                    scanf("%d",&dato);
                    p = insertar(dato,p);
                }
                break;
            case 3:
                printf("\n\tDato a Buscar: ");
                scanf("%d",&dato);
                q = buscar(dato,p);
                if(q != NULL)
                    printf("Se encontró el dato %d",dato);
                else
                    printf("No se encontró el dato %d",dato);
                break;
            case 4:
                printf("\n\n\tNodos : %d\n\n\tAltura =%d",cuenta_nodos(p),fe(p));
                break;
            case 5:
                printf("Árbol AVL");
                ver(0,p);
                break;
            case 6:
                printf("\n\tDato a borrar: ");
                scanf("%d",&dato);
                q = deleteNode(dato, p);
                if(q)
                    printf("Se borró el dato %d",dato);
                else
                    printf("No se encontró el dato %d",dato);
                break;
            case 7:
                borrar_AVL(p); /* Borra el árbol */
                exit(0);
                break;
            default:
                printf("Opción no válida");
                break;
        }
    }
    borrar_AVL(p);
}
