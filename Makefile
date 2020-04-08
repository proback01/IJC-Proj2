# Projekt: Proj1 IJC
# Autor: Vojtech Maslan
# Datum: 24.2.2020

CC=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra 

all: tail wordcount libhtab.a

tail: tail.c
	$(CC) $(CFLAGS) -o tail tail.c

wordcount: wordcount.o libhtab.a
	$(CC) $(CFLAGS) $^ -o wordcount

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c wordcount.c

libhtab.a: htab_bucket_count.o htab_clear.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_lookup_add.o htab_size.o
	ar rcs $@ $^

htab_bucket_count.o: htab_bucket_count.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_bucket_count.c

htab_clear.o: htab_clear.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_clear.c

htab_find.o: htab_find.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_find.c

htab_free.o: htab_free.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_free.c

htab_hash_fun.o: htab_hash_fun.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_hash_fun.c

htab_init.o: htab_init.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_init.c

htab_lookup_add.o: htab_lookup_add.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_lookup_add.c

htab_size.o: htab_size.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_size.c