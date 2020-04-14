// htab_erase.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce vymaze z tabulky prvek na ktery ukazuje dany iterator

#include "htab.h"
#include "structs_dec.h"

void htab_erase(htab_t * t, htab_iterator_t it) {
    struct htab_item* prevItem = NULL;
    struct htab_item* item = t->items[it.idx];
    //Reconnecting linear list
    while(item != NULL) {
        if(strcmp(it.ptr->key, item->key) == 0) { // It is item we are going to erase
            //First item, changing head
            if(prevItem == NULL)
                t->items[it.idx] = item->next;
            else
                prevItem->next = item->next;
            break;
        }
        item = item->next;
        prevItem = item;
    }
    free(it.ptr->key);
    free(it.ptr);
    it.ptr = NULL;

    t->size--;
}
