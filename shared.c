#include "includes.h"

void swap(void** a, void** b) {
    void* tmp = *a;
    *a = *b;
    *b = tmp;
}

static void** generate_pointer_array(void* array, size_t size, size_t element_size) {
    char** pointer_array = malloc(sizeof(char*) * size);
    char* char_array = (char*) array;
    size_t i;
    
    if (pointer_array == NULL) {
        return NULL;
    }
    
    for (i = 0; i < size; i++) {
        pointer_array[i] = &char_array[i * element_size];
    }
    
    return (void**) pointer_array;
}

static void test_sort(void (*sort)(void**, size_t, int (*cmp)(void*, void*)), 
                      int (*cmp)(void*, void*), 
                      void** array, 
                      size_t size, 
                      const char* message) {
    size_t i;
    
    (*sort)(array, size, cmp);
    
    if (size == 0 || size == 1) {
        return;
    }
    
    for (i = 1; i < size; i++) {
        if ((*cmp)(array[i - 1], array[i]) > 0) {
            printf("FAILED: %s\n", message);
            return;
        }
    }
    
    printf("PASSED: %s\n", message);
}

void test_int_sort(void (*sort)(void**, size_t, int (*cmp)(void*, void*)), 
                   int* array, 
                   size_t size, 
                   const char* message) {
    void** pointers = generate_pointer_array((void*) array, size, sizeof(int));
    test_sort(sort, int_compare, pointers, size, message);
    free(pointers);
}
