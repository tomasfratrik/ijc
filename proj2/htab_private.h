 /*
 * htab_private.h
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */


#ifndef __HTAB_PRIVATE_H__
#define __HTAB_PRIVATE_H__

#include <string.h>     
#include <stdbool.h>  
#include "htab.h"

struct htab;
struct htab_item;
struct htab_pair;

typedef struct htab {
    unsigned long int size;
    unsigned long int arr_size;
    struct htab_item **arr_ptr;
}htab_t;     

typedef struct htab_item{
    int test;
    struct htab_item *next;
    struct htab_pair *pair;
}htab_item_t;

void print_htab(htab_t *table);
htab_item_t *htab_item_ctor(htab_key_t key);

#endif // __HTAB_PRIVATE_H__