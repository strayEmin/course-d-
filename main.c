#include "libs/data_structures/unordered_set/unordered_set.h"

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};

    unordered_array_set set1 = unordered_array_set_create_from_array(arr1, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array(arr2, 4);

    unordered_array_set res = unordered_array_set_union(set1, set2);

    outputArray_(res.data, res.size);
}