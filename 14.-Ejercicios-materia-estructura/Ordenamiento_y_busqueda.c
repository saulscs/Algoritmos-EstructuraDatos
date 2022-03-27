//
//  main.c
//  METODOS DE ORDENAMIENTO Y METODOS DE BUSQUEDA
//
//  Created by saul corona on 28/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototipos
void burbuja(int a[], int n);
void insercion(int a[], int n);
void seleccion(int a[], int n);
void quicksort(int a[], int primero, int ultimo);
int secuencial(int a[], int elemento, int n);
int binaria(int a[], int elemento, int n);
int interpolacion(int a[], int elemento, int n);
void imprimir(int arreglo[], int n);
int findlargestelement(int arr[], int n);
int frecuenciaMasBuscada(int arr[], int n);
void frecuenciasRepetidas(int a[], int n);

//Variables globlales
int contadorBurbuja = 0, contadorInsercion = 0, contadorSeleccion = 0, contadorQuicksort = 0;


//Metodos de ordenamiento

//Ordenar por burbuja
void burbuja(int a[], int n){
    int i, j, tmp;
    for(i = 0; i < n; i++){
        contadorBurbuja = contadorBurbuja + 1;
        for(j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}


//Ordenar por Inserción
void insercion(int a[], int n){
    int i, key, j;
    for(i = 1; i < n; i++){
        contadorInsercion = contadorInsercion + 1;
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}


//Ordenar por seleccion
void seleccion(int a[], int n){
    int i, j, posicion,intercambio;
    for(i = 0; i < (n - 1); i++){
        contadorSeleccion = contadorSeleccion + 1;
        posicion=i;
        for(j = i + 1; j < n; j++){
            if(a[posicion] > a[j])
                posicion=j;
        }
        if(posicion != i){
            intercambio=a[i];
            a[i]=a[posicion];
            a[posicion]=intercambio;
        }
    }
}


//Ordenar por quicksort
void quicksort(int a[], int primero, int ultimo){
    int i, j, pivote, tmp;
    
    if(primero < ultimo) {
        contadorQuicksort = contadorQuicksort + 1;
        pivote = primero;
        i = primero;
        j = ultimo;
        while (i < j) {
            while (a[i] <= a[pivote] && i < ultimo)
                i++;
            
            while (a[j] > a[pivote])
                j--;
            
            if(i < j){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        
        tmp = a[pivote];
        a[pivote] = a[j];
        a[j] = tmp;
        quicksort(a, primero, j - 1);
        quicksort(a, j + 1 , ultimo);
    }
}

//Metodos de busqueda

//Busqueda secuencial
int secuencial(int a[], int elemento, int n){
    int i;
    for (i = 0; i < n; i++){
        //contadorSecuencial = contadorSecuencial + 1;
        if (a[i] == elemento){
            return  i;
        }
    }
    return  -1;
}


//busqueda binaria
int binaria(int a[], int elemento, int n){
    int primero = 0, ultimo = n - 1, centro;
    while (primero <= ultimo){
        centro = primero + (ultimo - primero)/2;
        if(a[centro] == elemento)
            return  centro;
        if(a[centro] < elemento)
            primero = centro + 1;
        else
            ultimo = centro - 1;
    }
    return  -1;
}

//busqueda por interpolación
int interpolacion(int a[], int elemento, int n){
    int centro, fondo = 0, tope =  n - 1;
    
    while(a[tope] != a[fondo] && elemento >= a[fondo] && elemento <= a[tope]){
        
        centro = fondo + ((elemento -a[fondo]) * (tope - fondo) / (a[tope] - a[fondo]));
        centro = roundf(centro);
        
        if (elemento == a[centro]){
            return  centro;
        } else if (elemento < a[centro]){
            tope = centro - 1;
        } else{
            fondo = centro + 1;
        }
    }
    
    if(elemento == a[fondo]){
        return fondo;
    } else {
        return -1;
    }
}


// Funcion para imprimir arreglo
void imprimir(int arreglo[], int n){
    int c;
    for(c=0;c<n;c++)
        printf("%d ",arreglo[c]);
}

//Funcion menos solicitada
int frecuenciaMenosBuscada(int a[], int n){
    int menor = a[0];
    for (int i=0; i<n; i++){
        if (a[i] < menor){
            menor = a[i];
        }
    }
    return menor;
}


// Funcion frecuencia más buscada
int frecuenciaMasBuscada(int a[], int n){
    int mayor = a[0];
   for(int i=0; i<n; i++) {
      if(mayor<a[i]) {
         mayor=a[i];
      }
   }
   return mayor;
}

// Funcion frecuencias repetidas
void frecuenciasRepetidas(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j]){
                printf("Frecuencias que se repiten: %d", a[i]);
            }
        }
    }
    
}


//Programa principal
int main() {
    int elementoAbuscar, submenu, submenu2, masBuscada, menosBuscada;
    int opcion,i,j,k=0;
    int frecuencia[5][4]={{100,230,350,700},{321,1,900,202},{102,23,5,12},{654,200,123,650},{403,202,199,90}}; //matriz
    int arreglo[20]; // nuevo arreglo de una dimensión
    
    //Ciclo for para convertir la matriz en un arrelo de una sola dimensión
    for(i=0;i<5;i++) {
        for(j=0;j<4;j++) {
            arreglo[k]=frecuencia[i][j];
            k++;
        }
    }
    
    //Tamaño del arreglo
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    
    do{
        printf("\n--MENU PRINCIPAL---\n");
        printf ("\nIngresa la opción:\n1-Imprimir  \n2-Metodos de ordenamiento \n3-Metodos de busqueda \n4-Frecuencia más buscada \n5-Frecuencia menos buscada \n6-Frecuencia repetida \n0-Salir\n\n\n");
        scanf ("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("\n---Imprimir---\n");
                imprimir(arreglo, n);
                break;
            case 2: // Submenu para metodos de ordenamiento
                do {
                    printf("\n---METODOS DE ORDENAMIENTO---\n");
                    printf("\n \n1-Imprimir \n2-Ordenar por burbuja \n3-Ordenar por Inserción \n4-Ordenar por Selección \n5-Ordenar QuickSort \n0-Salir\n\n\n");
                    scanf ("%d", &submenu);
                    switch (submenu) {
                        case 1:
                            printf("\n---Imprimir---\n");
                            imprimir(arreglo, n);
                            break;
                        case 2:
                            printf("\n---Ordenar por burbuja---\n");
                            burbuja(arreglo, n);
                            printf("Numero de ciclos ejecutados %d\n\n", contadorBurbuja);
                            break;
                        case 3:
                            printf("\n---Ordenar por Inserción---\n");
                            insercion(arreglo, n);
                            printf("Numero de ciclos ejecutados %d\n\n", contadorInsercion);
                            break;
                        case 4:
                            printf("\n---Ordenar por Selección---\n");
                            seleccion(arreglo, n);
                            printf("Numero de ciclos ejecutados %d\n\n", contadorSeleccion);
                            break;
                        case 5:
                            printf("\n---Ordenar QuickSort---\n");
                            quicksort(arreglo,0,n-1);
                            printf("Numero de ciclos ejecutados %d\n\n", contadorQuicksort);
                            break;
                        case 0:
                            break;
                    }
                } while(submenu != 0);
                break;
            case 3:
                do {
                    printf("\n---METODOS DE BUSQUEDA---\n");
                    printf("\n \n1-Imprimir \n2-Busqueda secuencial \n3-Busqueda binaria \n4-Busqueda por interpolación \n0-Salir\n\n\n");
                    scanf ("%d", &submenu2);
                    switch (submenu2) {
                        case 1:
                            printf("\n---Imprimir---\n");
                            imprimir(arreglo, n);
                            break;
                        case 2:
                            printf("\n---Busqueda secuencial---\n");
                            printf("Ingresa el numero que quieres buscar: ");
                            scanf("%d", & elementoAbuscar);
                            int busquedaSecuencial = secuencial(arreglo, elementoAbuscar, n);
                            (busquedaSecuencial == -1)
                            ? printf("No se encontro el elemento en el arreglo\n\n")
                            : printf("Se encontro en la posicion %d\n\n", busquedaSecuencial + 1);
                            break;
                        case 3:
                            printf("\n---Busqueda binaria---\n");
                            printf("Ingresa el numero que quieres buscar: ");
                            scanf("%d", & elementoAbuscar);
                            int busquedaBinaria = binaria(arreglo, elementoAbuscar, n);
                            (busquedaBinaria == -1)
                            ? printf("No se encontro el elemento en el arreglo\n\n")
                            : printf("Se encontro en la posicion %d\n\n", busquedaBinaria + 1);
                            break;
                        case 4:
                            printf("\n----Busqueda por interpolación---\n");
                            printf("Ingresa el numero que quieres buscar: ");
                            scanf("%d", & elementoAbuscar);
                            int busquedaInterpolacion = interpolacion(arreglo, elementoAbuscar, n);
                            (busquedaInterpolacion == -1)
                            ? printf("No se encontro el elemento en el arreglo\n\n")
                            : printf("Se encontro en la posicion %d\n\n", busquedaInterpolacion + 1);
                            break;
                        case 0:
                            break;
                    }
                }while(submenu2 != 0);
                break;
            case 4:
                printf("\n----Frecuencia más buscada---\n");
                masBuscada = frecuenciaMasBuscada(arreglo, n);
                printf("El elemento más buscado es: %d", masBuscada);
                break;
            case 5:
                printf("\n----Frecuencia menos buscada---\n");
                menosBuscada = frecuenciaMenosBuscada(arreglo, n);
                printf("El elemento menos buscado es: %d", menosBuscada);
                break;
            case 6:
                printf("\n----Frecuencia que más se repite---\n");
                frecuenciasRepetidas(arreglo, n);
                break;
            case 0:
                break;
            default:
                break;
        }
    }while(opcion != 0);
    return 0;
}
