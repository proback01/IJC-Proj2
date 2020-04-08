#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_end(const htab_t * t) {
    htab_iterator_t iterator = {NULL, t, t->arr_size};
    return iterator;
}
