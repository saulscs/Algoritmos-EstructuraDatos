/*Algoritmo de ordenación por metodo Quicksort*/
#include <stdio.h>

#define N 100
void quicksort(int a[], int primero, int ultimo);
void imprimirLista(int a[], int n);
void entradaLista(int a[], int n);  


int main() {
 int n;
 int v[N];
 do{
   printf("\nIntrodusca el numero de elementos: ");
   scanf("%d", &n);
 }while( (n<1) && (n>N));
 entradaLista(v,n);
  /*Muestra lista original*/
  printf("\nLista original de %d elementos", n);
  imprimirLista(v,n);
  quicksort(v,0,n-1);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void quicksort(int a[], int primero, int ultimo){
  int i,j,central;
  int pivote;

  central = (primero + ultimo)/2;
  pivote = a[central];
  i = primero;
  j = ultimo;
  
  do{
    while (a[i] < pivote) i++;
    while(a[j] > pivote) j--;

    if(i <= j){
      int tmp;
      tmp = a[i];
      a[i] = a[j];
      a[j] = tmp;
      i++;
      j--;
    } 
  }while(i <= j);
  if(primero < j)
  quicksort(a,primero,j); /*mismo proceso con sublista izqda*/
  if(i<ultimo)
  quicksort(a,i,ultimo);
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
