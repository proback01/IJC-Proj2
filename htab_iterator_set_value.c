// htab_iterator_set_key.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce nastavuje hodnotu prvku, na ktery ukazuje dany iterator na danou hodnotu

#include "htab.h"
#include "structs_dec.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {
    htab_value_t prevValue = it.ptr->data;
    it.ptr->data = val;
    return prevValue;
}