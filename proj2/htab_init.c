/*
 * htab_init.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */


#include<stdio.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"
#include "error.h"


//initialize and allocate new hashtable and set arr_size to n;
htab_t *htab_init(size_t n){
    htab_t *hash_table;
    hash_table = malloc(sizeof(htab_t));

    if(hash_table == NULL)
        return NULL;

    hash_table->arr_ptr = calloc(n,sizeof(htab_item_t*));
    hash_table->arr_size = n;
    hash_table->size = 0;

    
    //init pointers to NULL
    for(size_t i = 0; i < n; i++){
        hash_table->arr_ptr[i] = NULL;
    }
    return hash_table;
}
