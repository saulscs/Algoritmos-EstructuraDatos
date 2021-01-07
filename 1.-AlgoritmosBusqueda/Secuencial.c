/*https://ronnyml.wordpress.com/2009/07/09/busqueda-lineal-y-busqueda-binaria/*/

/*Algoritmo de busqueda secuencial*/ 

#include <stdio.h>


int secuencial(int arreglo[], int longitud, int x){
  int encontrado, k, posicion;
  posicion = -1;
  encontrado = 0;
  k = 0;
  

  while ((k< longitud) && (!encontrado)){
    if(arreglo[k] == x){
      posicion = k;
      encontrado = 1;
    } 
      else 
        k++;
  }
  
  return printf("\n %d se encuentra en la posicion  %d", x,posicion);
}




int main(void) {
  
  /*El arreglo*/ 
  
  int arreglo[] = {30, 28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
  
  /*Calcular la longitud, puede ser definida por ti o calculada: */
  
  int longitud = sizeof arreglo / sizeof arreglo[0];
  
  /*Numero a buscar*/
  
  int x = 21;
  
  /* Imprimirlo antes de ordenarlo */
  
  printf("\nImprimiendo arreglo \n");
  for (int x = 0; x < longitud; x++) {
    printf("%d ", arreglo[x]);
  }

  printf("\n");


	secuencial(arreglo, longitud,x); 
  
  return 0;
}

