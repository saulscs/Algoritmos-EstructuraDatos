//
//  main.c
//  Metodos de busqueda
//
//  Created by saul corona on 16/02/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define elementos 200

//Prototipos
int secuencial(int elemento, int a[]);
int binaria(int elemento, int a[]);
int interpolacion(int elemento, int a[]);

//Variables globales
int tamano,arreglo[elementos],elementoAbuscar,contadorSecuencial = 0,contadorBinario = 0,contadorInterpolacion = 0;

//Busqueda secuencial
int secuencial(int elemento, int a[]){
    int i;
    for (i = 0; i < tamano; i++){
        contadorSecuencial = contadorSecuencial + 1;
        
        if (a[i] == elemento){
            return  i;
        }
    }
    return  -1;
}

//busqueda binaria
int binaria(int elemento, int a[]){
    int izquierda = 0, derecha = tamano - 1, centro;
    
    while( izquierda <= derecha){
        contadorBinario = contadorBinario + 1;
        
        centro = izquierda + (derecha - 1) / 2;
        
        if(a[centro] == elemento){
            return centro;
        } else if (a[centro] < elemento){
            izquierda = centro + 1;
        } else {
            derecha = centro - 1;
        }
    }
    return  -1;
}


//busqueda por interpolación
int interpolacion(int elemento, int a[]){
    int centro, fondo = 0, tope = tamano - 1;
    
    while(a[tope] != a[fondo] && elemento >= a[fondo] && elemento <= a[tope]){
        contadorInterpolacion = contadorInterpolacion + 1;
        
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


int main() {
    int i,opcion,busquedaSecuencial,busquedaBinaria,busquedaInterpolacion;
    
    printf("Ingresa el tamaño del arreglo: ");
    scanf("%d", & tamano);
    
    printf("Ingresa en la misma linea los %d elementos del arreglo: ", tamano);
    
    for (i = 0; i < tamano; i++){
        scanf("%d", & arreglo[i]);
    }
    printf("Ingresa el numero que quieres buscar: ");
    scanf("%d", & elementoAbuscar);
    
    do {
        
        printf ("\nIngresa la opción:\n1-Busqueda secuencial  \n2-Busqueda binaria\n3-Busquda por interpolación\n0-Salir\n\n");
        scanf ("%d", &opcion);
        
        switch(opcion){
            case 1:
                printf("\n---Busqueda secuencial---\n");
                busquedaSecuencial = secuencial(elementoAbuscar, arreglo);
                (busquedaSecuencial == -1)
                ? printf("No se encontro el elemento en el arreglo\n\n")
                : printf("Numero de ciclos ejecutados %d\n\n", contadorSecuencial);
                break;
            case 2:
                printf("\n---Busqueda binaria---\n");
                busquedaBinaria = binaria(elementoAbuscar, arreglo);
                (busquedaBinaria == -1)
                ? printf("No se encontro el elemento en el arreglo\n\n")
                : printf("Numero de ciclos ejecutados %d\n\n", contadorBinario);
                break;
            case 3:
                printf("\n---Busqueda por interpolación---\n");
                busquedaInterpolacion = interpolacion(elementoAbuscar, arreglo);
                (busquedaInterpolacion == -1)
                ? printf("No se encontro el elemento en el arreglo\n\n")
                : printf("Numero de ciclos ejecutados %d\n\n", contadorInterpolacion);
                break;
            case 0:
                break;
            default:
                printf ("Invalido");
        }
    }while (opcion != 0);
    return 0;
}
