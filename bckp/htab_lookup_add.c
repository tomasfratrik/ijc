/*
 * htab_lookup_add.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */


#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"

htab_item_t *htab_item_ctor(htab_key_t key){
    htab_item_t *item = malloc(sizeof(htab_item_t));
    item->pair  = malloc(sizeof(htab_pair_t));
    // htab_pair_t *pair = malloc(sizeof(htab_pair_t));
    char *string = calloc(strlen(key)+1, sizeof(char));
    strcpy(string,key);
    item->pair->key = string;
    item->pair->value = 1;
    item->next = NULL;
    // pair->key = string;
    // pair->value = 1;
    // item->pair = pair;
    // item->next = NULL;
}


htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key){
    // printf("Key: %s\n",key);
    uint32_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *curr = t->arr_ptr[index];


    while(curr != NULL){
        // curr->pair = curr->pair;
        if(!strcmp(curr->pair->key,key)){
            curr->pair->value++;
            return curr->pair;
        }
        if(curr->next == NULL) break;
        curr = curr->next;
    }

    t->size++;
    htab_item_t *item = htab_item_ctor(key);
    if(t->arr_ptr[index] == NULL){
        t->arr_ptr[index] = item;
    }
    else{
        curr->next = item;
    }
    return item->pair;
}