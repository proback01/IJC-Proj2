// htab_init.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Definice funkce htab_init, ktera vytvari novou hash table.
// Velikost pole se kterym tabulka pracuje je dana parametrem size


#include "htab.h"
#include "structs_dec.h"

htab_t* htab_init(size_t size) {
    htab_t* table = malloc(sizeof(htab_t) + sizeof(struct htab_item*) * size);
    // Checking if dynamic allocation was successful
    if(table == NULL) {
        return NULL;
    }

    for(size_t i = 0; i < size; i++) {
        table->items[i] = NULL;
    }

    table->size = 0; // Initial number of items
    table->arr_size = size;

    return table;
}
