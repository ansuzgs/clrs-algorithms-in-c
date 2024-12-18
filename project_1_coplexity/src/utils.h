#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

/**
 * Genera un array de tamaño n con numeros aleatorios.
 * Retorna un puntero a int con la memoria reservada,
 * el usuario debe liberar con free().
*/
int *generate_random_array(size_t n);

/**
 * Imprime el array
*/
void print_array(const int *arr, size_t n);

/**
 * Imprime los resultados en un formato tabular o legible.
 * tiempo_seg es el tiempo en segundos
*/
void print_result(const char *label, size_t n, double tiempo_seg);

#endif // !DEBUG
