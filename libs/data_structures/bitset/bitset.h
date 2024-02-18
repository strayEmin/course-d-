#ifndef CODE_BITSET_H
#define CODE_BITSET_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct bitset {
    uint32_t values; // множество
    uint32_t max_value; // максимальный элемент универсума
} bitset;

// возвращает пустое множество c универсумом 0, 1,..., max_value
bitset bitset_create(unsigned max_value);

// возвращает значение ’истина’, если значение value имеется в множестве set
// иначе - ’ложь’
bool bitset_in(bitset set, unsigned int value);

// возвращает значение ’истина’, если множества set1 и set2 равны// иначе - ’ложь’
bool bitset_isEqual(bitset set1, bitset set2);

// возвращает значение ’истина’ если множество subset
// является подмножеством множества set, иначе - ’ложь’.
bool bitset_isSubset(bitset subset, bitset set);

// добавляет элемент value в множество set
void bitset_insert(bitset *set, unsigned int value);

// удаляет элемент value из множества set
void bitset_deleteElement(bitset *set, unsigned int value);

// возвращает объединение множеств set1 и set2
bitset bitset_union(bitset set1, bitset set2);

// возвращает пересечение множеств set1 и set2
bitset bitset_intersection(bitset set1, bitset set2);

// возвращает разность множеств set1 и set2
bitset bitset_difference(bitset minuend, bitset subtrahend);

// возвращает симметрическую разность множеств set1 и set2
bitset bitset_symmetricDifference(bitset set1, bitset set2);

// возвращает дополнение до универсума множества set
bitset bitset_complement(bitset set);

// вывод множества set
void bitset_print(bitset set);


#endif //CODE_BITSET_H
