#include "htab.h"
#include "structs_dec.h"

htab_iterator_t htab_lookup_add(htab_t *t, htab_key_t key) {
    // Finding if already exists item with given key
    htab_iterator_t iterator = htab_find(t, key);
    if(htab_iterator_valid(iterator))
        return iterator;

    // Item with given key doesnt exists
    struct htab_item* itemToAdd = malloc(sizeof(struct htab_item));
    itemToAdd->key = key;
    itemToAdd->data = 1;
    itemToAdd->next = NULL;

    size_t index = htab_hash_fun(key) % t->arr_size;
    htab_item* item = t->items[index];

    // Iterate to last item
    while(item->next != NULL)
        item = item->next;

    item->next = itemToAdd;
    iterator.t = t;
    iterator.ptr = itemToAdd;
    iterator.idx = index;
    return iterator;
}