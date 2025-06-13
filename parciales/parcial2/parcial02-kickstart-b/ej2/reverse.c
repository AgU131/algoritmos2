#include "reverse.h"
#include <stdio.h>

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de invertir
 * el orden de los elementos de `l`
 *
 */
list reverse(list l) {
    int i = 0;
    //Creamos una nueva lista p 
    list p = empty();
    while (i < length(l) && !is_empty(l)) {
        //le añadimos los elem de l, 1 a 1 por la izquierda
        p = addl(index(l, i), p);
        i++;
    }
    return p;
}


/*
Al añadirle los elem por la izquierda, 
tenemos que vamos creando una lista que agarra desde el primer elem de l
y lo agrega desde la izquierda a la nueva lista p
entonce ira agregando los elementos seguidos pero al revez de su orden original

Ej.:
l = [1,2,3,4]
p --> [], añado por la izquierda el primer elem de l
p --> [1] 
p --> [2,1] 
p --> [3,2,1] 
p --> [4,3,2,1] 
fin Ej
*/ 