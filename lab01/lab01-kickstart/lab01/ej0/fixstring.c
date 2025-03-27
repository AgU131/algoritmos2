#include <stdbool.h>
#include <stdio.h>

#include <assert.h>

#include "fixstring.h"



unsigned int fstring_length(fixstring s) {
    unsigned int res = 0;
    bool final_encontrado = false;

    while (!(final_encontrado)) {
        if (s[res] == '\0') {
            final_encontrado = true;
        } else {
            res++;
        }
    }
    
    return res;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool son_iguales = true;
    unsigned int tam1 = fstring_length(s1);
    if (tam1 == fstring_length(s2)) {       // consejo del profe desacerme de los casos particulares (sacar ese if por excasos casos)
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
    bool es_menor_ig = false;
    unsigned int tam1 = fstring_length(s1);
    unsigned int tam2 = fstring_length(s2);
    
    // while (i < tam1) {
    while (s1[i] <= s2[i]) {
        // es_menor_ig = es_menor_ig && (s1[i] <= s2[i]);
        // if (tam1 <= fstring_length(s2)) {
        // } else {
        // }
        es_menor_ig = true;
        i++;
    }
    return es_menor_ig;
} 
/*
*/



int main(){
    // char cadena[]="hola mundo !";
    // fixstring a = "hola1233";
    // fixstring b = "ola123323232";
    fixstring a = "aola";
    fixstring b = "chau";

    printf("tamano: %u \n", fstring_length(a));
    printf("equivalente: %d\n"
        "[1 = true y 0 = false]\n",
        fstring_eq(a, b));
    printf("s1 es menor o igual: %d \n", fstring_less_eq(a, b));
        
    return 0;
}
