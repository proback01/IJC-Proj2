// htab_lookup_add.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Funkce hleda v hash table zaznam s danym, klicem
// Pokud najde vraci iterator na zaznam
// Pokud nenajde vytvari zaznam a vraci iterator na zaznam

#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_lookup_add(htab_t *t, htab_key_t key) {
    struct htab_iterator result;
    // Calculating index of linear list where should item with given key be
    size_t index = htab_hash_fun(key) % t->arr_size;

    // First item in linear list
    struct htab_item* item = t->items[index];

    struct htab_item* prevItem = item;
    // Finding in linear list key equal to given key in argument
    // Loop ends either when item with key was found or when got to end of list
    while(item != NULL) {
        prevItem = item;

        if(strcmp(item->key, key) == 0)
            break;

        // Keys are not same, moving to another item in list
        item = item->next;
    }

    // Item with given key was found, returning this item
    if(item != NULL) {
        result.ptr = item;
        result.t = t;
        result.idx = index;
        return result;
    }

    // Item wasn't found, creating new item and returning this item
    item = malloc(sizeof(struct htab_item));
    if(item == NULL)
        return htab_end(t);
    item->key = malloc(sizeof(char) * (strlen(key) + 1));
    if(item->key == NULL)
        return htab_end(t);

    strcpy(item->key, key);
    item->data = 0;
    item->next = NULL;

    t->size++; // Increment number of items in htab

    //Adding item to linear list
    if(prevItem == NULL) // First item in list
        t->items[index] = item;
    else
        prevItem->next = item;

    // Creating iterator
    result.ptr = item;
    result.t = t;
    result.idx = index;
    return result;
}
