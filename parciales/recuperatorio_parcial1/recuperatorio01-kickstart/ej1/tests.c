#include <stdbool.h>
#include <stdio.h>
#include "intercalated_sort.h"

#define MAX_LENGTH 10
#define N_TESTCASES 23

bool equal_arrays(int a[], int b[], int length) {
    int i = 0;
    while (i < length && a[i] == b[i]) {
        i++;
    }
    return i == length;
}

int main() {
    // representación de un solo caso de test
    struct testcase {
        int n;                   // largo del arreglo a ordenar
        int a[MAX_LENGTH];       // elementos del arreglo a ordenar
        int result[MAX_LENGTH];  // resultado esperado: arreglo ordenado
    };

    // casos de test (uno por línea): { n, a, result }
    struct testcase tests[N_TESTCASES] = {
        // tests para sort intercalado
        { 0, { }, { } },
        { 1, {42}, {42} },
        { 2, {11, 42}, {11, 42} },
        { 2, {42, 11}, {42, 11} },
        { 3, {-10, 11, 42}, {-10, 11, 42} },
        { 3, {-10, 42, 11}, {-10, 42, 11} },
        { 3, {11, -10, 42}, {11, -10, 42} },
        { 3, {11, 42, -10}, {-10, 42, 11} },
        { 3, {42, -10, 11}, {11, -10, 42} },
        { 3, {42, 11, -10}, {-10, 11, 42} },
        { 4, {-10, 11, 42, 99}, {-10, 11, 42, 99} },
        { 4, {42, 11, -10, 99}, {-10, 11, 42, 99} },
        { 4, {42, -10, 99, 11}, {42, -10, 99, 11} },
        { 4, {11, 42, -10, 99}, {-10, 42, 11, 99} },
        { 5, {-10, 8, 11, 42, 99}, {-10, 8, 11, 42, 99} },
        { 5, {42, 8, 11, 99, -10}, {-10, 8, 11, 99, 42} },
        { 5, {11, 42, -10, 99, 8}, {-10, 42, 8, 99, 11} },
        { 5, {8, 42, 11, -10, 99}, {8, 42, 11, -10, 99} },
        // Ejercicio 1.2: cinco (5) Tests nuevos con al menos cinco (5) elementos
        { 5, {1, 2, -10, 999, 8}, {-10, 2, 1, 999, 8} },
        { 6, {8, 42, 1, -10, 99, 0}, {1, 42, 8, -10, 99, 0} },
        { 6, {42, 11, -10, -1, 11, 42}, {-10, 11, 11, -1, 42, 42} },
        { 7, {1, 2, 3, 4, 0, 11111, 0}, {0, 2, 0, 4, 1, 11111, 3} },
        { 8, {1, 919, 3, 4, 0, 101, -22, -1}, {-22, 919, 0, 4, 1, 101, 3, -1} },
    };

    printf("TESTING intercalated_sort\n");

    for (int i=0; i < N_TESTCASES; i++) {
        printf("Test case %i: ", i+1);

        // TEST! llamamos la función a intercalated_sort
        intercalated_sort(tests[i].a, tests[i].n);

        // comparamos resultado obtenido con resultado esperado
        if (equal_arrays(tests[i].a, tests[i].result, tests[i].n)) {
            printf("OK\n");
        } else {
            printf("FAILED\n");
        }
    }

    return 0;
}
