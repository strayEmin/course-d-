#include "matrix.h"

static void memAllocFailProcess_(void *p, char *func_name) {
    if (p == NULL) {
        MessageBox(GetActiveWindow(), "Fail memory allocated", func_name, MB_ICONERROR);
        exit(1);
    }
}

matrix_t getMemMatrix(size_t n_rows, size_t n_cols) {
    int **values = (int **) malloc(sizeof(int *) * n_rows);
    memAllocFailProcess_(values, "getMemMatrix");

    for (size_t i = 0; i < n_rows; i++) {
        values[i] = (int *) malloc(sizeof(int) * n_cols);
        memAllocFailProcess_(values[i], "getMemMatrix");
    }

    return (matrix_t) {
        values,
        n_rows,
        n_cols
    };
}


matrix_t *getMemArrayOfMatrices(size_t n_matrices, size_t n_rows, size_t n_cols) {
    matrix_t *mx_arr = (matrix_t *) malloc(sizeof(matrix_t) * n_matrices);
    memAllocFailProcess_(mx_arr, "getMemArrayOfMatrices");

    for (size_t i = 0; i < n_matrices; i++) {
        mx_arr[i] = getMemMatrix(n_rows, n_cols);
        memAllocFailProcess_(mx_arr, "getMemArrayOfMatrices");
    }

    return mx_arr;
}


void freeMemMatrix(matrix_t *m) {
    for (; m->n_rows > 0; m->n_rows--) {
        free(m->values[m->n_rows - 1]);
    }

    m->n_cols = 0;
    free(m->values);
    m->values = NULL;
}


void freeMemMatrices(matrix_t *ms, size_t n_matrices) {
    for (size_t i = 0; i < n_matrices; i++) {
        freeMemMatrix(&ms[i]);
    }

    free(ms);
    ms = NULL;
}


void inputMatrix(matrix_t *m) {
    for (size_t i = 0; i < m->n_rows; i++)
        for (size_t j = 0; j < m->n_cols; j++)
            scanf("%d", &m->values[i][j]);
}


void inputMatrices(matrix_t *ms, size_t n_matrices) {
    for (size_t i = 0; i < n_matrices; i++)
        inputMatrix(&ms[i]);
}


void outputMatrix(matrix_t m) {
    for (size_t i = 0; i < m.n_rows; i++) {
        printf("[%d", m.values[i][0]);
        for (size_t j = 1; j < m.n_cols; j++)
            printf(", %d", m.values[i][j]);
        printf("]\n");
    }
}


void outputMatrices(matrix_t *ms, size_t n_matrices) {
    for (size_t i = 0; i < n_matrices; i++) {
        printf("%d elem:\n");
        outputMatrix(ms[i]);
    }
}









