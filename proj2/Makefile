# Makefile
# Autor: Tomáš Frátrik (xfratr01), FIT
# Riešenie IJC=DU2, 19.4.2022

CC=gcc
CFLAGS= -std=c11 -pedantic -Wall -Wextra


all: wordcount

wordcount: wordcount.o htab_init.o
	$(CC) $(CFLAGS) wordcount.o htab_init.o -o wordcount


wordcount.o: wordcount.c
	$(CC) -c wordcount.c

htab_init.o: htab_init.c
	$(CC) -c htab_init.c