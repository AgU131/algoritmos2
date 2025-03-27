#include <stdio.h>
#include <stdlib.h>

#include "fixstring.h"

#define N_WORDS 4

// Para probar puedo usar este archivo, sobreescribir el titulo del main original para que no se ejecute y crear otro main con menos cosas para probar las funciones que voy haciendo
int main(void) {
    fixstring words[N_WORDS]={"hola", "mundo", "auto","automovil"};

    printf("Probando fstring_length()\n"
           "-------------------------\n\n");

    for (int i=0; i < N_WORDS; i++) {
        printf("La longitud de '%s' es %u\n",
                words[i],
                fstring_length(words[i]));
    }

    printf("\n"
           "Probando fstring_eq() y fstring_less_eq()\n"
           "-----------------------------------------\n\n");

    for (int i=0; i < N_WORDS; i++) {
        for (int j=0; j < N_WORDS; j++) {
            if (fstring_eq(words[i], words[j])) {
                printf("Los strings '%s' y '%s' son iguales\n",
                        words[i], words[j]);
            }
            printf("El string '%s' va %s alfabeticamente que '%s'\n\n", 
                   words[i],
                   fstring_less_eq(words[i], words[j]) ? "antes": "despues",
                   words[j]);
        }
    }
    return EXIT_SUCCESS;
}

