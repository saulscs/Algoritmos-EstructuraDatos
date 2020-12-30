//Uniones

#include <stdio.h>
#include <string.h>

/*Creamos una union*/
union frases 
{
	char mensajes[50];
	char ayudas[50];
	char lineas[50];
} palabra;

/*Creamos una estructura*/
struct comparte
{
	char mensajes[50];
	char ayudas[50];
	char lineas[50];
}Sistema;

/*Nótese que la estructura y la union tienen los mismos tipos de datos*/

int main(int argc, char** argv)
{
	/*Inicializamos*/
	strcpy(palabra.mensajes, "Primer Mensaje");
	
	/*Inicializamos*/
	strcpy(palabra.ayudas, "Una Ayuda");
	
	printf("\nFrases en Union: ");
	
	/*Imprimimos mensajes de union*/
	printf("\n1- %s", palabra.mensajes);
	
	/*Imprimimos ayudas de union*/
	printf("\n2- %s", palabra.ayudas);
	
	/*Inicializamos*/
	strcpy(Sistema.mensajes, "Primer Mensaje");
	
	/*Inicializamos*/
	strcpy(Sistema.ayudas, "Una Ayuda");
	
	/* Podemos notar que aunque inicializamos los valores 
	 * al imprimir se tiene el mismo valor para cada miembro 
	 * de la estructura, esto se debe a que las uniones usan el 
	 * mismo espacio de memoria para todos los elementos 
	 * de la union, siendo del tamaño de su miembro de 
	 * mayor tamaño, en este caso 50 bytes. 
	 * Entonces los tres miembros creados dentro de la 
	 * union comparten esos 50 bytes.
	 * Entonces el ultimo valor agregado a la union es 
	 * el que se tiene.
	 */
	
	printf("\n\nFrases en Struct: ");
	
	/*Imprimimos mensajes de struct*/
	printf("\n1- %s", Sistema.mensajes);
	
	/*Imprimimos ayudas de union*/
	printf("\n2- %s", Sistema.ayudas);
	
	/* En la estructura comparte, se reservan 150 bytes 
	 * de memoria para los tres miembros, en este caso 
	 * cada uno es independiente en memoria, asi pues se 
	 * puede inicializar cada uno o usar como un campo 
	 * independiente.
	 */
	
	return 0;
}
