#include "ordered_set.h"


ordered_array_set_t ordered_array_set_create(size_t capacity) {
    int *data = malloc(sizeof(int) * capacity);
    if (data == NULL) {
        fprintf(stderr, "Fail memory allocated in unordered_array_set_create.\n"
                        "File: .../libs/data_structures/ordered_set/ordered_set.h");
        exit(-1);
    }

    return (ordered_array_set_t) {
            data,
            0,
            capacity
    };
}


void unordered_array_set_shrinkToFit(ordered_array_set_t *set) {
    if (set->size != set->capacity) {
        set->data = (int *) realloc(set->data, sizeof(int) * set->size);
        if (set->data == NULL) {
            fprintf(stderr, "Fail memory allocated in unordered_array_set_shrinkToFit\n"
                            "File: .../libs/data_structures/unordered_set/unordered_set.h");
            exit(-1);
        }
        set->capacity = set->size;
    }
}

