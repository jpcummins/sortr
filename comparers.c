#include "includes.h"

int int_compare(void* a, void* b) {
    int* x = a;
    int* y = b;
    
    if (*x == *y)
        return 0;
    
    if (*x > *y)
        return 1;
    else
        return -1;
}
