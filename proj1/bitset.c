/*
 * bitset.c
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */
#include"bitset.h"


#ifndef USE_INLINE
#else
extern inline void bitset_free(bitset_t jmeno_pole);
extern inline bitset_index_t bitset_size(bitset_t jmeno_pole);
extern inline int bitset_getbit(bitset_t jmeno_pole, bitset_index_t index);
extern inline void bitset_setbit(bitset_t jmeno_pole, bitset_index_t index, int vyraz);

#endif