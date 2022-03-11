CC=gcc
CFLAGS=-O2 -g -std=c11 -pedantic -Wall -Wextra
SOURCE=primes.o error.o eratosthenes.o
SOURCE2=steg-decode.o error.o eratosthenes.o ppm.o


all: primes primes-i steg-decode

primes: $(SOURCE) bitset.h
	$(CC) $(CFLAGS) $(SOURCE) -o primes -lm

primes-i: $(SOURCE) bitset.o
	$(CC) $(CFLAGS) -DUSE_INLINE $(SOURCE) bitset.o -o primes-i -lm

steg-decode: $(SOURCE2) bitset.h
	$(CC) $(CFLAGS) $(SOURCE2) -o steg-decode -lm

primes.o: primes.c
	$(CC) -c primes.c

error.o: error.c error.h
	$(CC) -c error.c

eratosthenes.o: eratosthenes.c eratosthenes.h
	$(CC) -c eratosthenes.c

bitset.o: bitset.c bitset.h
	$(CC) -DUSE_INLINE -c bitset.c

steg-decode.o: steg-decode.c
	$(CC) -c steg-decode.c

ppm.o: ppm.c ppm.h
	$(CC) -c ppm.c

run: primes primes-i
	./primes
	./primes-i


# all: primes primes-i steg-decode
# run:
# 	./primes
# 	./primes-i


# primes: primes.o eratosthenes.o error.o
# 	gcc $(CFLAGS) primes.o eratosthenes.o error.o -o primes -lm

# primes.o: primes.c bitset.h
# 	gcc $(CFLAGS) -c primes.c -o primes.o

# #-primes
# eratosthenes.o: eratosthenes.c bitset.h
# 	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

# error.o: error.c error.h
# 	gcc $(CFLAGS) -c error.c -o error.o

# primes-i: primes-i.o eratosthenes.o error.o
# 	gcc $(CFLAGS) -DUSE_INLINE primes-i.o eratosthenes.o error.o -o primes-i -lm

# primes-i.o: primes.c primes.c bitset.h
# 	gcc $(CFLAGS) -c -DUSE_INLINE primes.c -o primes-i.o



# steg-decode: ppm.o steg-decode.o
# 	gcc $(CFLAGS) -c ppm.o steg-decode.o -o steg-decode
# ppm.o: ppm.c error.o ppm.h	
# 	gcc $(CFLAGS) -c ppm.c -o ppm.o

# steg-decode.o: steg-decode.c error.o ppm.o
# 	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o


clean:
	rm -f *.o primes primes-i steg-decode