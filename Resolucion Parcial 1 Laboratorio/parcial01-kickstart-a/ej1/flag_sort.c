#include "flag_sort.h"

void swap(color_t a[], int i, int j);

/**
 * @brief Ordenar un arreglo de tres colores RED, WHITE y BLUE.
 *
 * Dado un arreglo cuyos elementos son tres colores posibles RED, WHITE y BLUE,
 * ordenarlos de manera que queden todos los RED primero, después todos los 
 * WHITE y al final todos los BLUE, formando la bandera de Córdoba.
 * 
 * @param a Arreglo de colores.
 * @param length Largo del arreglo.
 */


// invariante:
// 0 <= i <= j <= k <= length-1
void flag_sort(color_t a[], int length) {
    int i = 0;
    int j = 0;
    int k = length-1;
    while (j <= k) {
        if (a[j] == red) {
            swap(a, i, j);
            i++;
            j++;
        } else if (a[j] == blue) {
            swap(a, j, k);
            k--;
        } else if (a[j] == white) {
            j++;
        } 
    }
}


void swap(color_t a[], int i, int j) {
    color_t tmp = a[i]; 
    a[i] = a[j]; 
    a[j] = tmp;
}
//Pruebasextras
// swap ({blue, red, blue, white}, 0, 0)
//temp = blue
//