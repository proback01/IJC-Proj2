// htab_end.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce vraci iterator za konec tabulky

#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_end(const htab_t * t) {
    htab_iterator_t iterator = {NULL, t, t->arr_size};
    return iterator;
}
