#include "htab.h"
#include "structs_dec.h"

htab_t* htab_init(size_t size) {
    htab_t* table = malloc(sizeof(htab_t) + sizeof(struct htab_item*) * size);
    // Checking if dynamic allocation was successful
    if(table == NULL) {
        fprintf(stderr, "Nepodarila se alokace\n");
        return NULL;
    }

    for(size_t i = 0; i < size; i++){
        table->items[i] = NULL;
    }

    table->size = 0; // Initial number of items
    table->arr_size = size;

    return table;
}
