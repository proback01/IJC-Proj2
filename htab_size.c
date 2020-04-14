// htab_size.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Definice funkce htab_init, ktera vraci pocet zaznamu v tabulce

#include "htab.h"
#include "structs_dec.h"

size_t htab_size(const htab_t * t) {
    return t->size;
}
