#include <stdio.h>
#include <string.h>
#include <math.h>

#define m 1000
#define R 0.6180334

long transformaClave(const char* clave);
int dispersion(long x);

int main(){
  char clave[11];
  long valor;
  int k;

  for (k=1; k<=10; k++){
    printf("\nClave a dispersar: ");
    scanf("%s", clave);
    valor = transformaClave(clave);
    valor = dispersion(valor);
    printf("Dispersión de la clave %s -> %ld\n", clave,valor);
  }
}


long transformaClave(const char* clave){
  int j;
  long d;

  d=0;
  for(j=0; j < strlen(clave); j++){
    d = d * 27 + clave[j];
  }
  /*En caso de valor grande no se puede almacenar en memoria 
    y genere un numero negativo*/
  if( d < 0) d = -d;
  return d;
}

int dispersion(long x){
  double t;
  int v;
  t = R * x - floor(R * x); /*Parte decimal*/
  v = (int) m * t;
  return v;
}