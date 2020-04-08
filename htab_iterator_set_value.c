/**
 * Funkce nastavuje hodnotu polozky z tabulky, urcene iteratorem
 */

#include "htab.h"
#include "structs_dec.h"

htab_value_t htab_iterator_set_value(htab_iterator_t it, htab_value_t val) {
    htab_value_t prevValue = it.ptr->data;
    it.ptr->data = val;
    return prevValue;
}