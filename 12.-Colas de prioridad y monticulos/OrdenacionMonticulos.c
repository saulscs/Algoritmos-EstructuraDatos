/*Ordenación por monticulos (HeapSort)*/


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int pedirN(void);
int *crearArreglo(int);
void llenar_arreglo(int, int *);
void mostrar_arreglo(int, int *);
int heapsort (int, int *);
int formar_monticulo(int, int *);
int hoja_padre(int);
int ordenar_monticulo(int, int *);
int obtener_hijo_mayor(int, int *, int);

int main(int argc, char **args){
    int n = pedirN();
    int *arreglo = crearArreglo(n);
    llenar_arreglo(n, arreglo);
    mostrar_arreglo(n, arreglo);
    int cant = heapsort(n, arreglo);
    mostrar_arreglo(n, arreglo);
    printf("Fueron %d operaciones\n", cant);
    return 0;
}


/*Pedir numero de elementos*/
int pedirN(void){
    int n;
    do{
        printf("Dame el valor de n: ");
        scanf("%d", &n);
        if(n<2){
            printf("Dame una n > 1\n");
        }
    }while(n < 2);
    return n;
}



int *crearArreglo(int n){
    int *a = calloc(n, sizeof(int));
    return a;
}


/*Funcion para llenar el arreglo*/
void llenar_arreglo(int n, int *a){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand() % (n * 10);
    }
}


/*Función para imprimir arreglos*/
void mostrar_arreglo(int n , int *a){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    putchar('\n'); 
}


int heapsort(int n, int *arreglo){
    int cant = 0;
    cant += formar_monticulo(n, arreglo);
    cant += ordenar_monticulo (n, arreglo);  
}

/*Contruir monticulo inicial con todos los elementos*/

int formar_monticulo(int n, int *arreglo){
    int temp;
    int cant = 0;
    for(int i=1; i<n; i++){
        temp = arreglo[i];
        int hoja_actual = i;
        while (hoja_actual > 0 && temp > arreglo[hoja_padre(hoja_actual)]){
            arreglo[hoja_actual] = arreglo[hoja_padre(hoja_actual)];
            hoja_actual = hoja_padre(hoja_actual);
            cant ++;
        }
        arreglo[hoja_actual] = temp;
    }
    return cant;
}

/*Reordenar los monticulos*/


int ordenar_monticulo(int n, int *arreglo){
    int temp;
    int cant = 0;
    for(int i = n-1; i > 0; i--){
        temp = arreglo[i];
        arreglo[i] = arreglo[0];
        int hoja_actual = 0;
        int hijo_mayor = obtener_hijo_mayor(i, arreglo, hoja_actual);
        while(hijo_mayor && arreglo[hijo_mayor] > temp){
            arreglo[hoja_actual] = arreglo[hijo_mayor];
            hoja_actual = hijo_mayor;
            hijo_mayor = obtener_hijo_mayor(i, arreglo, hoja_actual);
            cant ++;
        }
        arreglo[hoja_actual] = temp;
    }
    return cant;
}

int hoja_padre(int i){
    return (i - 1)/  2;
}


/*Ordenar los monticulos*/

int obtener_hijo_mayor(int n, int *arreglo, int hoja_actual){
    int hijo_izquierdo = 2 * hoja_actual + 1;
    int hijo_derecho = 2 * hoja_actual + 2;
    if(hijo_derecho < n){
        return (arreglo[hijo_izquierdo] > arreglo [hijo_derecho] ? hijo_izquierdo : hijo_derecho);
    }else if(hijo_izquierdo < n){
        return hijo_izquierdo;
    }else{
        return 0;
    }
}