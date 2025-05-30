#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

//aca no debo declarar el struct del pair.c porque romperia el encapsulamiento
static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
}  //aca debo utilizar las mismas funciones para declarar el primer y ultimo elemento
// ya que lo que habia hecho antes era declarar punteron, siendo que en teoria no sabria que esta implementado con punteros 
//ADEMAS debo complicar con gcc -Wall -Werror -Wextra -pedantic -std=c99 -c main.c pair.c pair.h

int main(void) { 
    pair_t p, q;

    // Nuevo par p
    p = pair_new(3, 4);

    // Se muestra el par por pantalla
    printf("p = ");
    show_pair(p);

    // Nuevo para q con elementos de p intercambiados
    q = pair_swapped(p);

    // Se vuelve a mostrar p
    printf("p = ");
    show_pair(p);

    // Se muestra q
    printf("q = ");
    show_pair(q);

    // Se destruyen p y q
    p = pair_destroy(p);
    q = pair_destroy(q);

    return EXIT_SUCCESS;
}
