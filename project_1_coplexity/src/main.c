#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "complexity_functions.h"
#include "utils.h"
#include "timing.h"

int main() {
    srand((unsigned)time(NULL));

    // Tamaños de entrada a probar
    size_t sizes[] = {1000, 10000, 50000, 100000};
    size_t nsizes = sizeof(sizes)/sizeof(sizes[0]);

    for (size_t i = 0; i < nsizes; i++) {
        size_t n = sizes[i];
        int *arr = generate_random_array(n);
        if (!arr) {
            fprintf(stderr, "Error: no se pudo asignar memoria para n=%zu\n", n);
            continue;
        }

        // O(1)
        clock_t start = start_timer();
        return_first(arr, n);
        double tiempo = end_timer(start);
        print_result("O(1)", n, tiempo);

        // O(n)
        start = start_timer();
        sum_array(arr, n);
        tiempo = end_timer(start);
        print_result("O(n)", n, tiempo);

        // O(n log n)
        // Copiamos el array para no alterar el original en otras pruebas
        int *arr_copy = malloc(n * sizeof(int));
        if (arr_copy) {
            for (size_t j = 0; j < n; j++) arr_copy[j] = arr[j];
            start = start_timer();
            merge_sort(arr_copy, n);
            tiempo = end_timer(start);
            print_result("O(n log n)", n, tiempo);
            free(arr_copy);
        }

        // O(n²)
        start = start_timer();
        count_pairs(arr, n);
        tiempo = end_timer(start);
        print_result("O(n²)", n, tiempo);

        printf("------------------------\n");
        free(arr);

    }
}