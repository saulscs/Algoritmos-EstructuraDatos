#include <stdio.h>

/*Rellenar tabla con datos de entrada y mostrar en pantalla*/

int main() {
  float discos[2][4];
  int fila,col;

  for(fila = 0; fila <2; fila ++){
    for(col = 0; col <4; col++){
      printf("\nIngresa datos: ");
      scanf("%f",&discos[fila][col]);
    }
  }

  for(fila = 0; fila <2; fila ++){
    for(col = 0; col <4; col++){
      printf("\nPts %.1f \n",discos[fila][col]);
    }
  }

  
}