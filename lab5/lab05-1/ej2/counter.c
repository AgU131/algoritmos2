#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter n = NULL;
    n = malloc(sizeof(counter));
    n->count = 0;

    return n;
}

void counter_inc(counter c) {
    c->count += 1;
}

bool counter_is_init(counter c) {
    return (c->count == 0);
}

void counter_dec(counter c) {
    assert(!(counter_is_init(c)));  //Me aseguro que counter no este en su pos inicial antes de decrementar
    c->count -= 1;
}

counter counter_copy(counter c) {
    counter n = NULL;
    n = malloc(sizeof(counter));
    n->count = c->count;

    return n;
}

void counter_destroy(counter c) {
    free(c);
    c = NULL;
}
