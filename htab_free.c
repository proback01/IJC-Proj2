#include "htab.h"
#include "structs_dec.h"

void htab_free(htab_t* table) {
    htab_clear(table);
    free(table);
}