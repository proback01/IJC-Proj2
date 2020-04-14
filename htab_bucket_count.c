// htab_bucket_count.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Definice funkce htab_init, ktera vraci velikost pole s jakym dana tabulka pracuje

#include "htab.h"
#include "structs_dec.h"

size_t htab_bucket_count(const htab_t * t) {
    return t->arr_size;
}
