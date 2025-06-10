#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",  
           sizeof(messi.name), 
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height));

    /*     COMPLETAR     */

    name_t *r = NULL;
    unsigned *p = NULL;
    data_t *q = NULL;
    
    printf("\nDirecciones de Memoria:\n");
    r = &messi.name;
    printf("Direccion de name-size: %p\n", (void *) r);
    p = &messi.age;
    printf("Direccion de age-size: %p\n", (void *) p);
    p = &messi.height;
    printf("Direccion de height-size: %p\n", (void *) p);
    q = &messi;
    printf("Direccion total de data_t-size: %p\n", (void *) q);

    return EXIT_SUCCESS;
}
