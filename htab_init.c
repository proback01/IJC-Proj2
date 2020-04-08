#include "htab.h"
#include "structs_dec.h"

htab* htab_init(size_t size) {
    htab_t* table = malloc(sizeof(htab_item*) * size + sizeof(htab_t));
    // Checking if dynamic allocation was successful
    if(table == NULL) {
        fprintf(stderr. "Nepodarila se alokace\n");
        return NULL;
    }

    table->size = 0; // Initial number of items
    table->arr_size = size;

    return table;
}