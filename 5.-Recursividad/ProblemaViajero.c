/*Problema del viajero Selección optima*/

#include <stdio.h>

#define M 12

typedef struct {
  int pso;
  int val;
}objeto;


struct{
  int n;
  objeto obj[M];
}a;  /*Array de objetos*/

typedef struct{
  int k;
  int b[M];
}conjunto;

conjunto actual,optimo;
int pesoMaximo;
void entredaObjetos();
void probarObjeto(int i, int pt,int va, int * mejorValor);
void escribirOptimo(int mejor);

int main(){
  int i;
  int maxValor,mejorValor;
  entredaObjetos();
  printf("Peso maximo = ");
  scanf("%d", &pesoMaximo);
  /*Suma de los valores de cada objeto*/
  for (maxValor = i =0; i < a.n; i++){
    maxValor += a.obj[i].val;
    mejorValor = 0;
    actual.k = optimo.k =0;
    probarObjeto(1,0,maxValor, &mejorValor);
    escribirOptimo(mejorValor);
    return 0;
  }
}

void entredaObjetos(){
  int j;
  do {
    printf("\n\tNumero de objetos: ");
    scanf("%d",&a.n);
  } while( (a.n < 1)||(a.n > M));
  for(j =1; j <= a.n; j++){
    printf("\tObjeto %d <peso valor> =", j);
    scanf("%d %d", &a.obj[j-1].pso, &a.obj[j-1].val);
  }
}

void probarObjeto(int i, int pt,int va, int * mejorValor){
  int valExclusion;
  if(pt+a.obj[i-1].pso <= pesoMaximo){
    actual.k++;
    actual.b[actual.k -1] = i-1;
    if(i < a.n)
      probarObjeto(i+1, pt+a.obj[i-1].pso, va,mejorValor);
      else 
        if(va > (*mejorValor)){
          optimo = actual;
          (*mejorValor) = va;
        }
      actual.k--;
  }
  valExclusion = va-a.obj[i-1].val;
  if(valExclusion > (*mejorValor))
    if(i < a.n)
      probarObjeto(i+1, pt, valExclusion,mejorValor);
    else {
      optimo = actual;
      (*mejorValor) = valExclusion;
    }
}

void escribirOptimo(int mejor){
  int j;
  printf("\t Seleccion de objetos que forma la seleccion optima\n");
  for (j=1; j<= optimo.k; j++){
    printf("\tObjeto %d = <%d,%d>\n", optimo.b[j-1] +1, a.obj[optimo.b[j-1]].pso, a.obj[optimo.b[j-1]].val);
  }
  printf("\tValor optimo = %d \t para un meso máximo =%d", mejor, pesoMaximo);
}


