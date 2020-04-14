// htab_begin.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce vraci iterator na prvni prvek tabulky

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
