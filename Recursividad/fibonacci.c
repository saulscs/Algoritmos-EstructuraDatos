/*Escribe los primeros numeros de la serie de fibonacci siendo n el
numero que se le pide al usuario*/

#include <stdio.h>

int Fibonacci(int);
 
int main()
{
   int n, i = 0, c;

   printf("Ingresa un numero para regresar la posición en la serie de fibonacci: \n");
 
   scanf("%d",&n);
 
   printf("Fibonacci series\n");
 
   for ( c = 1 ; c <= n ; c++ )
   {
      printf("%d\n", Fibonacci(i));
      i++; 
   }
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
} 