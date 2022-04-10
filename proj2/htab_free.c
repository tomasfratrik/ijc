/*
 * htab_free.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */


#include<stdio.h>
#include<stdlib.h>
#include "htab.h"

void htab_free(htab_t * t){

    htab_clear(t);
    free(t);

}