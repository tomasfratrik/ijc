/*
 * eratosthenes.c
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include "bitset.h"
#include <math.h>

void Eratosthenes(bitset_t bitset_arr){
    
    unsigned long zero = 0;
    unsigned long one = 1;
    bitset_setbit(bitset_arr,zero, 1);
    bitset_setbit(bitset_arr,one , 1);
    unsigned long size = sqrt(bitset_size(bitset_arr));
    
    //implementacia eratosthenesovo sita
    for(unsigned long i = 2; i <= size;i++){
        if(bitset_getbit(bitset_arr,i) == 0){
            for(unsigned long n = 2; n*i <  bitset_size(bitset_arr);n++){
                bitset_setbit(bitset_arr,n*i,1);
            }
        }
    }


}