/*Torre de Hanoi recursiva*/

#include <stdio.h>

int hanoi(char varinicial,char varcentral,char varfinal,int n );

int main(){
  char varinicial = 'A',  varcentral = 'B',  varfinal = 'C';
  int n;

  printf("Ingresa el numero de discos: ");
  scanf("%d", &n);
  printf("\nSecuencia de discos\n");
  hanoi(varinicial,varcentral,varfinal,n);
  printf("\n");
  return 0;
}


int hanoi(char varinicial,char varcentral,char varfinal,int n ){
  if(n == 1){
    printf("Mover disco %d desde varilla %c a varilla %c \n", n, varinicial, varfinal);
  }
    else {
      hanoi(varinicial,varcentral,varfinal, n-1);
      printf("Moves disco %d desde la varilla %c a varilla %c \n",n, varinicial, varfinal);
      hanoi(varinicial,varcentral,varfinal, n-1);
      return 0;
    }      
}
