/*
 * htab_erase.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include "htab.h"
#include "htab_private.h"
#define AVG_LEN_MIN 0.2 //20%


//function to erase item and free its memory
bool htab_erase(htab_t * t, htab_key_t key){


    uint32_t index = (htab_hash_function(key) % htab_bucket_count(t)); // find index in table
    htab_item_t *curr = t->arr_ptr[index];
    htab_item_t *prev = t->arr_ptr[index];
    while(curr != NULL){ //if there is NULL pointer return false
        if(strcmp(curr->pair->key,key)==0){ //found key
            if(prev == curr){
                t->arr_ptr[index] = curr->next;
            }
            //curr is found item
            //set prev item to point where curr was pointing
            prev->next = curr->next; 
            free((char *)(curr->pair->key)); //free all allocated memmory in item
            free(curr->pair); 
            free(curr);
            t->size--;
            return true;
            double avg = (double)htab_size(t) / htab_bucket_count(t);
            if(AVG_LEN_MIN > avg){
                htab_resize(t,(htab_bucket_count(t)/2));
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}
