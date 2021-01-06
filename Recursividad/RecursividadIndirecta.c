/*
Recursividad indiecta
Determinar si un numero entero positivo es par o impar con dos funciones que se llaman mutuamente*/


#include <stdio.h>
#include <string.h>

int par(int n);
int impar(int n);

int main(){
  int n;
  char rslt[12];
  do {
    printf("Introdusca un numero: ");
    scanf("%d",&n);
  } while(n < 0);
  if(par(n))
    strcpy(rslt, "es par");
  else 
    strcpy(rslt, "es impar");
    printf("\t %d %s", n,rslt );
    return 0;
}

int par(int n){
  if(n == 0)
    return 1;
  else 
    return impar(n-1);
}

int impar(int n){
  if(n == 0)
    return 0;
  else 
    return par(n-1);
}


/*Para resolver el ejercicio se escrieben dos funciones par() e impar() que se llaman mutuamente.
El programa principal llama a par pasando el entero 
n que se desea saber si es impar o par. Desde la funcion par() se llama a impar() pasando n-1 y lo mismo desde impar() a par(). En el caso base n==0 si esto ocurre el metodo par() es que el entero es par ya que el numero llamdado es multiplo de 2 y de igual forma si el caso base ocurre impar() es que el numero es impar por lo que par debe devolver false()*/