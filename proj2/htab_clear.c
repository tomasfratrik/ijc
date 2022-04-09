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

    for(int i = 0; i < t->arr_size; i++){
        htab_item_t *item = t->arr_ptr[i];
        htab_item_t *item_next = t->arr_ptr[i]->next;
        while(item != NULL){
            if(item_next != NULL){
                free(item->pair);
                free(item);
            }
            else{
                free(item->pair);
                free(item);
            }
            item = item_next
            item_next = item_next->next;
        }
        t->arr_ptr[i] = NULL;
    }    
}