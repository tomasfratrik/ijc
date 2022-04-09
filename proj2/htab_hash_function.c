/*
 * htab_hash_function.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include"htab.h"


/* 
 * Implementation of hash funcion sdbm
 * Source: http://www.cse.yorku.ca/~oz/hash.html
 * (funcion return) % arr_size = hash table index
 */
size_t htab_hash_function(const char *str) {
    uint32_t h=0;
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}