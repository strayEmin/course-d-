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

// осуществляет ввод матрицы m
void inputMatrix(matrix_t *m);

// осуществляет ввод массива из nMatrices матриц, хранящейся по адресу ms
void inputMatrices(matrix_t *ms, size_t n_matrices);

// осуществляет вывод матрицы m
void outputMatrix(matrix_t m);

// вывод массива из nMatrices матриц, хранящегося по адресу ms
void outputMatrices(matrix_t *ms, size_t n_matrices);

// осуществляет обмен строк под индексами i1 и i2 в матрице m
void swapRows(matrix_t m, size_t i1, size_t i2);

// осуществляет обмен столбцов под индексами j1 и j2 в матрице m
void swapColumns(matrix_t m, size_t j1, size_t j2);

// осуществляет сортировку вставками строк матрицы m по значениям функции criteria,
// примененной к этим строкам
void insertionSortRowsMatrixByRowCriteria(matrix_t m, int (*criteria)(int*, size_t));

// возвращает указатель на динамически выделенную область памяти,
// содержащую в себе столбец по индексу index размера m.n_rows
int *getColumn(matrix_t m, size_t index);

// осуществляет сортировку выбором столбцов матрицы m по значениям функции criteria,
// примененной к этим столбцам
void selectionSortColsMatrixByColCriteria(matrix_t m, int (*criteria)(int*, size_t));


#endif //COURSE_MATRIX_H
