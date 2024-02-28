#ifndef COURSE_VECTOR_H
#define COURSE_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include "../../algorithms/array/array.h"

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector_t;

// возвращает вектор вместимости capacity и размером size 0
vector_t createVector(size_t capacity) {
    int *data = (int *) malloc(capacity * sizeof(int));
    if (data == NULL && capacity != 0) {
        fprintf(stderr, "Fail memory allocated in vectorCreate\n");
        exit(1);
    }

    return (vector_t) {
        data,
        0,
        capacity
    };
}




#endif //COURSE_VECTOR_H
