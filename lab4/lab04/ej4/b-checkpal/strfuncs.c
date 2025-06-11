#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "strfuncs.h"


size_t string_length(const char *str) {
    // return sizeof(str);   esto no funciona, porque  sizeof  devuelve el tamaño del puntero, no de la cadena.
    size_t len = 0;   // esl size_t es como un unsigned int
    while (str[len] != '\0') {
            len++;
    }
    return len;
}
/*
calcula la longitud de la cadena apuntada por str
*/

char *string_filter(const char *str, char c) {
    size_t length = string_length(str);
    char *str2 = NULL;
    str2 = malloc((sizeof(char) * length) + 1); //Le sumo 1 por el "\0"
    size_t i = 0, j = 0;
    while (i < length && str[i]!='\0') {
        if (str[i] != c) {
            str2[j] = str[i];
            j++;
        }
        i++;
    }

    return str2;
}
/*
devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str 
que son distintos del caracter c
*/

bool string_is_symmetric(const char *str) {
    size_t length = string_length(str);
    size_t i = 0, j = length - 1;
    while ((i < j) && (str[j] == str[i])) {
            j--;
            i++;
    }

    return str[j] == str[i];
    
    //Correccion chatgpt

    // bool es_simetrica = true;
    // while (i < j && es_simetrica) {
    //     if (str[i] != str[j]) {
    //         es_simetrica = false;
    //     }
    //     i++;
    //     j--;
    // }
    // return es_simetrica;
}
/*
indica si la cadena apuntada por str es simétrica en cuanto que el primer caracter coincide con el 
último, el segundo con el penúltimo, etc; como por ejemplo las cadenas "aba", "abcba", "a", "". 
*/
