#ifndef CODE_ORDERED_SET_H
#define CODE_ORDERED_SET_H


#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include "C:\Users\пашк\Desktop\лабы\основы алг и проги\clion\course\libs\algorithms\array\array.h"
#include "C:\Users\пашк\Desktop\лабы\основы алг и проги\clion\course\libs\data_structures\unordered_set\unordered_set.h"


typedef struct ordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} ordered_set_t;

// возвращает пустое множество, в которое можно вставить capacity элементов
ordered_set_t ordered_array_set_create(size_t capacity);

// возвращает множество, состоящее из элементов массива a размера size
ordered_set_t ordered_array_set_create_from_array(const int *a,
                                                  size_t size);

// возвращает значение позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t ordered_array_set_in(ordered_set_t *set, int value);

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool ordered_array_set_isEqual(ordered_set_t set1, ordered_set_t set2);

// возвращает значение ’истина’, если subset является подмножеством set
// иначе - ’ложь’
bool
ordered_array_set_isSubset(ordered_set_t subset, ordered_set_t set);

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void ordered_array_set_isAbleAppend(ordered_set_t *set);

// добавляет элемент value в множество set
void ordered_array_set_insert(ordered_set_t *set, int value);

// удаляет элемент value из множества set
void ordered_array_set_deleteElement(ordered_set_t *set, int value);

// возвращает объединение множеств set1 и set2
ordered_set_t ordered_array_set_union(ordered_set_t set1,
                                      ordered_set_t set2);

// возвращает пересечение множеств set1 и set2
ordered_set_t ordered_array_set_intersection(ordered_set_t set1,
                                             ordered_set_t set2);

// возвращает разность множеств set1 и set2
ordered_set_t ordered_array_set_difference(ordered_set_t set1,
                                           ordered_set_t set2);

// возвращает симметрическую разность множеств set1 и set2
ordered_set_t ordered_array_set_symmetricDifference(ordered_set_t set1,
                                                    ordered_set_t set2);

// возвращает дополнение до универсума universumSet множества set
ordered_set_t ordered_array_set_complement(ordered_set_t set,
                                           ordered_set_t universumSet);

// вывод множества set
void ordered_array_set_print(ordered_set_t set);

// освобождает память, занимаемую множеством set
void ordered_array_set_delete(ordered_set_t set);


#endif //CODE_ORDERED_SET_H
