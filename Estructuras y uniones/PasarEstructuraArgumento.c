//Pasar la estructura como un argumento
#include <stdio.h>

//Definir la estrucutra
struct student{
  char name[50];
  int age;
  int roll_no;
  float marks;
};


void print(char name[],int age,int roll_no, float marks){
  printf("%s %d %d %.2f",name,age,roll_no,marks);
}

int main(){
  struct student s1 = {"Nick",16,200,9.0};
  print(s1.name,s1.age,s1.roll_no,s1.marks);
}