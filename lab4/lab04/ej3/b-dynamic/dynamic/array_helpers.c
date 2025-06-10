#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>



void array_dump(int a[], size_t length) {
    fprintf(stdout, "length: %lu\n", length);
    fprintf(stdout, "[ ");
    for (size_t i = 0u; i < length; ++i) {
        fprintf(stdout, "%d", a[i]);
        if (i < length - 1) {
            fprintf(stdout, ", ");
        }
    }
    fprintf(stdout, "]\n");
}


int * array_from_file(const char *filepath, size_t *length) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int i = 0u;
    unsigned int size = 0u;
    int res = 0;
    res = fscanf(file, " %u ", &size);
    if (res != 1) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    int *array=NULL;

    // COMPLETAR: - Reservar memoria para array
    //            - Cambiar el valor de *length para que contenga el tamaño del
    //              arreglo.
    array = malloc(sizeof(int) * size); //multiplicacion
    //Esto me dio copilot para entender como funciona
    //Aca multimplicamos The amount of memory requested is calculated by multiplying sizeof(int) (the number of bytes required to store a single integer on your system) by size (the number of elements you want in your array).
    //The result is a pointer to the first byte of the allocated memory block, which is then assigned to the variable array. After this line executes, array can be used as if it were an array of size integers. It's important to check if malloc returns NULL, which would indicate that the memory allocation failed. Also, remember to free the allocated memory with free(array) when it is no longer needed to avoid memory leaks.
    *length = size; //(size_t)size ??
    //This line assigns the value of size to the variable pointed to by length. In the context of the function, length is a pointer to a size_t variable provided by the caller. By writing *length = size;, the function updates the caller's variable to reflect the number of elements in the array that was just read from the file.
    //The comment (size_t)size ?? suggests a question about whether an explicit type cast is needed. size is declared as an unsigned int, while *length is a size_t. Although both types are unsigned and often have the same size, they are not guaranteed to be identical on all systems. For maximum portability and to avoid potential warnings or errors, it is good practice to cast size to size_t when assigning it to a size_t variable, like this: *length = (size_t)size;.


    if (size > 0 && array == NULL) {
        fprintf(stderr, "Not enough memory\n");
        exit(EXIT_FAILURE);
    }
    while (i < size) {
        res = fscanf(file," %d ", &(array[i]));
        if (res != 1) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
       ++i;
    }
    fclose(file);
    return array;
}

