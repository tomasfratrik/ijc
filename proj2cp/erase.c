

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include "htab.h"




htab_item_t *htab_item_free(htab_item_t *item)
{
    if (item == NULL)
        return NULL;

    // uklada si ukazatel na dalsi zaznam, ktery vraci
    htab_item_t *next = item->next;
    // free((char *)(item->pair->key));
    free(item->pair);
    free(item);
    return next;
}

bool htab_erase(htab_t * t, htab_key_t key){

      size_t index = htab_hash_function(key) % t->arr_size;
    bool ret_val = false;
    
    htab_item_t *item = t->arr_ptr[index];
    if (item != NULL)
    {
        // hledany prvek je ten prvni
        if (!strcmp(item->pair->key, key))
        {
            item = htab_item_free(item);
            (t->size)--;
            ret_val = true;
        }
        else
        {
            // pruchod vetvi
            for (; item->next != NULL && strcmp(item->next->pair->key, key);
                    item = item->next)
                ;   // zamerne
            if (item->next != NULL) // odstraneni item->next
            {
                item->next = htab_item_free(item->next);
                (t->size)--;
                ret_val = true;
            }
        }
    }
    return ret_val;