
/*Algoritmo de ordenación*/

#include <stdio.h>

#define N 100
void ordIntercambio(int a[], int n);
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
  ordIntercambio(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordIntercambio(int a[], int n){
  int i,j;
  /*Se realiza n-1 pasadas*/
  /*a[o],...a[n-2]*/
  for(i=0; i<= n-2; i++){
    /*Coloca minimo de a[i+1]..a[n-1] en a[i]*/
    for (j = i+1; j <= n-1; j++)
      if(a[i] > a[j]){
        int aux;
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
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
    printf("a[%d] = ");
    scanf("%d", a+i);
  }
}