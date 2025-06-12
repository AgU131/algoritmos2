#ifndef LISTAS
#define LISTAS
#include <assert.h>
#include <stdbool.h>

/* 
Definimos un nuevos tipos:
1. para los elementos de la lista 
2. para el largo de la lista
3. para el indice de una lista
*/
typedef int list_elem;
typedef unsigned int list_length;
typedef unsigned int list_index;

/* Definimos la lista */
typedef struct node *list;


/* Constructors */
list empty(void);
/*
{- crea una lista vacía. -}
*/

list addl(list l, list_elem e);
/*
{- agrega el elemento e al comienzo de la lista l. -}
*/

list destroy(list l);
/*
{- Libera memoria en caso que sea necesario. -}
*/

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

list drop(list l, list_index n);
/*
{- Elimina los primeros n elementos de l -}
*/

list copy_list(list l);
/*
{- Copia todos los elementos de l1 
*/

#endif