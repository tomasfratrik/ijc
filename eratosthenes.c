/*
 * eratosthenes.c
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include "bitset.h"
#include<math.h>

void Eratosthenes(bitset_t bitset_arr){
    
    unsigned long zero = 0;
    unsigned long one = 1;
    bitset_setbit(bitset_arr,zero, 1);
    bitset_setbit(bitset_arr,one , 1);
    // unsigned long cislo = 1;
    // unsigned long idx = 301;
    // bitset_setbit(bitset_arr,idx,cislo);
    // bitset_getbit(bitset_arr,idx);
    

    for(unsigned long i = 2; i <= sqrt(bitset_size(bitset_arr));i++){
        if(bitset_getbit(bitset_arr,i) == 0){
            for(unsigned long n = 2; n*i <  bitset_size(bitset_arr);n++){
                bitset_setbit(bitset_arr,n*i,1);
            }
        }
    }


}