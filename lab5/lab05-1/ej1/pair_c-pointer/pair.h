#ifndef _PAIR_H
#define _PAIR_H

typedef struct s_pair_t * pair_t;
// El encapsulamiento es intentar lo menor posible de codigo oalgoi asi. Es que solo con la implementacion los demas puedan leer y entender el codigo sin saber como esta especificado.
// POrlo tanto lo que esta debajo rompe esa encapsulacion, no es necesario agregar la definicion de s_pair_t, sino que puedo colocarlo directamente en el ".c"
struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y);
/*
 * DESC: Creates a new pair with components (x, y)
 *
 */

int pair_first(pair_t p);
/*
 * DESC: Returns the first component of p
 *
 */

int pair_second(pair_t p);
/*
 * DESC: Returns the second component of p
 *
 */

pair_t pair_swapped(pair_t p);
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 */

pair_t pair_destroy(pair_t p);
/*
 * DESC: Free memory if its necessary
 *
 */


#endif
