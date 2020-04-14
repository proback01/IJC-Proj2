// io.h
// Řešení IJC-DU2, příklad b), 14.4.2020
// Autor: Vojtech Maslan, FIT
// Přeloženo: gcc 7.5
// Hlavickovy soubor k io.c

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int get_word(char *s, int max, FILE *f);

#endif