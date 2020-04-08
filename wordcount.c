#include "htab.h"
#include <stdio.h>
int main() {
    char *word = malloc(100);
    htab_t* table = htab_init(10000);

    strcpy(word, "prdel");
    htab_iterator_t it = htab_lookup_add(table, word);
    htab_iterator_set_value(it, 20);
    htab_value_t value = htab_iterator_get_value(it);
    printf("1: %i\n", value);
    htab_erase(table, it);
    it = htab_lookup_add(table, word);
    value = htab_iterator_get_value(it);
    printf("2: %i\n", value);

    return 0;
}
