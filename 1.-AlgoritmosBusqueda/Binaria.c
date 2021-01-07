/*https://ronnyml.wordpress.com/2009/07/09/busqueda-lineal-y-busqueda-binaria/*/

/*Algoritmo de busqueda binaria*/ 

#include <stdio.h>

int busquedaBinaria(int arreglo[], int x, int longitud){
  int encontrado;
  int primero,ultimo,central;
  encontrado = 0;
  primero =0;
  ultimo = longitud - 1;

  while((primero <= ultimo) && (!encontrado)){
    central = (primero + ultimo)/2;

    if(arreglo[central] == x){
      encontrado = 1;
    } else{
      if(arreglo[central] > x)
        primero = central +1;
        else 
          ultimo = central -1;
    }
  }
  if(!encontrado)
    return printf("\nNo se encontro  %d", -1);
  else 
    return printf("\nSe encontro %d", central);
}

int main(void) {
  // El arreglo
  int arreglo[] = {30, 28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
  /*
  Calcular la longitud, puede ser definida por ti o calculada: */
  int longitud = sizeof arreglo / sizeof arreglo[0];
  
  /*Numero a buscar*/
  int x = 11;
  /*
  Imprimirlo antes de ordenarlo
  */
  printf("\nImprimiendo arreglo \n");
  for (int x = 0; x < longitud; x++) {
    printf("%d ", arreglo[x]);
  }

  printf("\n");


	busquedaBinaria(arreglo,x,longitud); 
  
  return 0;
}

