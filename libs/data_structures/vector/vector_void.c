#include "vector_void.h"


vector_void_t createVectorV(size_t capacity, size_t base_type_size) {
    void *data = NULL;
    if (capacity != 0) {
        data = malloc(capacity * base_type_size);
        if (data == NULL) {
            fprintf(stderr, "Fail memory allocated in vectorCreateV\n");
            exit(1);
        }
    }

    return (vector_void_t) {
            data,
            0,
            capacity,
            base_type_size
    };
}


void reserveV(vector_void_t *v, size_t new_capacity) {
    v->capacity = new_capacity;

    if (v->capacity == 0) {
        free(v->data);
        v->data = NULL;
    } else {
        v->data = realloc(v->data, v->capacity * v->base_type_size);
        if (v->data == NULL) {
            fprintf(stderr, "Fail memory allocated in reserveV\n");
            exit(1);
        }
    }

    if (v->capacity < v->size)
        v->size = v->capacity;
}


void clearV(vector_void_t *v) {
    v->size = 0;
}


void shrinkToFitV(vector_void_t *v) {
    reserveV(v, v->size);
}


void deleteVectorV(vector_void_t *v) {
    reserveV(v, 0);
}