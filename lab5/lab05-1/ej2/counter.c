#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c = malloc(sizeof(counter));
    (c->count) = 0;

    return c;
}

void counter_inc(counter c) {
    ++(c->count);   // c->count += 1; tambien esta bien
}

bool counter_is_init(counter c) {
    return (c->count == 0);
}

void counter_dec(counter c) {
    //Me aseguro que counter no este en su pos inicial antes de decrementar
    assert(!counter_is_init(c));
    --(c->count);   // c->count -= 1; tambien esta bien
}

counter counter_copy(counter c) {
    counter d = NULL;
    d = counter_init();
    d->count = c->count;

    return d;
}

void counter_destroy(counter c) {
    free(c);
    //c = NULL;     // Opcional
}
