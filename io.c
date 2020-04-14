// io.c
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Soubor obsahuje funkci get_word, ktera nacita vzdy jedno slovo z daneho file streamu

#include "io.h"

int get_word(char *s, int max, FILE *f) {
    int c;
    bool overflow = false;
    // Iterating over first whitespaces
    while(isspace(c = getc(f)));

    // First character of actual word
    if(c == EOF) // Only EOF
        return EOF;

    s[0] = (char)c;

    int i = 1;
    // Iterating over other characters of word
    while(!isspace(c = getc(f)) && c != EOF) {
        if(i > max - 1) { // Checking overflow
            overflow = true;
            break;
        }
        s[i] = (char)c;
        i++;
    }
    s[i] = '\0';

    // If overflow occured, iterate over rest of the word
    if(overflow) {
        while(!isspace(c = getc(f)) && c != EOF)
            i++;
    }

    return i;
}
