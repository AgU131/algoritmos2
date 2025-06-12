#include <stdio.h>
#include <stdlib.h>

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
    Node *n0 = malloc(sizeof(Node)); 
    Node *n1 = malloc(sizeof(Node)); 
    Node *n2 = malloc(sizeof(Node)); 

    n0->data = 0;
    n1->data = 10;
    n2->data = 20;
    
    n2->next = n1;
    n1->next = n0;
    n0->next = NULL;

    return n2;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    show_list(my_list);

    // free(my_list);
    
    return 0;
}
