/*
 * htab_size.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */


#include<stdio.h>
#include "htab.h"


size_t htab_size(const htab_t * t){
    return t->size;
}