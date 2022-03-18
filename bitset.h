/*
 * bitset.h
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include"error.h"


//10 miliard
#define UPPER_LIMIT 10000000000

#ifndef BITSET_H
#define BITSET_H

typedef unsigned long *bitset_t;
typedef unsigned long bitset_index_t;

#define BITS(x) sizeof(x) *CHAR_BIT

//Alokujeme velikost / velkost unsigned long == kolko krat sa tam zmesti unsigned long
// + musim zaratat cely unsigned long aj ked alokujem menej ako unsigned long bitov
// + musim alokovat 1 miesto na zaciatku kde ulozim velkost
#define bitset_create(jmeno_pole,velikost) static_assert(velikost > 0 && velikost < UPPER_LIMIT ,"Pocet bitov musi byt vacsi ako 0"); \
    bitset_index_t jmeno_pole[velikost / (BITS(unsigned long)) + ((velikost %(BITS(unsigned long))) == 0 ? 1 : 2 )] = {velikost,0}
    

//calloc pre vynulovanie
#define bitset_alloc(jmeno_pole, velikost) assert((velikost > 0 && velikost < UPPER_LIMIT,"Pocet bitov musi byt vacsi ako 0")); \
    bitset_index_t *jmeno_pole = calloc(velikost / (BITS(unsigned long)) + ((velikost %(BITS(unsigned long))) == 0 ? 1 : 2 ), sizeof(unsigned long));\
    if(jmeno_pole == NULL){\
        error_exit("bitset_alloc: Chyba alokace paměti\n");\
    }\
    jmeno_pole[0] = velikost;



#ifndef USE_INLINE

#define bitset_size(jmeno_pole) jmeno_pole[0]
#define bitset_free(jmeno_pole) free(jmeno_pole)

#define bitset_getbit(jmeno_pole,index)  (index > bitset_size(jmeno_pole))\
    ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole))),0 \
    : ((jmeno_pole[(index/((BITS(unsigned long))))+1] >> index ) & 1UL)

#define bitset_setbit2(jmeno_pole,index,vyraz) (vyraz) ? (jmeno_pole[(index/((BITS(unsigned long))))+1]) |= 1UL << index : ((jmeno_pole[(index/((BITS(unsigned long))))+1])  &= ~(1UL << index))
#define bitset_setbit(jmeno_pole,index,vyraz) (index > bitset_size(jmeno_pole))\
    ? (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole))),0\
    : (bitset_setbit2(jmeno_pole,index,vyraz))


//Ak USE_INLINE je def.
#else
    inline void bitset_free(bitset_t jmeno_pole){
        free(jmeno_pole);
    }

    inline bitset_index_t bitset_size(bitset_t jmeno_pole){
        return jmeno_pole[0];
    }

    inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index){
        if(index > bitset_size(jmeno_pole)){
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole));
        }
        int bit = (jmeno_pole[(index/((BITS(unsigned long))))+1] >> index ) & 1UL;
        return bit;
    }

    inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz){
        if(index > bitset_size(jmeno_pole)){
            error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu",(unsigned long)index, (unsigned long)bitset_size(jmeno_pole));
        }
        else{
            if(vyraz){
                (jmeno_pole[(index/((BITS(unsigned long))))+1]) |= 1UL << index;
            }
            else{
                (jmeno_pole[(index/((BITS(unsigned long))))+1])  &= ~(1UL << index);
            }
        }
    }

#endif

#endif