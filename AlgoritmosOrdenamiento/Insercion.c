/*Algoritmo de Ordenacion por insercion*/

#include <stdio.h>


void insercion(int arreglo[], int longitud){
  int k,i,orden;
  double tem;

  for (k =1; k < longitud; k++){
    orden = 0;
    tem = arreglo[k];
    i = k -1 ;
    while ((i >=0)&& (!orden)){
      if(arreglo[i] > tem){
        arreglo[i+1] = arreglo[i];
        i = i -1;
      } else 
        orden = 1;
      
    }
    arreglo[i+1] = tem; 
  }
}


int main(void) {
  // El arreglo
  int arreglo[] = {30, 28, 11, 96, -5, 21, 18, 12, 22, 30, 97, -1, -40, -500};
  /*
  Calcular la longitud, puede ser definida por ti o calculada: */
  int longitud = sizeof arreglo / sizeof arreglo[0];
  /*
  Imprimirlo antes de ordenarlo
  */
  printf("Imprimiendo arreglo antes de ordenar...\n");
  for (int x = 0; x < longitud; x++) {
    printf("%d ", arreglo[x]);
  }

  printf("\n");


	insercion(arreglo, longitud);
	/*
  Imprimirlo después de ordenarlo
  */
  printf("Imprimiendo arreglo despues de ordenar...\n");
  for (int x = 0; x < longitud; x++)
    printf("%d ", arreglo[x]);
  return 0;
}