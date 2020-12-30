//Arrays de estructura

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct inventario{
  char titulo[25];
  char fecha_pub[20];
  char autor[30];
  int num;
  int pedido;
  float precio_venta;
};


int main(void){
  struct inventario libro[10];
  int total = 0;
  char resp, b[21];

  do {
    printf("Total libros %d\n", (total+1));
    printf("\n¿Cuál es el titulo? \n");
    scanf("%s",libro[total].titulo);
    printf("\n¿Cual es la fecha de publicación?\n");
    scanf("%s",libro[total].fecha_pub);
    printf("\n¿Quién es el autor?\n");
    scanf("%s",libro[total].autor);
    printf("\n¿Cuantos libros existen?\n");
    scanf("%d",&libro[total].num);
    printf("\n¿Cuantos ejemplares se pidieron?\n");
    scanf("%d",&libro[total].pedido);
    printf("\n¿Cual es el precio de venta?\n");
    scanf("%.2f", libro[total].precio_venta);
    printf("\n¿Hay más libros? (S/N)\n");
    scanf("%c",&resp);
    fflush(stdin);
    resp = toupper(resp);
    if(resp == 'S'){
      total ++;
      continue;
    }
  }
  while(resp == 'S');
  return 0;
}
