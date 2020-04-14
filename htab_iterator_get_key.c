// htab_iterator_get_key.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce vraci klic prvku, na ktery ukazuje dany iterator

#include "htab.h"
#include "structs_dec.h"

htab_key_t htab_iterator_get_key(htab_iterator_t it) {
    return it.ptr->key;
}
