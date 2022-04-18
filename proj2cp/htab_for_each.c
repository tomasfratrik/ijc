/*
 * htab_for_each.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"




void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){

    int counter = 0;
    for(int i = 0; i < htab_bucket_count(t);i++){
        counter = 0;
        htab_item_t *curr = t->arr_ptr[i];
        while(curr != NULL){
            if(counter == 0){
                (*f)(t->arr_ptr[i]->pair);
                counter = 1;
                curr = curr->next;
                continue;
            }
            (*f)(curr->pair);
            curr = curr->next;
        }
    }

}