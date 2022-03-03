
 # makefile
 # Riešenie IJC=DU1, priklad a), 20.3.2022
 # Autor: Tomáš Frátrik (xfratr01), FIT
 # Preložene: gcc 9.3.0



CC=gcc
CFLAGS= -O2 -g -std=c11 -lm  -pedantic -Wextra -Wall

all: primes

#steg-decode: steg-decode.c eratosthenes.c ppm.c ppm.h error.c bit-array.h
#	$(CC) $(CFLAGS) steg-decode.c -o steg-decode

primes: primes.o eratosthenes.o bitset.o error.o
	$(CC) $(CFLAGS) primes.o error.o bitset.o eratosthenes.o -o primes -lm

primes.o: primes.c
	$(CC) $(CFLAGS) -c primes.c  -o primes.o

eratosthenes.o: eratosthenes.c
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c
	$(CC) $(CFLAGS) -c error.c -o error.o

bit_array.o: bitset.h
	$(CC) $(CFLAGS) -c bitset.h -o bitset.h

#primes: primes.c eratosthenes.c 
#	$(CC) $(CFLAGS) eratosthenes.c -o eratosthenes
#	$(CC) $(CFLAGS) primes.c -o primes
#	$(CC) $(CFLAGS) -DUSE_INLINE prvocisla.c -o prvocisla-inline
	
#clean:
#	rm -f steg-decode prvocisla prvocisla-inline xnechu01.zip

#zip: *.c *.h Makefile
#	zip xfratr01.zip *.c *.h Makefile