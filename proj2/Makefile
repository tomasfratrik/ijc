# Makefile
# Author: Tomáš Frátrik (xfratr01), FIT
# Solution to IJC=DU2, 19.4.2022

CC=gcc
CFLAGS=  -std=c11 -pedantic -Wall -Wextra -Werror
HTAB_SOURCE= error.o htab_item_ctor.o htab_for_each.o wordcount.o htab_init.o htab_hash_function.o htab_lookup_add.o htab_erase.o htab_find.o htab_free.o htab_clear.o htab_size.o htab_bucket_count.o htab_resize.o


all: tail wordcount wordcount-dynamic

wordcount: wordcount.o io.o libhtab.a print_htab.o
	$(CC) $(CFLAGS) -o wordcount -static wordcount.o io.o print_htab.o -L. -lhtab
wordcount-dynamic: wordcount.o io.o libhtab.so print_htab.o
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o io.o  print_htab.o -L. -lhtab 

libhtab.a: $(HTAB_SOURCE)
	ar rcs libhtab.a $^
	
libhtab.so: $(HTAB_SOURCE)
	$(CC) $(CFLAGS) -shared -o  libhtab.so $^

%.o : %.c 
	$(CC) $(CFLAGS) -c -fPIC  $<

tail: tail.o error.o
	$(CC) $(CFLAGS) $^  -o  $@

run: 
	./wordcount
	LD_LIBRARY_PATH="." ./wordcount-dynamic

clean:
	rm -f *.o tail wordcount wordcount-dynamic libhtab.a libhtab.so


zip: *.c *.h Makefile
	zip xfratr01.zip *.c *.h Makefile