CC=gcc
CFLAGS= -O2 -g -std=c11 -Wextra -Wall -pedantic  -Werror

all: primes primes-i

primes: primes.o eratosthenes.o error.o
	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes -lm

primes.o: primes.c bitset.h
	gcc $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c primes.c bitset.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

error.o: error.c error.h error.h
	gcc $(CFLAGS) -c error.c -o error.o




primes-i: primes-i.o eratosthenes-i.o error.o
	gcc $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes-i.o error.o -o primes-i -lm

primes-i.o: primes.c primes.c bitset.h
	gcc $(CFLAGS) -c -DUSE_INLINE primes.c -o primes-i.o
	
eratosthenes-i.o: eratosthenes.c primes.c bitset.h
	gcc $(CFLAGS) -c -DUSE_INLINE eratosthenes.c -o eratosthenes-i.o
	

clean:
	rm -f *.o 