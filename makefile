# makefile
# Autor: Tomáš Frátrik (xfratr01), FIT
# Riešenie IJC=DU1, 20.3.2022
 

CC=gcc
CFLAGS= -O2 -g -std=c11 -pedantic -Wall -Wextra

#all
all: primes primes-i steg-decode

#main
primes: primes.o error.o eratosthenes.o bitset.h
	$(CC) $(CFLAGS) primes.o error.o eratosthenes.o -o primes -lm

primes-i: primes.o error.o eratosthenes.o bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE primes.o error.o eratosthenes.o bitset.o -o primes-i -lm

steg-decode: steg-decode.o error.o eratosthenes.o ppm.o bitset.h
	$(CC) $(CFLAGS) steg-decode.o error.o eratosthenes.o ppm.o -o steg-decode -lm


#.o
primes.o: primes.c
	$(CC) -c primes.c

bitset.o: bitset.c bitset.h
	$(CC) -DUSE_INLINE -c bitset.c

error.o: error.c error.h
	$(CC) -c error.c

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) -c eratosthenes.c

ppm.o: ppm.c ppm.h
	$(CC) -c ppm.c

steg-decode.o: steg-decode.c
	$(CC) -c steg-decode.c


#others
run: primes primes-i
	./primes
	./primes-i

clean:
	rm -f *.o primes primes-i steg-decode

zip:
	clean
	xfratr01.zip *.c *.h makefile