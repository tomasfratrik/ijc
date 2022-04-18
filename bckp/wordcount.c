/*
 * wordcount.c
 * Riešenie IJC=DU2, priklad a), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */
#include<stdio.h>
#include "htab.h"
#include "io.h"
#include<stdlib.h>



#define HASH_TABLE_SIZE 10
#define WORD_LEN_LIMIT 127


//function to print htab
void print_htab(htab_t *table){
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
                curr = curr->next;
            }
            printf("\n");

        }
    }
    printf("/************************************/\n");
    printf("\n");
}

void print_word(htab_pair_t *data)
{
    printf("[%s, %d]\n", data->key,data->value);
}

int main(){
    htab_t *hash_table;
    hash_table = htab_init(HASH_TABLE_SIZE);

    char word[WORD_LEN_LIMIT];

    int word_len = 0;

    while((word_len = read_word(word,WORD_LEN_LIMIT,stdin)) != EOF){
        htab_lookup_add(hash_table,word);
    }


    // char *buffer = malloc(WORD_LEN_LIMIT);
    // htab_item_t * item;
    // int test = 0;
    // while (read_word(buffer, WORD_LEN_LIMIT, stdin) != EOF)
    // {
    //     htab_lookup_add(hash_table, buffer);
    // }

    // print_htab(hash_table);
    // htab_lookup_add(hash_table,"test");
    // htab_lookup_add(hash_table,"test");
    // htab_lookup_add(hash_table,"nehehe");
    // htab_lookup_add(hash_table,"auto");
    // htab_lookup_add(hash_table,"cesko");
    // htab_lookup_add(hash_table,"lmao");
    // htab_lookup_add(hash_table,"divocak");
    // htab_add(hash_table, "test");
    // htab_add(hash_table, "divocak");
    
    // htab_clear(hash_table);
    // htab_free(hash_table);
    // print_elems(hash_table);

    print_htab(hash_table);
    // htab_erase(hash_table,"lmao");
    // htab_erase(hash_table,"divocak");
    // htab_erase(hash_table,"lmao");
    // htab_erase(hash_table,"test");
    // htab_erase(hash_table,"nehehe");
    // htab_erase(hash_table,"auto");
    // htab_erase(hash_table,"cesko");
    htab_resize(hash_table,20);
    // htab_erase(hash_table,"test");
    // htab_erase(hash_table,"test");
    // htab_erase(hash_table,"lmao");
    // htab_clear(hash_table);
    print_htab(hash_table);
    // free(hash_table->arr_ptr);
    // free(hash_table);
    // htab_free(hash_table);

    // int read_word(char *s, int max, FILE *f)
    // int max = 5;
    // char str[5];
    // int test = read_word(str,5,stdin);
    // printf("len -> %d\n",test);

    htab_free(hash_table);
}