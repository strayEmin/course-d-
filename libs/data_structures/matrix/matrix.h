#ifndef COURSE_MATRIX_H
#define COURSE_MATRIX_H


#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <memory.h>
#include <windows.h>
#include "../../algorithms/array/array.h"


typedef struct matrix {
    int **values; // элементы матрицы
    size_t n_rows; // количество рядов
    size_t n_cols; // количество столбцов
} matrix_t;


typedef struct position {
    size_t row_index;
    size_t col_index;
} position_t;

// размещает в динамической памяти матрицу размером n_rows на n_cols, возвращает матрицу
matrix_t getMemMatrix(size_t n_rows, size_t n_cols);

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу
matrix_t *getMemArrayOfMatrices(size_t n_matrices, size_t n_rows, size_t n_cols);

// освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix_t *m);

// освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix_t *ms, size_t n_matrices);

// ввод матрицы m
void inputMatrix(matrix_t *m);

// ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix_t *ms, size_t n_matrices);

// вывод матрицы m
void outputMatrix(matrix_t m);

// – вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix_t *ms, size_t n_matrices);


#endif //COURSE_MATRIX_H
