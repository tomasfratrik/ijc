# Makefile
# Autor: Tomáš Frátrik (xfratr01), FIT
# Riešenie IJC=DU2, 19.4.2022

CC=gcc
CFLAGS=  -std=c11 -pedantic -Wall -Wextra -Werror
SOURCE= error.o htab_for_each.o io.o wordcount.o htab_init.o htab_hash_function.o htab_lookup_add.o htab_erase.o htab_find.o htab_free.o htab_clear.o htab_size.o htab_bucket_count.o htab_resize.o

all: wordcount

wordcount: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o  wordcount


wordcount.o: wordcount.c htab.h
	$(CC) -c wordcount.c

htab_init.o: htab_init.c 
	$(CC) -c htab_init.c

htab_hash_function.o: htab_hash_function.c 
	$(CC) -c htab_hash_function.c
	
htab_lookup_add.o: htab_lookup_add.c
	$(CC) -c htab_lookup_add.c

htab_find.o: htab_find.c
	$(CC) -c htab_find.c
	
htab_erase.o: htab_erase.c
	$(CC) -c htab_erase.c

htab_free.o: htab_free.c
	$(CC) -c htab_free.c
htab_clear.o: htab_clear.c
	$(CC) -c htab_clear.c

htab_size.o: htab_size.c
	$(CC) -c htab_size.c

htab_bucket_count.o: htab_bucket_count.c
	$(CC) -c htab_bucket_count.c

htab_resize.o: htab_resize.c
	$(CC) -c htab_resize.c

io.o: io.c io.h
	$(CC) -c io.c

htab_for_each.o: htab_for_each.c
	$(CC) -c htab_for_each.c

error.o: error.c error.h
	$(CC) -c error.c