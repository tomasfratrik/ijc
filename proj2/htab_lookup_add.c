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


// void htab_alloc_item()

htab_pair_t * htab_add(htab_t *t,htab_key_t key){
  uint32_t index = (htab_hash_function(key) % t->arr_size);

    if(t->arr_ptr[index] == NULL){
        t->arr_ptr[index] = malloc(sizeof(htab_item_t));
        t->arr_ptr[index]->pair = malloc(sizeof(htab_pair_t));
        htab_item_t *item = t->arr_ptr[index];
        htab_pair_t *pair = item->pair;
        pair->value = 1;
        pair->key = key;
        t->size++;
        return pair;
    }

    htab_item_t *curr = t->arr_ptr[index];
    while(curr != NULL){
        curr->pair = curr->pair;
        if(strcmp(curr->pair->key,key) ==0){
            curr->pair->value++;
            return curr->pair;
        }
        if(curr->next == NULL) break;
        curr = curr->next;
    }


        t->size++;
        htab_item_t *item = malloc(sizeof(htab_item_t));
        item->pair = malloc(sizeof(htab_pair_t));
        item->pair->value = 1;
        item->pair->key = key;
        curr->next = item;
        return curr->pair;

}

htab_pair_t * htab_lookup_add(htab_t *t, htab_key_t key){
        uint32_t index = (htab_hash_function(key) % t->arr_size);

        if(t->arr_ptr[index] == NULL){
            htab_pair_t *pair = htab_add(t,key);
            return pair;
        }
        htab_item_t *item = t->arr_ptr[index];
        htab_item_t *curr = item;
        htab_pair_t *pair = curr->pair;

        while(curr != NULL){
            pair = curr->pair;
            if(strcmp(pair->key,key) ==0){
                return pair;
            } 
            curr = curr->next;
        }
        pair = htab_add(t,key);
        return pair;
        // while(strcmp(pair->key,key))

        // if(strcmp(t->arr_ptr[index],key) == 0)

}