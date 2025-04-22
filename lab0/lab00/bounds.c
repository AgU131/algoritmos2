#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    // TODO: COMPLETAR

    bool is_upper = true;
    bool is_lower = true;
    bool exists = false;
    res.where = 0;


    // Comprobar si el valor es un upperbound
    for (unsigned int i = 0; i < length; i++) {
        is_upper = is_upper && (arr[i] <= value);
        // if (arr[i] >= value) {
        //     is_upper = true;
        // }
        
        // Comprobar si el valor es un lowerbound
        is_lower = is_lower && (arr[i] >= value);
        // if (arr[i] <= value) {
        //     is_lower = true;
        // }

        // Comprobar si el valor existe en el array y dar el indice donde esta
        exists = exists || (arr[i] == value);
        if (arr[i] == value) {
            res.exists = true;
            res.where = i;
        }
    }

    res.is_upperbound = is_upper;
    res.is_lowerbound = is_lower;
    res.exists = exists;      

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    // TODO: COMPLETAR - Pedir entrada al usuario
    // int i = 0;
    // int b[ARRAY_SIZE], valor;
    // while (i < ARRAY_SIZE)
    // {
    //     printf("ingrese el valor %i del arreglo:\n");
    //     scanf("%d", &a[i]);
    //     i++;
    // }
    // printf("ingrese el valor:\n");
    // scanf("%d", &valor);


    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("is_upperbound = %d\n", result.is_upperbound); // Imprime 1
    printf("is_lower = %d\n", result.is_lowerbound); // Imprime 0
    printf("exists = %u\n", result.exists);        // Imprime 1
    printf("where = %u\n", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

