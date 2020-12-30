//sizeof de tipos de datos estructurados

#include <stdio.h>


#define NAME_LENGTH 10
#define TABLE_SIZE 100
#define UNITS_NUMBER 10

struct unit
{  /* Definir una estructura con una union */
  int x;
  float y;
  double z;
  short int a;
  long b;
  union
  { /* La union no tiene nombre porque esta dentro de la estructura */
    char name[NAME_LENGTH];
    int id;
    short int sid;
  } identifier;
};

int main(int argc, char *argv[])
{
  int table[TABLE_SIZE];
  struct unit data[UNITS_NUMBER];

  printf("%d\n", sizeof(struct unit)); 
  printf("%d\n", sizeof(table));       
  printf("%d\n", sizeof(data));       

  return 0;
}