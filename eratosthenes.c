/*
 * eratosthenes.c
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include "bitset.h"
#include <math.h>

void Eratosthenes(bitset_t bitset_arr){
    
    //nastavime cisla 0 a 1 ze su neni prvocislami
    bitset_setbit(bitset_arr,1UL, 1);
    bitset_setbit(bitset_arr,0UL, 1);
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