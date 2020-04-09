#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_begin(const htab_t * t) {
    // For empty htab returning htab_end
    htab_iterator_t result = htab_end(t);
    // Iterating over linked list and finding first linked list with item
    for(size_t i = 0; i < t->arr_size; i++) {
        if(t->items[i] != NULL) {
            result.idx = i;
            result.ptr = t->items[i];
            result.t = t;
            break;
        }
    }
    return result;
}
