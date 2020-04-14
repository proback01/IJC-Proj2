// htab_iterator_get_value.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce vraci hodnotu prvku, na ktery ukazuje dany iterator

#include "htab.h"
#include "structs_dec.h"

htab_value_t htab_iterator_get_value(htab_iterator_t it) {
    return it.ptr->data;
}
