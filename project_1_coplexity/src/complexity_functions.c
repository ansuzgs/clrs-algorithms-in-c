#include "complexity_functions.h"
#include <stdlib.h>
#include <string.h>

// Funcion O(1)
int return_first(const int *arr, size_t n) {
  return arr[0];
}

// Funcion O(n)
long long sum_array(const int *arr, size_t n) {
  long long sum = 0;
  for (size_t i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

// Funciones auxiliares para merge sort
static void merge(int *arr, int *temp, size_t left, size_t mid, size_t right) {
  size_t i = left, j = mid + 1, k = left;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
    }
  }
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }

  memcpy(arr + left, temp + left, (right - left + 1)*sizeof(int));

}

static void merge_sort_recursive(int *arr, int *temp, size_t left, size_t right) {
  if (left >= right) return;
  size_t mid = left + ( right - left )/2;
  merge_sort_recursive(arr, temp, left, mid);
  merge_sort_recursive(arr, temp, mid+1, right);
  merge(arr, temp, left, mid, right);
}

// Funcion O(n log n)
void merge_sort(int *arr, size_t n) {
  if (n < 2) return;
  int *temp = malloc(n*sizeof(int));
  if (!temp) return;
  merge_sort_recursive(arr, temp, 0, n-1);
  free(temp);
}

// Funcion O(n^2)
int count_pairs(const int *arr, size_t n) {
  int count = 0;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = i+1; j < n; j++) {
      if (arr[i] == arr[j]) {
        count++;
      }
    }
  }
  return count;
}

