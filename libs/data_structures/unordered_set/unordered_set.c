#include "unordered_set.h"


unordered_set_t unordered_array_set_create(size_t capacity) {
    int *data = malloc(sizeof(int) * capacity);
    if (data == NULL) {
        fprintf(stderr, "Fail memory allocated in unordered_array_set_create.\n"
                        "File: .../libs/data_structures/unordered_set/unordered_set.h");
        exit(-1);
    }
    return (unordered_set_t) {
            data,
            0,
            capacity
    };
}


void unordered_array_set_shrinkToFit(unordered_set_t *set) {
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


unordered_set_t unordered_array_set_create_from_array(const int *arr, size_t arr_size) {
    unordered_set_t set = unordered_array_set_create(arr_size);
    for (size_t i = 0; i < arr_size; i++) {
        unordered_array_set_insert(&set, arr[i]);
    }
    unordered_array_set_shrinkToFit(&set);

    return set;
}


size_t unordered_array_set_ind(unordered_set_t set, int value) {
    return getFirstIndexOfNumber_(set.data, set.size, value);
}


bool unordered_array_set_isValueIn(unordered_set_t set, int value) {
    return unordered_array_set_ind(set, value) != set.size;
}


bool unordered_array_set_isSubset(unordered_set_t subset, unordered_set_t set) {
    size_t matches = 0;
    for (size_t i = 0; i < subset.size; i++) {
        if (unordered_array_set_isValueIn(set, subset.data[i]))
            matches++;
    }

    return matches == subset.size;
}


void unordered_array_set_isAbleAppend(unordered_set_t *set) {
    assert(set->size < set->capacity);
}


void unordered_array_set_insert(unordered_set_t *set, int value) {
    unordered_array_set_isAbleAppend(set);

    if (!isValueInArr(set->data, set->size, value)) {
        set->data[set->size++] = value;
    }
}


void unordered_array_set_deleteElement(unordered_set_t *set, int value) {
    size_t index_of_value = unordered_array_set_ind(*set, value);
    if (index_of_value < set->size)
        deleteByIndexAndSaveOrder_(set->data, &set->size, index_of_value);
}


unordered_set_t unordered_array_set_union(unordered_set_t set1,
                                          unordered_set_t set2) {
    unordered_set_t result = unordered_array_set_create(set1.size + set2.size);

    memcpy(result.data, set1.data, set1.size * sizeof(int));
    result.size = set1.size;

    for (size_t i = 0; i < set2.size; i++) {
        unordered_array_set_insert(&result, set2.data[i]);
    }

    unordered_array_set_shrinkToFit(&result);

    return result;
}


unordered_set_t unordered_array_set_intersection(unordered_set_t set1,
                                                 unordered_set_t set2) {
    unordered_set_t result = unordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (unordered_array_set_isValueIn(set2, set1.data[i]))
            unordered_array_set_insert(&result, set1.data[i]);
    }

    unordered_array_set_shrinkToFit(&result);

    return result;
}


unordered_set_t unordered_array_set_difference(unordered_set_t set1,
                                               unordered_set_t set2) {
    unordered_set_t result = unordered_array_set_create(set1.size);

    for (size_t i = 0; i < set1.size; i++) {
        if (!unordered_array_set_isValueIn(set2, set1.data[i]))
            result.data[result.size++] = set1.data[i];
    }

    unordered_array_set_shrinkToFit(&result);

    return result;
}


unordered_set_t unordered_array_set_complement(unordered_set_t set,
                                               unordered_set_t universumSet) {
    assert(unordered_array_set_isSubset(set, universumSet));
    return unordered_array_set_difference(universumSet, set);
}


unordered_set_t unordered_array_set_symmetricDifference(unordered_set_t set1,
                                                        unordered_set_t set2) {
    unordered_set_t l_diff = unordered_array_set_difference(set1, set2);
    unordered_set_t r_diff = unordered_array_set_difference(set2, set1);

    unordered_set_t result = unordered_array_set_create(l_diff.size + r_diff.size);

    result.size = result.capacity;

    memcpy(result.data, l_diff.data, l_diff.size * sizeof(int));
    memcpy(&result.data[l_diff.size], r_diff.data, r_diff.size * sizeof(int));

    unordered_array_set_delete(l_diff);
    unordered_array_set_delete(r_diff);

    return result;
}


void unordered_array_set_print(unordered_set_t set) {
    outputArray_(set.data, set.size);
}


void unordered_array_set_delete(unordered_set_t set) {
    free(set.data);
}







