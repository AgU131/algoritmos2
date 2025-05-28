/*
  @file main.c
  @brief Main program function implementation
*/
#include <stdio.h>
#include <stdlib.h>

/** @brief structure which represent a person */
typedef struct _person {
    int age;
    char name_initial;
} person_t;

/**
 * @brief Main program function
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(void) {

    int x = 1;
    person_t m = {90, 'M'};
    int a[] = {0, 1, 2, 3};

    /* Completar aquí:
       Al finalizar la ejecución las variables deben tener los siguientes valores
       x = 9
       m = (100, F)
       a[1] = 42

       Las restricciones son:
       - No usar las variables 'x', 'm' y 'a' en la parte izquierda de alguna asignación.
       - Se pueden agregar líneas de código, pero no modificar las que ya existen.
       - Se pueden declarar hasta 2 punteros.
       AYUDA: podes usar GDB para consultares valores de variables y la dirección de memoria donde estan alojadas.
    */
    
    //pruebas primero:
    /*
    int *p = &x;
    int *q = p;
    printf("el puntero p = %d\n", *p);
    printf("el puntero q = %d\n", *q);
    */
    //Resolucion:
    // Primero declaro e inicializo los punteros:
    int *p = NULL;
    char *q = NULL;

    //despues apunto los punteros a la direccion de la variable que quiero modificar
    //y modifico su valor
    p = &x;   // puntero p apunta a la direccion de x (apunta a su caja)
    *p = 9;  // puntero abre la caja y modifica lo que contenga x
    //ahora x = 10

    p = &a[1];   // apunto
    *p = 42;     // cambio el valor

    p = &m.age;
    *p = 100;
    
    q = &m.name_initial;
    *q = 'F';
    //done

    printf("x = %d\n", x);
    printf("m = (%d, %c)\n", m.age, m.name_initial);
    printf("a[1] = %d\n", a[1]);

    return EXIT_SUCCESS;
}

