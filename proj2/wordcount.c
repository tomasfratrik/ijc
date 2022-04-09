/*
 * wordcount.c
 * Riešenie IJC=DU2, priklad a), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */
#include<stdio.h>
#include "htab.h"

void print_elems(htab_t *table){
    printf("\n");
        printf("size-> %ld\n",table->size);
        printf("arr_size-> %ld\n",table->arr_size);
        printf("\n");
    printf("/************ HASH TABLE ************/\n");
    for(int i = 0; i < table->arr_size;i++){
        if(table->arr_ptr[i] == NULL){
            printf("%d \t ---\n",i);
        }
        else{
            htab_item_t *curr = table->arr_ptr[i];
            printf("%d \t ",i);
            while(curr != NULL){
                printf("[%s,%d]",curr->pair->key, curr->pair->value);
                if(curr->next != NULL) printf("->");
                // else printf("-|");
                curr = curr->next;
            }
            printf("\n");
            // printf("%d \t %s[%d]\n",i,table->arr_ptr[i]->pair->key,table->arr_ptr[i]->pair->value);

        }
    }
    printf("/************************************/\n");
    printf("\n");
}

void print_pair(htab_pair_t *pair){
    printf("\n");
    printf("Key -> %s\n",pair->key);
    printf("Value -> %d\n",pair->value);
    printf("\n");
}
int main(){
    htab_t *hash_table;
    hash_table = htab_init(5);

    htab_lookup_add(hash_table,"test");
    htab_lookup_add(hash_table,"test");
    htab_lookup_add(hash_table,"nehehe");
    htab_lookup_add(hash_table,"auto");
    htab_lookup_add(hash_table,"cesko");
    htab_lookup_add(hash_table,"lmao");
    htab_lookup_add(hash_table,"divocak");
    htab_add(hash_table, "test");
    htab_add(hash_table, "divocak");

    // htab_erase(hash_table,"cesko");
    // htab_erase(hash_table,"nehehe");
    htab_clear(hash_table);
    print_elems(hash_table);


    // htab_pair_t *item = htab_find(hash_table,"divocak");
    // if(item == NULL){

    // printf("NULL\n");
    // return 1;
    // }

    // print_pair(item);

}