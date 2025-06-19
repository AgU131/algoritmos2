#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include "fixstring.h"


unsigned int fstring_length(fixstring s) {
    int i = 0;
    while (s[i] != '\0') {
            i++;
    }
    
    return i;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    int i = 0;
    bool son_iguales = true;

    while ((s1[i] == s2[i]) && (s1[i] != '\0')) {
        i++;
    }
    son_iguales = (s1[i] == s2[i]);

    return son_iguales;
}
    // Consejo del profe desacerme de los casos particulares (sacar ese if por excasos casos):
    // if (tam1 == fstring_length(s2)) {while...} else {son_iguales = false;}


bool fstring_less_eq(fixstring s1, fixstring s2) {
    int i = 0;
    
    while ((s1[i] == s2[i]) && (s1[i] != '\0')) {
        i++;
    }

    return (s1[i] <= s2[i]);
}

// Aca tenia el error de ir comparando por caracter a caracter y si habia alguno que era menor o ig que el otro me daba true,
// sin importar del primer caracter que era lo mas importante, de ahi daba mal en los ejemplos "aola" y "chau"

// Error. me dio false con "hal\0" y "hal\0". Arregle el predicado final agregandole lo de los tamaños para arreglarlo
// FALSE esta mal ESTE ERROR

//Uncomment cuando quiera probar fixSolo
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
