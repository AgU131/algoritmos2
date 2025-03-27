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

    while (son_iguales) {
        if (s1[i] != s2[i]) {
            son_iguales = false;
        }
        i++;
    }
    
    return son_iguales;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool es_menor = false;

    // while () {
        
    //     i++;
    // }

    // return ;
} 
