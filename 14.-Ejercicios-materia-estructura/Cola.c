//
//  main.c
//  Cola
//
//  Created by saul corona on 02/02/22.
//

#include <stdio.h>
#include <stdlib.h>

//prototipos
void inserta (int);
int eliminar(void);
void lleno(void);
void vacio(void);
void imprimir(void);


//Variables globales
#define N 10
int queue[N];
int front = -1;
int rear = -1;

//Insertar a la cola
void inserta (int new_data) {
  if (rear == N - 1) {
    printf ("-----La cola esta llena----\n");
  }
  else if (front == -1 && rear == -1){
    front = 0;
    rear = 0;
    queue[rear] = new_data;
  }
  else {
    rear++;
    queue[rear] = new_data;
  }
}


// Eliminar de la cola
int eliminar(){
  int dequeued;
  if (front == -1 && rear == -1) {
    printf ("-----La cola esta vacia----\n");
  }
  else if (front == rear){
    dequeued = queue[front];
    front = -1;
    rear = -1;
  }
  else {
    dequeued = queue[front];
    front++;
  }
  return dequeued;
}


//Mostar si el arreglo esta lleno
void lleno(){
  if (rear == N-1) {
    printf ("----La Cola esta llena----\n");
  } else {
  printf("----La cola no esta llena y contiene: ");
    int i;
    for (i = front ; i <= rear ; i++) {
      printf ("%d\t", queue[i]);
    }
    printf ("\n");
  }
}


//Mostar si el arreglo esta vacio

void vacio() {
  if (front == -1 && rear == -1) {
    printf ("----La cola esta vacia----\n");
  }
  else {
    printf ("----La cola no esta vacia y contiene: \n");
    int i;
    for (i = front ; i <= rear ; i++) {
      printf ("%d\t", queue[i]);
    }
    printf ("\n");
  }
}

//Imprimir lo que incluye el arreglo
void imprimir(){
  int i;
  for (i = front ; i <= rear ; i++) {
  printf ("%d\t", queue[i]);
  }
  printf ("\n\n");
}


int main() {
  int ch, n;
  do {
    printf ("Ingresa una opcion:\n1-Inserta Cola\n2-Elimina cola\n3-Lleno\n4-Vacio\n5-Imprimir\n0-Salir\n\n");
    scanf ("%d", &ch);
    switch(ch) {
      case 1:
      printf ("Numero a ingresar: ");
      scanf ("%d", &n);
      inserta(n);
      break;
      case 2:
      eliminar();
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

