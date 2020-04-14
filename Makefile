# Makefile
# Řešení IJC-DU2, příklad b), 14.4.2020
# Autor: Vojtech Maslan, FIT

CC=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra 

all: tail wordcount libhtab.a

tail: tail.c
	$(CC) $(CFLAGS) -o tail tail.c

wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGS) $^ -o wordcount

wordcount.o: wordcount.c
	$(CC) $(CFLAGS) -c wordcount.c

io.o: io.c io.h
	$(CC) $(CFLAGS)  -c io.c

libhtab.a: htab_bucket_count.o htab_clear.o htab_find.o htab_free.o htab_hash_fun.o htab_init.o htab_lookup_add.o htab_size.o htab_iterator_get_value.o htab_end.o htab_iterator_set_value.o htab_erase.o htab_iterator_get_key.o htab_iterator_next.o htab_begin.o
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

htab_iterator_get_value.o: htab_iterator_get_value.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_get_value.c

htab_end.o: htab_end.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_end.c

htab_iterator_set_value.o: htab_iterator_set_value.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_set_value.c

htab_erase.o: htab_erase.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_erase.c

htab_iterator_get_key.o: htab_iterator_get_key.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_get_key.c

htab_iterator_next.o: htab_iterator_next.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_iterator_next.c

htab_begin.o: htab_begin.c htab.h structs_dec.h
	$(CC) $(CFLAGS) -fPIC -c htab_begin.c
