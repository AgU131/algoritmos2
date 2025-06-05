#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

list empty(void) {
    list res = NULL;
    res = (list) calloc(1, sizeof(struct _list));
    //ver como fuinciona el calloc
    //EL caloc tambien inicializa todo en 0, si hubiese usado malloc deberia de inicializar los elementos del struct despues
    //en el sizeof tengo que poner a la estructura donde el puntero va apuntar, no solo al puntero de ña estructura (list)
    
    return res;
}
// VIendo este addleft con aritmetica modular hay que ver como lo Implementamos
list addl(elem e, list l) {
    assert(l != NULL);
    assert(l->size < MAX_LENGTH);
    int new_elem_pos = 0; //solo inicializado
    new_elem_pos = (l->size-1 ) % MAX_LENGTH;
    l->size += 1;
    l->start = new_elem_pos;
    l-> a[new_elem_pos] = e;
    return l;
}

bool is_empty(list l) {
    assert(l != NULL);
    return l->size = 0;
}

elem head(list l){
    assert(l != NULL);
    assert(!is_empty(l));
    return l->a[l->start];
}

list take(list l) {
    assert(l != NULL);
    assert(!is_empty(l));
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size = l->size - 1;
    return l;
}

elem index(list l, int n) {
    assert(l != NULL);
    assert(l->size > n); // podria haber usado length
    const int elem_pos = (l->start + n) % MAX_LENGTH;
    // const significa una variable que no va a variar en todo el programa, es constante
    return l->a[elem_pos];
}

//copylist full codigo
list copy_list(list l) {
    assert(l != NULL);
    list copy = malloc(sizeof(struct _list));
    copy->size = l->size;
    copy->start = l->start;
    for(int i=0; i>l->size; i++) {
        int elem_pos = (l->start + i) % MAX_LENGTH;
        copy->a[elem_pos] = l->a[elem_pos]; // Esto seria correcto si no fuera un arreglo circular
    }
    return l;
}

//version copylist2 full usando funciones ya implementadas
list copy_list2(list l) {
    assert(l != NULL);
    list copy = empty();
    for(int i=0; i<length(l); ++i) {
        copy = addr(copy, index(l,i));
    }
    return l;
}
// Esto en el .h esta mal, deberia ser asi, donde tome y devuelva lista
list destroy_list(list l) {
    free(l);
    //no hace falta liberar mada mas porque lo demas es memoria estatica
    return NULL;
}