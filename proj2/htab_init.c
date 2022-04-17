/*
 * htab_init.c
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<stdlib.h>
#include "htab.h"

htab_t *htab_init(size_t n){
    htab_t *hash_table;
    hash_table = malloc(sizeof(htab_t)+n*sizeof(htab_item_t*));
    
    // hash_table = malloc(sizeof(htab_t));
    // hash_table->arr_ptr = malloc(n*sizeof(htab_item_t));
    if(hash_table == NULL){
        return NULL;
    }
    hash_table->arr_size = n;
    hash_table->size = 0;
    //init pointers to NULL
    for(int i = 0; i < n; i++){
        // hash_table->arr_ptr[i] = malloc(sizeof(htab_item_t));
        hash_table->arr_ptr[i] = NULL;
    }
    return hash_table;
}
