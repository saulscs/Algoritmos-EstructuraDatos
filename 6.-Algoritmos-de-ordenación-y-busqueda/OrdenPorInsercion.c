/*Algoritmo de ordenación por inserción*/

#include <stdio.h>

#define N 100
void ordInsercion (int a[], int n );
void imprimirLista(int a[], int n);
void entradaLista(int a[], int n);


int main() {
 int n;
 int v[N];
 do{
   printf("\nIntrodusca en numero de elementos: ");
   scanf("%d", &n);
 }while( (n<1) && (n>N));
 entradaLista(v,n);
  /*Muestra lista original*/
  printf("\nLista original de %d elementos", n);
  imprimirLista(v,n);
  ordInsercion(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordInsercion (int a[], int n ){
  int i,j;
  int aux;
  for (i=1; i<n;i++){
    /*Indice j explora la sublista a[i-1]..a[0] buscando la posición correcta del elemento destino, loa asigna a a[j]*/
    j = i;
    aux = a[i];
    /*Se localiza el punto de insercion explorando hacia abajo*/
    while(j > 0 && aux < a[j-1]){
      /*desplazar elementos hacia arriba para hacer espacio*/
      a[j] = a[j-1];
      j--;
    }
    a[j] = aux;
  }
}

void imprimirLista(int a[], int n){
  int i;
  for (i =0; i < n; i++){
    char c;
    c = (i%10 == 0) ? '\n': ' ';
    printf("%c %d", c, a[i]);
  }
}

void entradaLista(int a[], int n){
  int i;
  printf("Entrada de los elementos\n");
  for(i=0; i< n; i++){
    printf("a[%d] = ", i+1);
    scanf("%d", &a[i]);
  }
}