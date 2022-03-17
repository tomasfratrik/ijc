/*
 * primes.c
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include <stdio.h>
#include <limits.h>
#include "bitset.h"
#include "eratosthenes.h"
#define N 300000000
#define NUM_TO_PRINT 10



int main(){
    bitset_create(bit_arr,N);
    // bitset_alloc(bit_arr,N);
    Eratosthenes(bit_arr);

    unsigned long last_prime_numbers[NUM_TO_PRINT];
    int count = 0;

    //nacitam posledne cisla
    for(unsigned long i = N-1; i >= 2 ;i--){
        if(bitset_getbit(bit_arr,i) == 0){
            count++;
            last_prime_numbers[NUM_TO_PRINT-count] = i;
        }
        if(count == NUM_TO_PRINT) break;
    }
    //vypisem poslede prime cisla
    for(int i = NUM_TO_PRINT-count; i < NUM_TO_PRINT; i++){
        printf("%ld\n",last_prime_numbers[i]);
    }

    // bitset_free(bit_arr);
}