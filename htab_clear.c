#include "htab.h"
#include "structs_dec.h"

void htab_clear(htab_t* table) {
    for(size_t i = 0; i < htab_bucket_count(table); i++) {
        struct htab_item* current = table->items[i];
        struct htab_item* temp;

        while(current != NULL) {
            temp = current->next;
            free(current);
            current=temp;
        }
        table->items[i] = NULL;
    }
}