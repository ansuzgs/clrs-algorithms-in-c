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

    // Abrir archivo para escribir resultados
    FILE *fp = fopen("resultados.dat", "w");
    if (!fp) {
        fprintf(stderr, "Error: no se pudo crear el archivo de resultados.dat\n");
        return EXIT_FAILURE;
    }

    // Escribir encabezados
    fprintf(fp, "# n O1 On Onlogn On2\n");

    for (size_t i = 0; i < nsizes; i++) {
        size_t n = sizes[i];
        int *arr = generate_random_array(n);
        if (!arr) {
            fprintf(stderr, "Error: no se pudo asignar memoria para n=%zu\n", n);
            continue;
        }

        // Variables para almacenar los tiempos
        double tiempo_O1, tiempo_On, tiempo_Onlogn, tiempo_On2;

        // O(1)
        clock_t start = start_timer();
        return_first(arr, n);
        tiempo_O1 = end_timer(start);

        // O(n)
        start = start_timer();
        sum_array(arr, n);
        tiempo_On = end_timer(start);

        // O(n log n)
        // Copiamos el array para no alterar el original en otras pruebas
        int *arr_copy = malloc(n * sizeof(int));
        if (arr_copy) {
            for (size_t j = 0; j < n; j++) arr_copy[j] = arr[j];
            start = start_timer();
            merge_sort(arr_copy, n);
            tiempo_Onlogn = end_timer(start);
            free(arr_copy);
        } else {
            tiempo_Onlogn = -1.0;
        }

        // O(n²)
        start = start_timer();
        count_pairs(arr, n);
        tiempo_On2 = end_timer(start);

        // Escribir los resultados en el fichero
        fprintf(fp, "%zu %.6f %.6f %.6f %.6f\n", n, tiempo_O1, tiempo_On, tiempo_Onlogn, tiempo_On2);

        // Imprimir resultados en pantalla (opcional)
        print_result("O(1)", n, tiempo_O1);
        print_result("O(n)", n, tiempo_On);
        if (tiempo_Onlogn >= 0.0)
            print_result("O(n log n)", n, tiempo_Onlogn);
        else
            printf("O(n log n) con n=%zu: Error al ordenar\n", n);
        print_result("O(n²)", n, tiempo_On2);
        printf("------------------------\n");

        free(arr);

    }


    fclose(fp);
    printf("Resultados guardados en resultados.dat\n");

    return 0;
}