/**
 * Funkce hleda v hash table zaznam s danym klicem
 * Pokud najde vraci iterator na zaznam
 * Pokud nenajde vraci htab_end()
 */

#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_find(htab_t *t, htab_key_t key) {
    size_t index = htab_hash_fun(key) % t->arr_size;


    struct htab_item* item = t->items[index];
    // Finding in linear list key equal to given key in argument
    while(item != NULL) {
        if(strcmp(item->key, key) == 0)
            break;

        // Keys are not same, moving to another item in list
        item = item->next;
    }
    // Item with given key was not found
    if(item == NULL)
        return htab_end(t);


    htab_iterator_t iterator = {item, t, index};
    return iterator;
}