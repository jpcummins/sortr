#include "includes.h"

static void heapify(void* array[], size_t index, size_t max, int (*cmp)(void*, void*)) {
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < max && (*cmp)(array[left], array[index]) > 0) {
        largest = left;
    }
    if (right < max && (*cmp)(array[right], array[largest]) > 0) {
        largest = right;
    }
    if (largest != index) {
        swap(&array[largest], &array[index]);
        heapify(array, largest, max, cmp);
    }
}

static void build_heap(void* array[], size_t size, int (*cmp)(void*, void*)) {
    size_t i;
    for (i = (size / 2) - 1; i >= 0; i--) {
        heapify(array, i, size, cmp);
    }
}

void heap_sort(void* array[], size_t size, int (*cmp)(void*, void*)) {
    size_t i;
    build_heap(array, size, cmp);
    for (i = size - 1; i >= 1; i--) {
        swap(&array[0], &array[i]);
        heapify(array, 0, i, cmp);
    }
}
