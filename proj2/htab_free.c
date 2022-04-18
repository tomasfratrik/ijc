/*
 * htab_free.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"

void htab_free(htab_t * t){

    htab_clear(t);
    t->arr_size=0;
    t->size = 0;
    free(t->arr_ptr);
    free(t);

}