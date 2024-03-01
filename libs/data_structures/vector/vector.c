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


bool isEmpty(vector_t v) {
    return v.size == 0;
}


bool isFull(vector_t v) {
    return v.size == v.capacity;
}


int getVectorValue(vector_t v, size_t i) {
    if (i >= v.size ) {
        fprintf(stderr, "Access error: going beyond the vector\n");
        exit(1);
    }
    return v.data[i];
}


void pushBack(vector_t *v, int x) {
    if (isFull(*v))
        reserve(v, v->capacity * 2 ? v->capacity != 0 : 1);

    v->data[v->size] = x;
    v->size++;
}


void popBack(vector_t *v) {
    if (isEmpty(*v)) {
        fprintf(stderr, "Error: the vector is empty, it is impossible to delete the last element\n");
        exit(1);
    }
    if (--v->size <= v->capacity / 2)
        reserve(v, v->capacity / 2);
}
