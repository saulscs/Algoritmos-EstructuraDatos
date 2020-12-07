#include <stdio.h>

/*La funcion Leer() lee un array (una tabla) de dos dimenciones 
y la funcion visualización() presenta la tabla en pantalla*/

void Leer(int a[][5]);
void Visualizar( const int a[][5]);

int main() {
 int a[3][5];
 Leer(a);
 Visualizar(a);
 return 0;
}

void Leer(int a[][5]){
  int i,j;
  printf("Ingresa 15 numeros 3 por fila: ");
  for(i=0; i < 3; i++){
    for(j=0; j < 5; j++){
      printf("\nFila %d: ",i);
      scanf("%d",&a[i][j]);
    }
  }
}

void Visualizar(const int a[][5]){
  int i,j;
  for(i=0; i < 3; i++){
    for(j=0; j < 5; j++){
      printf("%d: ",a[i][j]);
      printf("\n");
    }
  }
}