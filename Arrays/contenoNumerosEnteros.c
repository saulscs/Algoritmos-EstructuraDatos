/*Programa que examina la cantidad de nueros enteros*/

#include <stdio.h>

#define NUM 4

int main(void) {
 int nums[NUM];
 int i;
 int total = 0;

 for(i = 0; i < NUM; i++){
   printf("Ingresa un numero: ");
   scanf("%d", &nums[i]);
 }

  printf("\nLista de numeros: ");

  for(i = 0; i < NUM; i++){
    total = (nums[i]>0 ? nums[i] : 0);
  }
  printf("\nLa suma de los numeros es %d", total);
  return 0;
}