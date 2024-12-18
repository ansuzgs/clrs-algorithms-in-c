#ifndef COMPLEXITY_FUNCS_H
#define COMPLEXITY_FUNCS_H

#include <stddef.h>

/**
* O(1): Retorna el primer elemento del array.
* n: tamaño del array
*/
int return_first(const int *arr, size_t n);

/**
* O(n): Suma todos los elementos del array.
* n: tamaño del array
*/
long long sum_array(const int *arr, size_t n);

/**
* O(n log n): Ordena el array usando merge sort
* n: tamaño del array
*/
void merge_sort(int *arr, size_t n);

/**
* O(n^2): Cuenta pares que cumplan una condicion
* n: tamaño del array
*/
int count_pairs(const int *arr, size_t n);

#endif
