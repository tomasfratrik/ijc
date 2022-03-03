
 # makefile
 # Riešenie IJC=DU1, priklad a), 20.3.2022
 # Autor: Tomáš Frátrik (xfratr01), FIT
 # Preložene: gcc 9.3.0

CC=gcc
CFLAGS= -O2 -g -std=c11 -pedantic -Wextra -Wall

all: primes primes-i
#steg-decode: steg-decode.c eratosthenes.c ppm.c ppm.h error.c bit-array.h
#	$(CC) $(CFLAGS) steg-decode.c -o steg-decode


primes.o: primes.c bitset.h eratosthenes.h
error.o: error.c error.h
eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h


primes: primes.o eratosthenes.o error.o eratosthenes.h
		$(CC) $(CFLAGS) error.o primes.o eratosthenes.o -o $@ -lm

primes-i: primes.o eratosthenes.o error.o eratosthenes.h
	$(CC) $(CFLAGS) -DUSE_INLINE error.o primes.o eratosthenes.o -o $@ -lm


clean:
	rm -f *.o 