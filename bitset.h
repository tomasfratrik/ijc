/*
 * bitset.h
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include"error.h"

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long bitset_t;
typedef unsigned long bitset_index_t;

#define BITS(x) sizeof(x) *CHAR_BIT


#define bitset_create(jmeno_pole,size) bitset_t jmeno_pole[size / (BITS(unsigned long)) + ((size %(BITS(unsigned long))) == 0 ? 1 : 2 )] = {size,0}

#define bitset_alloc(jmeno_pole, size) bitset_t* jmeno_pole = calloc(size / (BITS(unsigned long)) + ((size %(BITS(unsigned long))) == 0 ? 1 : 2 ), sizeof(unsigned long));\
    if(jmeno_pole == NULL){\
        error_exit("bitset_alloc: Chyba alokace paměti");\
    }\
    jmeno_pole[0] = size;



#ifndef USE_INLINE

#define bitset_size(jmeno_pole) jmeno_pole[0]
#define bitset_free(jmeno_pole) free(jmeno_pole)
#define bitset_getbit2(jmeno_pole,index) ((jmeno_pole[(index/((BITS(unsigned long))))+1] >> index ) & 1UL)
#define bitset_getbit(jmeno_pole,index)  (index > bitset_size(jmeno_pole)) ? bitset_getbit2(jmeno_pole,index) : bitset_getbit2(jmeno_pole,index)
#define bitset_setbit2(jmeno_pole,index,vyraz) (vyraz) ? (jmeno_pole[(index/((BITS(unsigned long))))+1]) |= 1UL << index : ((jmeno_pole[(index/((BITS(unsigned long))))+1])  &= ~(1UL << index))
#define bitset_setbit(jmeno_pole,index,vyraz) (index > bitset_size(jmeno_pole)) ? (void)(error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole))) : (void)(bitset_setbit2(jmeno_pole,index,vyraz))

#else // USE_LINE is defined

    static inline void bitset_free(bitset_t* jmeno_pole){
        free(jmeno_pole);
    }

    static inline bitset_index_t bitset_size(bitset_t *jmeno_pole){
        return jmeno_pole[0];
    }

    static inline int bitset_getbit(bitset_t *jmeno_pole, bitset_index_t index){
        if(index > bitset_size(jmeno_pole)){
            // printf("error msg");
        }
        int bit = (jmeno_pole[(index/((BITS(unsigned long))))+1] >> index ) & 1UL;
        printf("xd ");
        return bit;
    }

    static inline void bitset_setbit(bitset_t *jmeno_pole, bitset_index_t index, int vyraz){
        if(index > bitset_size(jmeno_pole)){
            if(vyraz){
                (jmeno_pole[(index/((BITS(unsigned long))))+1]) |= 1UL << index;
            }
            else{
                ((jmeno_pole[(index/((BITS(unsigned long))))+1])  &= ~(1UL << index));
            }
        }
        else{
            printf("error msg");
        }
    }

#endif
#endif