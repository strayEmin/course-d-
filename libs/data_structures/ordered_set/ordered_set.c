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


void ordered_array_set_shrinkToFit(ordered_array_set_t *set) {
    if (set->size != set->capacity) {
        set->data = (int *) realloc(set->data, sizeof(int) * set->size);
        if (set->data == NULL) {
            fprintf(stderr, "Fail memory allocated in ordered_array_set_shrinkToFit\n"
                            "File: .../libs/data_structures/ordered_set/ordered_set.h");
            exit(-1);
        }
        set->capacity = set->size;
    }
}


ordered_array_set_t ordered_array_set_create_from_array(const int *a,
                                                        size_t size) {
    ordered_array_set_t set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);
    ordered_array_set_shrinkToFit(&set);

    return set;
}


size_t ordered_array_set_ind(ordered_array_set_t set, int value) {
    return binarySearch_(set.data, set.size, value);
}

bool ordered_array_set_isValueIn(ordered_array_set_t set, int value) {
    return ordered_array_set_ind(set, value) != set.size;
}

bool ordered_array_set_isEqual(ordered_array_set_t set1, ordered_array_set_t set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++) {
        if (set1.data[i] != set2.data[i])
            return false;
    }

    return true;
}

bool ordered_array_set_isSubset(ordered_array_set_t subset,
                                ordered_array_set_t set) {

}
