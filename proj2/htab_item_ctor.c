/*
 * htab_item_ctor.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"
#include "error.h"


//function that allocates new item and returns pointer to it
htab_item_t *htab_item_ctor(htab_key_t key){
    htab_item_t *item = malloc(sizeof(htab_item_t));
    item->pair  = malloc(sizeof(htab_pair_t));

    if(item == NULL || item->pair == NULL)
        error_exit("Couldnt allocate new item in htab_item_ctor.c !");

    char *string = calloc(strlen(key)+1, sizeof(char));
    strcpy(string,key);
    item->pair->key = string;
    item->pair->value = 0;
    item->next = NULL;
    return item;
}