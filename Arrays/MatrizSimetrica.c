/*Determinar si una matriz es simetrica. La matriz se genera con
numeros aleatorios. El programa itera hasta encontrar 
una matriz simetrica*/



#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NFILAS 10
#define NCOLUMNAS 10

 
typedef struct{
    int fila;
    int columna;
}COORDENADAS;

 

int main(int argc, char* argv[]){
  
  COORDENADAS mayor,menor;
  int i,j;
  int matriz[NFILAS][NCOLUMNAS];

  srand((unsigned)time(NULL));
  //lleno la matriz

  for (i=0; i<NFILAS; i++){
    for (j=0; j<NCOLUMNAS; j++){
        matriz[i][j] = (rand()%255)+1;
      }
  }
   
  //Asigno a mayor y menor el valor del primer elemento del array
  mayor.fila = mayor.columna = menor.fila = menor.columna = 0;

  for (i=0; i<NFILAS; i++){
    for (j=0; j<NCOLUMNAS; j++){
      printf ("%3i",matriz[i][j]);
      if (j < NCOLUMNAS-1)
        printf("\t");
      if (matriz[i][j] > matriz[mayor.fila][mayor.columna]){
        mayor.fila = i;
        mayor.columna = j;
      }
      if (matriz[i][j] < matriz[menor.fila][menor.columna]){
        menor.fila = i;
        menor.columna = j;
      }

    }
     printf ("\n\n");
  }

    printf ("El numero mayor de la matriz es: matriz[%i][%i]=%i\n",mayor.fila,mayor.columna,matriz[mayor.fila][mayor.columna]);

    printf ("El numero menor de la matriz es: matriz[%i][%i]=%i\n",menor.fila,menor.columna,matriz[menor.fila][menor.columna]);

    printf ("Pulsa intro para salir...");

    getchar();

    return 0;
}