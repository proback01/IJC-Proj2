#include "htab.h"
#include "structs_dec.h"

size_t htab_bucket_count(htab_t* table) {
    return table->arr_size;
}