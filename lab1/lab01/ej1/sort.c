#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) {
    /* needs implementation */
    unsigned int j = i;
    while (j > 0 && goes_before(a[j], a[j - 1])) {
        swap(a, j, j - 1);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        insert(a, i, length);
    }
    assert(array_is_sorted(a, length));
}

int _main()
{
    int a[] = {5, 2, 9, 1, 5, 6};
    unsigned int length = 6;
    printf("Before sorting: ");
    array_dump(a, length);
    insertion_sort(a, length);
    printf("After sorting: ");
    array_dump(a, length);

    return 0;
}
