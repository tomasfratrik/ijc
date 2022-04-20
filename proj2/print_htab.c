/*
 * print_htab.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include<stdlib.h>
#include "htab.h"
#include "htab_private.h"
#include "error.h"
#include "io.h"

//own function to print hash table
void print_htab(htab_t *table){
    printf("\n");
        printf("size-> %ld\n",table->size);
        printf("arr_size-> %ld\n",table->arr_size);
        printf("\n");
    printf("/************ HASH TABLE ************/\n");
    for(size_t i = 0; i < table->arr_size;i++){
        if(table->arr_ptr[i] == NULL){
            printf("%ld \t ---\n",i);
        }
        else{
            htab_item_t *curr = table->arr_ptr[i];
            printf("%ld \t ",i);
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