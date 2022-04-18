/*
 * htab_lookup_add.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"

//function adds new item if key wasnt found, or increments value by 1 if it founds the key
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key){
    uint32_t index = (htab_hash_function(key) % htab_bucket_count(t)); //find index
    htab_item_t *curr = t->arr_ptr[index];


    while(curr != NULL){ //if there is at least 1 item already
        if(!strcmp(curr->pair->key,key)){ //found key
            curr->pair->value++;
            return curr->pair;
        }
        if(curr->next == NULL) break;
        curr = curr->next;
    }

    t->size++;
    htab_item_t *item = htab_item_ctor(key);
    if(t->arr_ptr[index] == NULL){ //if it is first item
        t->arr_ptr[index] = item;
    }
    else{
        curr->next = item;
    }
    return item->pair;
}