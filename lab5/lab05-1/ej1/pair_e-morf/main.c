#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

static
void show_pair(pair_t p) {
    printf("(%d, %d)\n", pair_first(p), pair_second(p));
}

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


    
    //Nuvo ejemplo de Polimorfirsmo:
    pair_t r, s;
    // Nuevo par p
    r = pair_new('a', 'x');

    // Se muestra el par por pantalla
    printf("r = ");
    show_pair(r);

    // Nuevo para q con elementos de p intercambiados
    s = pair_swapped(r);

    // Se vuelve a mostrar p
    printf("r = ");
    show_pair(r);

    // Se muestra s
    printf("s = ");
    show_pair(s);

    // Se destruyen r y s
    r = pair_destroy(r);
    s = pair_destroy(s);


    return EXIT_SUCCESS;
}
