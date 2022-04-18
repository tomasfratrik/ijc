/*
 * htab_resize.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"

/* function creates new hash table with the newn size 
 * to this new hash table we parse old items from old table, but to different indexes
 * then we clear old hash table
 * then we copy items and its positions from new table to old table
 * at the end we free new table
 */
void htab_resize(htab_t *t, size_t newn){

    htab_t *new_htab = htab_init(newn); 
    htab_item_t *item;
    for(size_t i = 0 ;i < htab_bucket_count(t); i++){ //parse from old table to new
        item = t->arr_ptr[i];
        while(item != NULL){
            for(size_t j= 0; j < item->pair->value; j++)
                htab_lookup_add(new_htab,item->pair->key);  
            item = item->next;
        }
    }   

    item = NULL;
    htab_clear(t); //clear old
    t->arr_ptr = realloc(t->arr_ptr,newn * sizeof(htab_item_t *)); //reallocate array of pointers to new size, pointers point to NULL
    t->arr_size = newn;
    for(size_t i = 0 ;i < htab_bucket_count(new_htab); i++){ //parse items from new to old
        item = new_htab->arr_ptr[i];
        while(item != NULL){
            for(size_t j= 0; j < item->pair->value; j++)
                htab_lookup_add(t,item->pair->key);  
            item = item->next;
        }
    }   
    
    htab_free(new_htab);
}

