// htab_free.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce zrusi veskere prvky v tabulce a tabulku samotnou zrusi.

#include "htab.h"
#include "structs_dec.h"

void htab_free(htab_t* table) {
    htab_clear(table);
    free(table);
}
