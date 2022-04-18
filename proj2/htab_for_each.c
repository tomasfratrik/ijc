/*
 * htab_for_each.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"



//function goes thru all items and calls on them function f
// f returns nothing and parses pointer to htab_pair_t as an argument
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    int cntr =  0;
    for(int i = 0; i < htab_bucket_count(t);i++){
        htab_item_t *curr = t->arr_ptr[i];
        while(curr != NULL){
            if(!cntr){ //if it is first item
                (*f)(t->arr_ptr[i]->pair);
                curr = curr->next;
                cntr = 1;
                continue;
            }
            (*f)(curr->pair);
            curr = curr->next;
            cntr = 1;
        }
    }

}