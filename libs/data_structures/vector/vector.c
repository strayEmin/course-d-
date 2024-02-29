#include "vector.h"


vector_t createVector(size_t capacity) {
    int *data = NULL;
    if (capacity != 0) {
        data = (int *) malloc(capacity * sizeof(int));
        if (data == NULL) {
            fprintf(stderr, "Fail memory allocated in vectorCreate\n");
            exit(1);
        }
    }

    return (vector_t) {
        data,
        0,
        capacity
    };
}


void reserve(vector_t *v, size_t new_capacity) {
    v->capacity = new_capacity;

    if (v->capacity == 0) {
        free(v->data);
        v->data = NULL;
    } else {
        v->data = (int *) realloc(v->data, v->capacity * sizeof(int));
        if (v->data == NULL) {
            fprintf(stderr, "Fail memory allocated in reserve\n");
            exit(1);
        }
    }

    if (v->capacity < v->size)
        v->size = v->capacity;
}


void clear(vector_t *v) {
    v->size = 0;
}


void shrinkToFit(vector_t *v) {
    reserve(v, v->size);
}

void deleteVector(vector_t *v) {
    reserve(v, 0);
}