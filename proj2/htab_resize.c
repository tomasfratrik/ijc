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


//reason for making this copypasted lookup_add
//is that this lookup_add doesnt check for min and max (if it did it could call resize again, and resize calls lookup_add)
//therefore it cannot get to infinite cycle

htab_pair_t *htab_ownlookup_add(htab_t *t, htab_key_t key){
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
                htab_ownlookup_add(new_htab,item->pair->key);  
            item = item->next;
        }
    }   

    item = NULL;
    htab_clear(t); //clear old
    t->arr_ptr = realloc(t->arr_ptr,newn * sizeof(htab_item_t *)); //reallocate array of pointers to new size
    t->size = 0;
    t->arr_size = newn;
    for(size_t i = 0; i < t->arr_size; i++){
        t->arr_ptr[i] = NULL;
    }
    for(size_t i = 0 ;i < htab_bucket_count(new_htab); i++){ //parse items from new to old
        item = new_htab->arr_ptr[i];
        while(item != NULL){
            for(size_t j= 0; j < item->pair->value; j++)
                htab_ownlookup_add(t,item->pair->key);  
            item = item->next;
        }
    }   
    
    htab_free(new_htab);
}

