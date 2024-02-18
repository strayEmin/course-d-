#include "bitset.h"


bitset bitset_create(unsigned max_value) {
    assert(max_value < 32);
    return (bitset) {0, max_value};
}

bool bitset_in(bitset set, unsigned int value) {
    return (value < set.max_value) && set.values & (1 << value);
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (set.values & subset.values) == subset.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    assert(value <= set->max_value);
    set->values |= (1 << value);
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    assert(value <= set->max_value);
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    return (bitset) {
        set1.values | set2.values,
        set1.max_value
        };
}

bitset bitset_intersection(bitset set1, bitset set2) {
    return (bitset) {
        set1.values & set2.values,
        set1.max_value
    };
}

bitset bitset_difference(bitset minuend, bitset subtrahend) {
    return (bitset) {
        minuend.values & ~subtrahend.values,
        minuend.max_value
    };
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    return (bitset) {
        set1.values ^ set2.values,
        set1.max_value
    };
}

bitset bitset_complement(bitset set) {
    uint32_t n = 32 - (set.max_value + 1);
    return (bitset) {
        (~set.values << n) >> n,
        set.max_value
    };
}

void bitset_print(bitset set) {
    for (uint32_t elem_of_sequence = 0; elem_of_sequence <= set.max_value; elem_of_sequence++) {
        if (bitset_in(set, elem_of_sequence))
            printf("%u ", elem_of_sequence);
    }
}