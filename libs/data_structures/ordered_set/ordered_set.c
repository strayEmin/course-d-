#include "ordered_set.h"


ordered_set_t ordered_array_set_create(size_t capacity) {
    int *data = malloc(sizeof(int) * capacity);
    if (data == NULL) {
        fprintf(stderr, "Fail memory allocated in unordered_array_set_create.\n"
                        "File: .../libs/data_structures/ordered_set/ordered_set.h");
        exit(-1);
    }

    return (ordered_set_t) {
            data,
            0,
            capacity
    };
}


static void ordered_set_shrink_to_fit(ordered_set_t *set ) {
    if ( set->m_capacity != set->m_size ) {
        set->m_data = realloc( set->m_data, sizeof( int ) * set->m_size );
        set->m_capacity = set->m_size;
    }
}

