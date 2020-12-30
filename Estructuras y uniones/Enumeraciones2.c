//Uniones 2

#include <stdio.h>

enum DiasSemanas
{
	Domingo = 1,
	Lunes,
	Marte,
	Miercoles,
	Jueves,
	Viernes,
	Sabado
};
/* Podemos inicializar nuestra primer constante Domingo
 * en 2, asi pues las demas los siguientes valores enteros.
 */

int main(int argc, char** argv)
{

	enum DiasSemanas dia;

	for (dia = Domingo; dia <= Sabado; dia++)
	{
		printf("%d ", dia); /* Salida: 1 2 3 4 5 6 7  */
	}

	return 0;
}