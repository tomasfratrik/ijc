/*
 * htab_erase.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// #include<stdint.h>
#include "htab.h"


void htab_clear(htab_t * t){

    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *curr = t->arr_ptr[i];
        htab_item_t *prev = t->arr_ptr[i];
        while(curr != NULL){
            curr = curr->next;
            htab_erase(t,prev->pair->key);
            prev = curr;
        }
    }
}