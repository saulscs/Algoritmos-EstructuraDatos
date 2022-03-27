//
//  main.c
//  Pila_EA_SACS
//
//  Created by saul corona on 01/02/22.
//

#include <stdio.h>
#include <stdlib.h>

//prototipos
void pon(int);
int quita(void);
void lleno(void);
void vacio(void);
void imprimir(void);

//Variables globales
#define N 10
int stack[N];
int top = -1;

//Insertar a la pila
void pon(int n) {
    if (top == N-1) {
      printf ("-----Se desarramo la pila----\n");
    } else {
      top++;
      stack[top] = n;
  }
}


// Eliminar de la pila
int quita() {
  int item;
  if (top == -1)
    printf ("-----Sin elementos----\n");
  else{
    item = stack[top];
    top--;
  }
  return item;
}


//Mostar si el arreglo esta lleno
void lleno(){
  int i;
  if (top == N - 1){
    printf ("----La pila esta llena----\n");
    return;
  } else {
    printf ("----No esta llena y contiene: \n");
    for (i = top ; i >= 0 ; i--)
    printf ("%d\n", stack[i]);
  }
  
}

//Mostar si el arreglo esta vacio

void vacio(){
  int i;
  if(top == -1) {
    printf ("----La pila esta vacia\n");
    return;
  } else {
    printf ("----No esta vacia y contiene: \n");
    for (i = top ; i >= 0 ; i--)
    printf ("%d\t", stack[i]);
  }
  
}

//Imprimir lo que incluye el arreglo
void imprimir(){
  int i;
  for (i = top ; i >= 0 ; i--) {
    printf ("%d\t", stack[i]);
  }
  printf ("\n\n");
}


int main() {
  int ch, n;
  do {
    printf ("Ingresa la opción:\n1-Inserta Pila\n2-Elimina Pila\n3-Lleno\n4-Vacio\n5-Imprimir\n0-Salir\n\n");
    scanf ("%d", &ch);
    switch(ch) {
      case 1:
        printf ("Numero a ingresar: ");
        scanf ("%d", &n);
        pon(n);
        break;
      case 2:
            quita();
      break;
      case 3:
            lleno();
      break;
      case 4:
            vacio();
      break;
      case 5:
            imprimir();
      break;
      case 0:
      break;
      default:
      printf ("Invalido");
    }
  } while (ch != 0);
  return 0;
}
