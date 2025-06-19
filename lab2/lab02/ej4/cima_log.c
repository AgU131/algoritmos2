#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */



static int cima_rec(int a[], int lft, int rgt) {
    int mid;
    int cima;
    mid = (lft + rgt) / 2;
    
    //
    // bool es_cima;
    // bool izq_cima;
    // es_cima = ( (mid == 0 || a[mid] > a[mid - 1]) &&
    //             (mid == rgt || a[mid] > a[mid + 1]) );
    // izq_cima = (mid > 0 && a[mid - 1] > a[mid]);

    if (es_cima(a,mid,rgt)) {
        cima = mid;
    } else if (izq_cima(a, mid)) {
        cima = cima_rec(a, lft, mid - 1); // La cima está en la parte izquierda, llamamos recursivamente a la mitad izquierda
    } else if (der_cima(a, mid)) {
        cima = cima_rec(a, mid + 1, rgt);  // La cima está en la parte derecha, llamamos recursivamente a la mitad derecha
    }

    return cima; 
}

int cima_log(int a[], int length) {
    return cima_rec(a, 0, length - 1);
}

bool es_cima(int a[], int i, int rgt) {
    return((i == 0 || a[i] > a[i - 1]) && (i == rgt || a[i] > a[i + 1]));
}
bool izq_cima(int a[], int i) {
    return (i > 0 && a[i - 1] > a[i]);
}
bool der_cima(int a[], int i) {
    return (i > 0 && a[i - 1] > a[i]);
}