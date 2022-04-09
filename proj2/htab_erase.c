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

bool htab_erase(htab_t * t, htab_key_t key){
    uint32_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *curr = t->arr_ptr[index];
    htab_item_t *curr_next = t->arr_ptr[index]->next;


    //check first
    if(strcmp(curr->pair->key,key) ==0){
        if(curr_next == NULL)
            t->arr_ptr[index] = NULL;            
        else
            t->arr_ptr[index] = t->arr_ptr[index]->next;
        return true;
    }



    //check others
    while(curr != NULL){
        if(curr_next != NULL){
            if(strcmp(curr_next->pair->key,key) ==0){
                curr->next = curr_next->next;
                return true;
            }
        }
        else return false;

        curr_next = curr_next->next;
        curr = curr->next;
    }
    return false;

}