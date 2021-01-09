/*Algoritmo de ordenación por burbuja 2*/
#include <stdio.h>

#define N 100
void ordBurbuja2(int a[], int n);
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
  ordBurbuja2(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordBurbuja2(int a[], int n){
  int i,j;
  int indiceIntercambio;

  /*i es el indice del ultimo elemento de la sublista*/
  i = n-1;
  /*El proceso continua hasta que no haya intercambios*/
  while (i > 0){
    indiceIntercambio = 0;
    /*Explorar la sublista a[0] a a [i]*/
    for (j = 0; j < i;  i++)
      if(a[j+1] < a[j]){
        int aux = a[j];
        a[j] = a[j+1];
        a[j +1] = aux;
        indiceIntercambio = j;
      }
      /*i se pone al valor del indice del ultimo intercambio*/
      i = indiceIntercambio;
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