/*Algoritmo de ordenación por burbuja*/
#include <stdio.h>

#define N 100
void ordBurbuja(int a[], int n);
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
  ordBurbuja(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordBurbuja(int a[], int n){
  int interructor = 1;
  int pasada,j;
  for (pasada =0; pasada < n-1 && interructor; pasada ++){
    /*Bucle externo controla la cantidad de pasadas*/
    interructor = 0;
    for (j = 0; j < n - pasada -1; j++)
      if(a[j] > a[j+1]){
        /*Elementos desordenados, es necesario intercambio*/
        int aux;
        interructor = 1;
        aux  = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;
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