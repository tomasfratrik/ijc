/*
 * htab_find.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include "htab.h"

htab_pair_t * htab_find(htab_t *t, htab_key_t key){
    uint32_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *curr = t->arr_ptr[index];

    while(curr != NULL){
        if(strcmp(curr->pair->key,key) ==0){
            return curr->pair;
        }
        curr = curr->next;
    }
    return NULL;

}
