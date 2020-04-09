#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_iterator_next(htab_iterator_t it) {
    htab_iterator_t result;
    result.t = it.t;
    // Current iterator points to last item in current linked list
    if(it.ptr->next == NULL) {
        // Finding next linked list with item
        for(size_t i = it.idx + 1; i < it.t->arr_size; i++) {
            // Checking if linked list contains item
            if(it.t->items[i] != NULL) {
                result.ptr = it.t->items[i];
                result.idx = i;
                return result;
            }
        }
        // No other linked list with items found, returning htab_end
        result = htab_end(it.t);
    }
    else { // Jumping in current linked list to next item
        result.ptr = it.ptr->next;
        result.idx = it.idx;
    }
    return result;
}
