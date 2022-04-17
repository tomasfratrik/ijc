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


// htab_item_t *htab_item_free(htab_item_t *item)
// {
//     if (item == NULL)
//         return NULL;

//     // uklada si ukazatel na dalsi zaznam, ktery vraci
//     htab_item_t *next = item->next;
//     // free((char *)(item->pair->key));
//     free(item->pair);
//     free(item);
//     return next;
// }


bool htab_erase(htab_t * t, htab_key_t key){


    uint32_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *curr = t->arr_ptr[index];
    htab_item_t *prev = t->arr_ptr[index];
    
    
    while(curr != NULL){
        if(strcmp(curr->pair->key,key)==0){
            if(prev == curr){
                t->arr_ptr[index] = curr->next;
            }
            prev->next = curr->next;
            // free((char *)curr->pair->key);
            free(curr->pair); 
            free(curr);
            t->size--;
            return true;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

//   uint32_t index = (htab_hash_function(key) % t->arr_size);
//     htab_item_t *curr = t->arr_ptr[index];
//     htab_item_t *prev = t->arr_ptr[index];
    
    
//     while(curr != NULL){
//         if(strcmp(curr->pair->key,key)==0){
//             if(prev == curr);{
//                 t->arr_ptr[index] = curr->next;
//             }
//             prev->next = curr->next;
//             free(curr->pair); 
//             free(curr);
//             t->size--;
//             return true;
//         }
//         else{
//             prev = curr;
//             curr = curr->next;
//         }
//     }
//     return false;