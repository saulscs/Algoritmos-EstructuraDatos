/*Algoritmo de ordenación por selccion*/

#include <stdio.h>

#define N 100
void ordSeleccion(int a[], int n);
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
  ordSeleccion(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordSeleccion(int a[], int n){
  int indiceMenor, i,j;
  /*Ordenar un a[0]...a[n-2] y a[n-1] en cada pasada*/
  for(i=0; i < n-1; i++){
    /*Comienza con la exploración en indice i*/
    indiceMenor = i;
    /*Explora la sublista a[i+1]...a[n-1]*/
    for(j= i+1; j<n; j++)
      if(a[j] < a[indiceMenor])
        indiceMenor = j;
          /*Situa el elemento más pequeño en a[i]*/
          if(i != indiceMenor){
            int aux = a[i];
            a[i] = a[indiceMenor];
            a[indiceMenor] = aux;

          }
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