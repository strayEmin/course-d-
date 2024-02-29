#include "vector.h"

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