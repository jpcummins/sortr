#pragma once

#include <stdio.h>
#include <stdlib.h>

extern int int_compare(void* a, void* b);

extern void swap(void** a, void** b);

extern void test_int_sort(void (*sort)(void**, size_t, int (*cmp)(void*, void*)),
                          int* array, size_t size, const char* message);

extern void insert_sort(void* array[], size_t size, int (*cmp)(void*, void*));

extern void bubble_sort(void* array[], size_t size, int (*cmp)(void*, void*));
