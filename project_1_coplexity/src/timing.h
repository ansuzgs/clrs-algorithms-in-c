#ifndef TIMING_H
#define TIMING_H

#include <time.h>

/**
 * Inicia una medicion de tiempo.
 * Retorna el clock_t inicial.
*/
static inline clock_t start_timer() {
    return clock();
}

/**
 * Finaliza una medicion de tiempo dado el clock_t inicial,
 * retorna el tiempo transcurrido en segundos
*/
static inline double end_timer(clock_t start) {
    clock_t end = clock();
    return (double)(end - start)/CLOCKS_PER_SEC;
}

#endif