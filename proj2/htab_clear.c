/*
 * htab_erase.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

//function goes thru all items and call erase function on them
void htab_clear(htab_t * t){

    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *curr = t->arr_ptr[i];
        htab_item_t *prev = t->arr_ptr[i];
        while(curr != NULL){ 
            if((curr == prev) && curr->next == NULL){ //function itself will free only first item
                free((char *)(curr->pair->key));
                free(curr->pair);
                free(curr);
                t->arr_ptr[i] = NULL;
                break;
            }
            curr = curr->next;
            htab_erase(t,prev->pair->key);
            prev = curr;
        }
    }
}