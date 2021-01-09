/*Algoritmo de ordenación por metodo shell*/
#include <stdio.h>

#define N 100
void ordenacionShell(int a[], int n);
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
  ordenacionShell(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

void ordenacionShell(int a[], int n){
  int intervalo, i, j, k;
  intervalo = n / 2;

  while(intervalo > 0){
    for (i = intervalo; i <n; i++){
      j = i - intervalo;
      while(j >= 0){
        k = j + intervalo;
        if(a[j] <= a[k])
          j = -1;
        else {
          int temp;
          temp = a[j];
          a[j] = a[k];
          a[k] = temp;
          j -= intervalo;
        }
      }
    }
    intervalo = intervalo / 2;
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