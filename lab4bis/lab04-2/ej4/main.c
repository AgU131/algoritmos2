#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    // COMPLETAR ACÁ!
    Node *n2 = malloc(sizeof(Node)); 
    Node *n1 = malloc(sizeof(Node)); 
    Node *n0 = malloc(sizeof(Node)); 

    n2->data = 20;
    n1->data = 10;
    n0->data = 0;
    
    n2->next = n1;
    n1->next = n0;
    n0->next = NULL;

    return n2;
}

/**
 * @brief Elimina el primer elemento de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
List tail_example(List xs) {
    // COMPLETAR ACÁ!
    assert(xs != NULL);
    List l = malloc(sizeof(Node));
    l = xs;

    xs = xs->next;

    free(l);

    return xs;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}


//Aca un extra: FREE de la lista completa y sus elementos
void free_list(List xs) {
    while (xs!=NULL) {
        List temp = xs;
        xs = xs->next;
        free(temp);
    }
}


int main(void) {
    List my_list;

    my_list = setup_example();

    printf("Lista antes del tail: ");

    show_list(my_list);

    my_list = tail_example(my_list);

    printf("Lista después del tail: ");

    show_list(my_list);


    //EXTRA
    free_list(my_list);


    return 0;
}
