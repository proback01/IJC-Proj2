#include "htab.h"
#include <stdio.h>
int main() {
    char *word = malloc(100);
    htab_t* table = htab_init(10000);

    strcpy(word, "prdel");
    htab_lookup_add(table, word);

    strcpy(word, "joo");
    htab_lookup_add(table, word);

    strcpy(word, "hej");
    htab_lookup_add(table, word);

    htab_iterator_t hejIterator = htab_find(table, "hej");
    htab_iterator_set_value(hejIterator, 5);

    htab_iterator_t iterator = htab_find(table, "joo");
    htab_iterator_t iterator2 = htab_find(table, "hej");
    htab_value_t value = htab_iterator_get_value(iterator);
    htab_value_t value2 = htab_iterator_get_value(iterator2);

    printf("%i %i\n", value, value2);

    return 0;
}
