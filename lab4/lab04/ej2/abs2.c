#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    *y = x;
    if (*y < 0) {
        *y = -x;  // Si x es negativo, asigna -x a y
    }
}

int main(void) {
    int a=-100, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    printf("res antes de absolute = %d\n", res);
    printf("a = %d\n", a);

    absolute(a, &res);

    printf("res = %d\n", res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

