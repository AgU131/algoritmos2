#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

// typedef list_elem elem;

struct node{
    list_elem elem;
    struct node *next;
};


/* Constructors */
list empty(void) {

}

list addl(list l, list_elem e) {
    
}
/*
{- agrega el elemento e al comienzo de la lista l. -}
*/

list destroy(list l){
    free(l);
    return l = NULL;
}

/* Operations */
bool is_empty(list l);
/*
{- Devuelve True si l es vacía. -}
*/

list_elem head(list l);
/*
{- Devuelve el primer elemento de la lista l -}
{- PRE: not is_empty(l) -}
*/

list tail(list l);
/*
{- Elimina el primer elemento de la lista l -}
{- PRE: not is_empty(l) -}
*/

list addr(list l, list_elem e);
/*
{- agrega el elemento e al final de la lista l. -}
*/

list_length length(list l);
/*
{- Devuelve la cantidad de elementos de la lista l -}
*/

list concat(list l1, list l2);
/*  
{- Agrega al final de l todos los elementos de l0
en el mismo orden.-}
*/

list_elem index(list l, list_index n);
/*  
{- Devuelve el n-ésimo elemento de la lista l -}
{- PRE: length(l) > n -}
*/

list take(list l, list_index n);
/*
{- Deja en l sólo los primeros n
elementos, eliminando el resto -}
*/

list drop(list l, list_index n){

}
/*
{- Elimina los primeros n elementos de l -}
*/

list copy_list(list l);
/*
{- Copia todos los elementos de l1 
*/


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
proc addl (in e : T, in/out l : List of T)
var p : pointer to (Node of T)
alloc(p)
p->elem := e
p->next := l
l := p
end proc

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
    //no hace falta liberar mada mas porque lo demas es memoria estatica
    return NULL;
}