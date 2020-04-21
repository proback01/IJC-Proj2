#include "htab.h"
#include "structs_dec.h"
#include "io.h"
#include <stdio.h>
#include <stdbool.h>

#define BUCKET_SIZE 5000
#define MAX_WORD_SIZE 127

int main() {
    int len;
    bool overflowMsg = false;
    htab_t* m = htab_init(BUCKET_SIZE);
    char* word = malloc(sizeof(char) * (MAX_WORD_SIZE + 1));
    htab_iterator_t it;
    htab_value_t value;


    while((len = get_word(word,MAX_WORD_SIZE, stdin)) != EOF) {
        if(len > MAX_WORD_SIZE && !overflowMsg) { // Checking overflow
            fprintf(stderr, "Minimalne jedno slovo se nepodarilo nacist cele\n");
            overflowMsg = true;
        }
        it = htab_lookup_add(m, word);
        value = htab_iterator_get_value(it);
        htab_iterator_set_value(it, ++value);
    }

    //Iterating over htab
    for(htab_iterator_t it = htab_begin(m); !htab_iterator_equal(it, htab_end(m)); it = htab_iterator_next(it))
        printf("%s\t%i\n", htab_iterator_get_key(it), htab_iterator_get_value(it));

    htab_free(m);
    free(word);
    return 0;
}
