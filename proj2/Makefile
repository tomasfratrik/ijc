# Makefile
# Autor: Tomáš Frátrik (xfratr01), FIT
# Riešenie IJC=DU2, 19.4.2022

CC=gcc
CFLAGS= -g -std=c11 -pedantic -Wall -Wextra
SOURCE= wordcount.o htab_init.o htab_hash_function.o htab_lookup_add.o htab_erase.o htab_find.o

all: wordcount

wordcount: $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o wordcount


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