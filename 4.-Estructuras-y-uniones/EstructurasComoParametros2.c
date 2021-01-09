
/* Estructuras como parametros por punteros */
#include <stdio.h>
#include <math.h>


struct coordenadas 
{
    float x;
    float y;
    float z;
};



/* Definición de función que calcula la distancia entre dos puntos */
float distancia(struct coordenadas *a_ptr, struct coordenadas *b_ptr) 
{
    return sqrtf(pow(a_ptr->x - b_ptr->x, 2.0) + 
                 pow(a_ptr->y - b_ptr->y, 2.0) + 
                 pow(a_ptr->z - b_ptr->z, 2.0));
}

int main() 
{
    /* Declaración e inicialización de dos variables */
    struct coordenadas punto_a = { 3.5e-120, 2.5, 1.5 };
    struct coordenadas punto_b = { 5.3e-120, 3.1, 6.3 };
    float d; /* Almacenar el resultado */

    /* Llamada a la función con las dos estructuras */    
    d = distancia(&punto_a, &punto_b);
    /* Imprimir el resultado */
    printf("%f\n", d);

    return 0;
}

/*El uso de punteros ofrece una alternativa más eficiente.
*Con esta nueva versión, el programa ejecuta exactamente los mismos cálculos, obtiene el mismo resultado, pero su ejecución es más rápida, y utiliza menos memoria.
*/
