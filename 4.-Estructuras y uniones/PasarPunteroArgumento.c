//Pasar el puntero a la variable de estructura como argumento.

#include <stdio.h>

//Definir la estrucutra
struct point{
 int x;
 int y;
}; 


void print(struct point *ptr){
  printf("%d %d\n", ptr -> x, ptr ->y);
}

int main (){
  struct point p1 = {23,45};
  struct point p2 = {65,96};
  print(&p1);
  print(&p2);
  return 0;
}