/*Maximo como un divisor*/

#include <stdio.h>

int mcd(int m, int n);

int main(void) {
  int m,n;
  do{
    printf("Introduzca dos enteros positivos: ");
    scanf("%d %d", &m,&n);
  }while(n <= 0 || m <= 0);
  printf("\nEl maximo como un divisor es %d:", mcd(m,n));
}

int mcd(int m, int n){
  if(n <= m && m%n == 0)
  return n;
  else if (m < n)
    return mcd(n,m);
  else 
    return mcd (n, m%n);
}

/*El mcd es n si el numero más pequeño y n divide a m; si m es el numero más pequeño entonces la determinacion del mcd se debe ejecutar con los argumentos transpuestos; por ultimo si n no divide a m el resto se obtiene encontrando el mcd de n y el resto es dividido por n*/