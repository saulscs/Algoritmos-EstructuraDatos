//Enumeraciones

#include <stdio.h>

enum Boolean
{
	FALSE, TRUE
};

/* Se define un enum para emular las constantes 
 * True y False con valores de 0 y 1. 
 * Notese que las enum no necesitan ; al final 
 * de cada tipo de dato.
 */

/* Definimos una funcion del tipo enum llamada numero*/
enum Boolean numero(char c);

int main(int argc, char** argv)
{
	char caracter;
	int Numeros = 0;
	
	printf("\nIntroduce un numero de hasta 9 digitos. Para terminar: Enter. \n\t");
	
	/* Tenemos un while que mientras no se presione Enter 
	 * seguira leyendo un tipo de dato caracter
	 */
	while((caracter = getchar()) != '\n')
	{
		if (numero(caracter))
		{
			Numeros++;
		}
	}
	printf("\nTotal de Numeros leidos: %d", Numeros);
	
	return 0;
}

enum Boolean numero(char c)
{
	switch(c)
	{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return TRUE;
		/* Mientras el caracter valga de 0 a 9 retornara TRUE (1) */
		default:
			return FALSE;
		/* Por default retornara FALSE (0) */
	}
}