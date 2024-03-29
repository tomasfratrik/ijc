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
    htab_pair_t *pair;
    for(size_t i = 0 ;i < htab_bucket_count(t); i++){ //parse from old table to new
        item = t->arr_ptr[i];
        while(item != NULL){
            for(int j= 0; j < item->pair->value; j++){
                pair = htab_lookup_add(new_htab,item->pair->key);  
                pair->value = item->pair->value;
            }
            item = item->next;
        }
    }   

    item = NULL;
    htab_clear(t); //clear old
    t->arr_ptr = realloc(t->arr_ptr,newn * sizeof(htab_item_t *)); //reallocate array of pointers to new size
    if(t->arr_ptr == NULL){

    }
    t->size = 0;
    t->arr_size = newn;
    for(size_t i = 0; i < t->arr_size; i++){
        t->arr_ptr[i] = NULL;
    }
    for(size_t i = 0 ;i < htab_bucket_count(new_htab); i++){ //parse items from new to old
        item = new_htab->arr_ptr[i];
        while(item != NULL){
            for(int j= 0; j < item->pair->value; j++){
                pair = htab_lookup_add(t,item->pair->key);  
                pair->value = item->pair->value;
            }
            item = item->next;
        }
    }   
    
    htab_free(new_htab);
}

