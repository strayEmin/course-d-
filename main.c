#include "libs/data_structures/unordered_set/unordered_set.h"

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {2, 4, 6, 8};

    unordered_array_set uno = unordered_array_set_create_from_array(arr1, 7);
    unordered_array_set set2 = unordered_array_set_create_from_array(arr2, 4);

    unordered_array_set res = unordered_array_set_difference(uno, set2);

    outputArray_(res.data, res.size);
}