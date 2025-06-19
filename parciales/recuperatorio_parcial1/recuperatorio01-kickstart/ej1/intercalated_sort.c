#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "intercalated_sort.h"

//Funcion que intercambia los valores de 2 lugares de un arreglo
void swap(int a[], int i, int j) {
    int aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

//Funcion que comprueba que una posicion par del arreglo sea mayor a sus anteriores posiciones pares
//Y de ser mayor las intercambia con el anterior valor par posible
void insert(int a[], int i) {
    int j = i;
    while (j > 0 && a[j] < a[j-2]) {
        swap(a, j-2, j);
        j = j-2;
    }
}

/**
 * @brief Ordena las posiciones pares del arreglo (0-based)
 * usando el algoritmo de ordenación por inserción.
 */
void intercalated_sort(int a[], int length) {
    //Recorre el arreglo en posiciones par, desde la 2 posicion par posible (2)
    for (int i = 2; i < length; i = i + 2) {
        insert(a, i);
    }
}

