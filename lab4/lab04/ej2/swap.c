#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
Ejercicio Traducir:
proc swap(in/out a : int, in/out b : int) 
    var aux : int 
    aux := a 
    a := b 
    b := aux  
end proc 
fun main() ret r : int 
  var x, y : int 
  x := 6 
  y := 4 
  print(x, y) 
  swap(x, y) 
  print(x, y) 
  r := 0 
end fun
*/

void swap (int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
int main(void) {
    int x=6, y=4;
    printf("\nx = %d,\ny = %d\n", x, y);   //Variables antes del swap
    swap(&x, &y);
    printf("\nx = %d,\ny = %d\n", x, y);   //Variables despues del swap
    
    return EXIT_SUCCESS;
}
