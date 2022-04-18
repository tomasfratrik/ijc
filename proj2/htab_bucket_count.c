/*
 * htab_bucket_count.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include "htab.h"


size_t htab_bucket_count(const htab_t * t){
    return t->arr_size;
}