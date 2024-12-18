#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int *generate_random_array(size_t n) {
    int *arr = malloc(n*sizeof(int));
    if (!arr) return NULL;
    for (size_t i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}

void print_array(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print_result(const char *label, size_t n, double tiempo_seg) {
    printf("%-15s n=%10zu: %f s\n", label, n, tiempo_seg);
}