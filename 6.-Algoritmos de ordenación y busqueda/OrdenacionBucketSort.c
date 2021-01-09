/*Algoritmo de ordenación por metodo bucketsort o binsort*/
#include <stdio.h>
#include <stdlib.h>


#define N 100
void bucketSort(int a[], int n);
void imprimirLista(int a[], int n);
void entradaLista(int a[], int n);  


struct bucket {
    int count;
    int* value;
};

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
  bucketSort(v,n);
  printf("\nLista ordenada de %d elementos", n);
  imprimirLista(v,n);
  return 0;
}

int compareIntegers(const void* first, const void* second) {
    int x = *((int*)first), y =  *((int*)second);
    if (x == y){
      return 0;
    }
    else if (x < y){
      return -1;
    }
    else{
      return 1;
    }
}

void bucketSort(int a[], int n){
  struct bucket buckets[n];
  int i, j, k;
    for (i = 0; i < n; i++) {
      buckets[i].count = 0;
      buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++){
        if (a[i] < 0){
           buckets[0].value[buckets[0].count++] = a[i];
        }
        else if (a[i] > 10){
          buckets[2].value[buckets[2].count++] = a[i];
        }
        else{
          buckets[1].value[buckets[1].count++] = a[i];
        }
    }
    for (k = 0, i = 0; i < n; i++){
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++){
          a[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
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