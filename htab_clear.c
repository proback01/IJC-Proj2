// htab_clear.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce zrusi veskere prvky v tabulce, ktera pote zustane prazdna

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