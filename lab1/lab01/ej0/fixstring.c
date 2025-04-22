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
    unsigned int i = 0;
    bool son_iguales = true;
    unsigned int tam1 = fstring_length(s1);
    while (i < tam1 && son_iguales) {

        if (s1[i] != s2[i]) {
            son_iguales = false;
        }
        i++;
    }
    
    return son_iguales;
}
    // Consejo del profe desacerme de los casos particulares (sacar ese if por excasos casos):
    // if (tam1 == fstring_length(s2)) {while...} else {son_iguales = false;}


bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    unsigned int tam1 = fstring_length(s1);
    unsigned int tam2 = fstring_length(s2);
    
    while ((s1[i] == s2[i]) && (s1[i] != '\0')) {
        i++;
    }

    return (s1[i] <= s2[i]);
} 

// Aca tenia el error de ir comparando por caracter a caracter y si habia alguno que era menor o ig que el otro me daba true,
// sin importar del primer caracter que era lo mas importante, de ahi daba mal en los ejemplos "aola" y "chau"

// Error. me dio false con "hal\0" y "hal\0". Arregle el predicado final agregandole lo de los tamaños para arreglarlo
// FALSE esta mal ESTE ERROR


// int main() {
//     fixstring a = "alessss";
//     fixstring b = "halesss";

//     printf("tamano: %u \n", fstring_length(a));
//     printf("equivalente: %d\n"
//         "[1 = true y 0 = false]\n",
//         fstring_eq(a, b));
//     printf("s1 es menor o igual: %d \n", fstring_less_eq(a, b));
        
//     return 0;
// }
