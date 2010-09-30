#include "includes.h"

void insert_sort(void* array[], size_t size, int (*cmp)(void*, void*)) {
    size_t i, j;
    void* tmp;
    
    for (i = 1; i < size; i++) {
        j = i;
        tmp = array[i];
        while (j > 0 && (*cmp)(array[j - 1], tmp) > 0) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = tmp;
    }
}
