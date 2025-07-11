#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y) {
    pair_t p = malloc(sizeof(struct s_pair_t));
    p->fst = x;
    p->snd = y;
    return p;
}

int pair_first(pair_t p) {
    return (p->fst);
}    

int pair_second(pair_t p)  {
    return (p->snd);
}    

pair_t pair_swapped(pair_t p) {
    pair_t q = pair_new(p->snd, p->fst);
    
    return q;
}    
 
pair_t pair_destroy(pair_t p) {
    return p;
}



