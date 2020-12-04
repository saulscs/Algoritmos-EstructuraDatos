/*Algoritmo de Ordenacion por seleccion*/


/*FUENTES
https://parzibyte.me/blog/2020/05/16/ordenamiento-seleccion-c/

https://www.ecured.cu/Algoritmo_de_ordenamiento_por_selecci%C3%B3n
*/

#include <stdio.h>



void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

void seleccion(int arreglo[], int longitud) {
  for (int i = 0; i < longitud - 1; i++) {
    for (int j = i + 1; j < longitud; j++) {
     
      if (arreglo[i] > arreglo[j]) {
        // ...intercambiarlos, es decir, mover el actual a la derecha y el de la derecha al actual
        intercambiar(&arreglo[i], &arreglo[j]);
      }
    }
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


	seleccion(arreglo, longitud);
	/*
  Imprimirlo después de ordenarlo
  */
  printf("Imprimiendo arreglo despues de ordenar...\n");
  for (int x = 0; x < longitud; x++)
    printf("%d ", arreglo[x]);
  return 0;
}