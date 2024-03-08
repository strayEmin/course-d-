#ifndef COURSE_VECTOR_VOID_H
#define COURSE_VECTOR_VOID_H

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include "../../algorithms/array/array.h"

typedef struct vector_void {
    void *data; // указатель на нулевой элемент вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t base_type_size; // размер базового типа:
} vector_void_t;


// возвращает вектор вместимости capacity и размером size 0
vector_void_t createVectorV(size_t capacity, size_t base_type_size);

// изменяет количество памяти, выделенное под хранение элементов вектора
void reserveV(vector_void_t *v, size_t new_capacity);

// удаляет элементы из контейнера, но не освобождает выделенную память
void clearV(vector_void_t *v);

//  освобождает память, выделенную под неиспользуемые элементы
void shrinkToFitV(vector_void_t *v);

// освобождает память, выделенную вектору и приравнивает указателю на массив data NULL,
// размеру и вместимости size и capacity соответственно нули
void deleteVectorV(vector_void_t *v);


#endif //COURSE_VECTOR_VOID_H
