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