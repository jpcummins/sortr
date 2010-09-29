#include "shared.c"

void bubble_sort(void* array[], size_t size, int (*cmp)(void*, void*)) {   
    size_t i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if ((*cmp)(array[i], array[j]) < 0) {
                swap(&array[i], &array[j]);
            }
        }
    }
}