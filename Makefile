# Projekt: Proj1 IJC
# Autor: Vojtech Maslan
# Datum: 24.2.2020

CC=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra 

all: tail

tail: tail.c
	$(CC) $(CFLAGS) -o tail tail.c
