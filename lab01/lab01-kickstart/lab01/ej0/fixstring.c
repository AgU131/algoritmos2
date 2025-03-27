#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "fixstring.h"



unsigned int fstring_length(fixstring s) {
    unsigned int res = 0;
    int i = 0;
    bool final_encontrado = false;

    while (!(final_encontrado)) {
        if (s[i] == '\0') {
            final_encontrado = true;
        } else {
            res++;
        }
        i++;
    }
    
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool son_iguales = true;
    unsigned int tam1 = fstring_length(s1);
    if (tam1 == fstring_length(s2)) {
        while (i < tam1) {
            if (s1[i] != s2[i]) {
                son_iguales = false;
            }
            i++;
        }
    } else {
        son_iguales = false;
    }
    
    return son_iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool es_menor_ig = true;
    unsigned int tam1 = fstring_length(s1);

    while (i < tam1) {
        es_menor_ig = es_menor_ig && (s1[i] <= s2[i]);
        // if (tam1 <= fstring_length(s2)) {
        // } else {

        // }
        
        i++;
    }
    return es_menor_ig;
} 
/*
*/


int main(){
    // char cadena[]="hola mundo !";
    fixstring a = "hola1233";
    fixstring b = "hola123";

    printf("tamano: %u \n", fstring_length(a));
    printf("equivalente: %d\n"
        "[1 = true y 0 = false]\n",
        fstring_eq(a, b));
    printf("s1 es menor o igual: %d \n", fstring_less_eq(a, b));
        
    return 0;
}
