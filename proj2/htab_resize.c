/*
 * htab_resize.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"


void htab_array_erase( htab_item_t* (*old_ptr), size_t size){

    htab_item_t *curr;
    htab_item_t *prev;
    for(size_t i = 0; i< size;i++){
        if(old_ptr[i] == NULL)
            continue;
        curr = old_ptr[i];
        prev = old_ptr[i];
        while(curr != NULL){
            if((curr == prev) && curr->next == NULL){
                free(curr->pair);
                free(curr);
                 old_ptr[i] = NULL;
                 break;

            }
            if(curr->next != NULL){
                prev = curr;
                curr = curr->next;
                continue;
            }
            prev->next = curr->next;
            free(curr->pair); 
            free(curr);
            curr = old_ptr[i];
            prev = old_ptr[i];
        }
    }

}

void print_array(htab_item_t **array, size_t size){
    printf("\n");
    printf("/************ ARRAY ************/\n");
    for(int i = 0; i < size;i++){
        if(array[i] == NULL){
            printf("%d \t ---\n",i);
        }
        else{
            htab_item_t *curr = array[i];
            printf("%d \t ",i);
            while(curr != NULL){
                printf("[%s,%d]",curr->pair->key, curr->pair->value);
                if(curr->next != NULL) printf("->");
                curr = curr->next;
            }
            printf("\n");

        }
    }
    printf("/************************************/\n");
    printf("\n");
}

htab_item_t *item_ctor(htab_key_t key){
    htab_item_t *item = malloc(sizeof(htab_item_t));
    item->pair = malloc(sizeof(htab_pair_t));
    // item->pair->key = calloc(strlen(key)+1, sizeof(char));

    item->pair->value = 1;
    item->pair->key = key;
    item->next = NULL;
    
    return item;

}

void array_add(htab_item_t **array,size_t size,htab_key_t key){
    uint32_t index = (htab_hash_function(key) % size);
    htab_item_t *curr = array[index];
    array[index]= item_ctor(key);
}


// htab_item_t *htab_create_item(htab_key_t key){
    
//     htab_item_t *item = malloc(sizeof(htab_item_t));
//     item->pair = malloc(sizeof(htab_pair_t));
//     // item->pair->key = calloc(strlen(key)+1, sizeof(char));

//     item->pair->value = 1;
//     item->pair->key = key;
//     item->next = NULL;
    
//     return item;

// }

// htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key){
//     // printf("Key: %s\n",key);
//     uint32_t index = (htab_hash_function(key) % t->arr_size);
//     htab_item_t *curr = t->arr_ptr[index];


//     while(curr != NULL){
//         // curr->pair = curr->pair;
//         if(strcmp(curr->pair->key,key) ==0){
//             curr->pair->value++;
//             return curr->pair;
//         }
//         if(curr->next == NULL) break;
//         curr = curr->next;
//     }

//     t->size++;
//     htab_item_t *item = htab_create_item(key);
//     if(t->arr_ptr[index] == NULL){
//         t->arr_ptr[index] = item;
//     }
//     else{
//         curr->next = item;
//     }
//     return item->pair;
// }

void htab_resize(htab_t *t, size_t newn){
// t->arr_ptr

    htab_item_t* (*old_ptr) = t->arr_ptr;
    htab_item_t **new_arr_ptr = malloc(newn*sizeof(htab_item_t*));

    for(size_t i = 0; i< newn;i++){
        new_arr_ptr[i] = NULL;
    }


    for (size_t i = 0; i<htab_bucket_count(t); i++){
        htab_item_t *curr = t->arr_ptr[i];
        while(curr != NULL){
            array_add(new_arr_ptr,newn,curr->pair->key);
            curr = curr->next;
        }
    }


    // t->arr_ptr = new_arr_ptr;






    print_array(new_arr_ptr,newn);

    htab_array_erase(old_ptr,htab_bucket_count(t));

}
