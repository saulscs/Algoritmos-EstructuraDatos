//Pasar una estructura por argumento
#include <stdio.h>

//Definir la estrucutra
struct charset{
  char s;
  int i;
};


void keyvalue(char *s, int *i){
  printf("\nIngresa una letra y un numero: ");
  scanf("%c %d", s, i);
}

int main (){
  struct charset cs;
  keyvalue(&cs.s, &cs.i);
  printf("%c %d", cs.s,cs.i);
  return 0;
}