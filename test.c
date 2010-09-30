#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes.h"

static void test_integers(void (*sort)(void**, size_t, int (*cmp)(void*, void*)), const char* sort_name) {
    int test1[] = {5, 4, 7, 2, 0, 5};
    int test2[] = {0, 0, 0, 0, 0, 0};
    int test3[] = {-5, -4, -7, -2, 0, -5};
    int test4[] = {1, 2, 0, -2, -1, 1};
    int test5[] = {1, 2, 3, 4, 5, 6};
    int test6[] = {5, 4, 3, 2, 1, 0};
    char message[80];
    int message_length;
    
    message_length = snprintf(message, sizeof(message), "%s: Test case X", sort_name);
    
    /* Test case 1 */
    message[message_length - 1] = '1';
    test_int_sort(sort, test1, 6, message);
    
    /* Test case 2 */
    message[message_length - 1] = '2';
    test_int_sort(sort, test2, 6, message);
    
    /* Test case 3 */
    message[message_length - 1] = '3';
    test_int_sort(sort, test3, 6, message);
    
    /* Test case 4 */
    message[message_length - 1] = '4';
    test_int_sort(sort, test4, 6, message);
    
    /* Test case 5 */
    message[message_length - 1] = '5';
    test_int_sort(sort, test5, 6, message);
    
    /* Test case 6 */
    message[message_length - 1] = '6';
    test_int_sort(sort, test6, 6, message);
}

int main() {
    test_integers(bubble_sort, "bubble_sort.c");
    test_integers(insert_sort, "insert_sort.c");
    return 0;
}
