#include "libs/data_structures/unordered_set/unordered_set.h"
#include "libs/data_structures/ordered_set/ordered_set.h"


ordered_array_set_t set_a = {
        (int[]) {1, 3, 5, 7},
        4,
        4
};

ordered_array_set_t set_b = {
        (int[]) {4, 6},
        2,
        4
};


void test_ordered_array_set_create_from_array() {
    int arr[] = {1, 5, 3, 7};
    ordered_array_set_t exp = ordered_array_set_create_from_array(arr, 4);

    assert(ordered_array_set_isEqual(set_a, exp));

    ordered_array_set_delete(exp);
}


void test_ordered_array_ind() {
    ordered_array_set_t test_set = ordered_array_set_create_from_array(
            (int[]) {0, 1, 2, 3, 4},5);

    for (int i = 0; i < test_set.size; i++) {
        assert(ordered_array_set_ind(&test_set, i) == i);
    }

    assert(ordered_array_set_ind(&test_set, 5) == test_set.size);

    ordered_array_set_delete(test_set);
}


void test_ordered_array_isEqual() {
    ordered_array_set_t test_set = ordered_array_set_create(set_a.size);
    test_set.size = test_set.capacity;
    memcpy(test_set.data, set_a.data, test_set.size);

    assert(ordered_array_set_isEqual(set_a, test_set));

    ordered_array_set_delete(test_set);
}


void test_ordered_array_set_isAbleAppend() {
    ordered_array_set_t test_set = ordered_array_set_create(5);

    ordered_array_set_isAbleAppend(&test_set);
    ordered_array_set_isAbleAppend(&set_b);

    ordered_array_set_delete(test_set);
}


void test_ordered_array_set_insert() {
    ordered_array_set_t test_set = ordered_array_set_create(set_a.capacity);

    for (size_t i = 0; i < set_a.size; i++) {
        ordered_array_set_insert(&test_set, set_a.data[i]);
    }

    assert(memcmp(set_a.data, test_set.data, set_a.size) == 0);
    assert(test_set.size == set_a.size);

    ordered_array_set_delete(test_set);
}


void test_ordered_array_set_deleteElement() {
    ordered_array_set_t test_set = ordered_array_set_create(set_a.size);
    test_set.size = test_set.capacity;
    memcpy(test_set.data, set_a.data, test_set.size);

    ordered_array_set_deleteElement(&test_set, set_a.data[0]);
    assert(ordered_array_set_isValueIn(test_set, set_a.data[0]) == 0);

    ordered_array_set_delete(test_set);
}


void test_ordered_array_set_union() {
    ordered_array_set_t op_1 = ordered_array_set_create_from_array(
            (int[]) {1, 3, 5, 7}, 4);
    ordered_array_set_t op_2 = ordered_array_set_create_from_array(
            (int[]) {2, 4, 6, 8}, 4);
    ordered_array_set_t op_3 = ordered_array_set_create_from_array(
            (int[]) {7, 8}, 2);
    ordered_array_set_t verify_union = ordered_array_set_create_from_array(
            (int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);

    ordered_array_set_t test_union = ordered_array_set_union(op_1, op_2);

    assert(ordered_array_set_isEqual(verify_union, test_union));
    assert(ordered_array_set_isEqual(verify_union, ordered_array_set_union(test_union, op_3)));

    ordered_array_set_delete(op_1);
    ordered_array_set_delete(op_2);
    ordered_array_set_delete(op_3);
    ordered_array_set_delete(verify_union);
    ordered_array_set_delete(test_union);
}


void test_ordered_array_set_intersection() {
    ordered_array_set_t op_1 = ordered_array_set_create_from_array(
            (int[]) {1, 2, 3, 4}, 4);
    ordered_array_set_t op_2 = ordered_array_set_create_from_array(
            (int[]) {3, 4, 5, 6}, 4);
    ordered_array_set_t op_3 = ordered_array_set_create_from_array(
            (int[]) {7, 8}, 2);
    ordered_array_set_t verify_intersection_1 = ordered_array_set_create_from_array(
            (int[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    ordered_array_set_t verify_intersection_2 = ordered_array_set_create(1);

    ordered_array_set_t test_intersection_1 = ordered_array_set_union(op_1, op_2);
    ordered_array_set_t test_intersection_2 = ordered_array_set_intersection(verify_intersection_1, op_3);

    assert(ordered_array_set_isEqual(verify_intersection_1, test_intersection_1));
    assert(ordered_array_set_isEqual(verify_intersection_2, test_intersection_2));

    ordered_array_set_delete(op_1);
    ordered_array_set_delete(op_2);
    ordered_array_set_delete(op_3);
    ordered_array_set_delete(verify_intersection_1);
    ordered_array_set_delete(test_intersection_1);
    ordered_array_set_delete(verify_intersection_2);
    ordered_array_set_delete(test_intersection_2);
}





void tests() {
    test_ordered_array_set_create_from_array();
    test_ordered_array_ind();
    test_ordered_array_isEqual();
    test_ordered_array_set_isAbleAppend();
    test_ordered_array_set_insert();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
}

int main() {
    tests();

    return 0;
}