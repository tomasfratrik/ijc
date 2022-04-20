/*
 * wordcount.c
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

//if we choose low number, we dont waste memory but we reduce speed
//nowdays I think memmory isnt a big problem, and I think speed is more important 
//so around 15000 should be  (this really depents on how many unique keys we are going to store)

// from one source I found out that the prime number is the best to reduce collisions, so we choose 15013
//source: https://medium.com/swlh/why-should-the-length-of-your-hash-table-be-a-prime-number-760ec65a75d1
#define HASH_TABLE_SIZE 15013

#define AVG_LEN_MAX 0.75 //75%
//from this source, aroud 70% - 75% max occupation should be the best
//source: https://www.quora.com/How-is-the-size-of-a-hash-table-determined-How-should-optimization-be-done-for-it-to-be-fast

#define WORD_LEN_LIMIT 127



//first function to print pairs, which uses htab_for_each, secont function is in print_htab(htab_t *t), which is more complex
void printh(htab_pair_t* pair) {
  printf("%s\t%d\n", pair->key, pair->value);
}


int main(){
    htab_t *hash_table;
    hash_table = htab_init(HASH_TABLE_SIZE);
    if(hash_table == NULL)
        error_exit("Couldnt allocate new hash table!\n");

    char word[WORD_LEN_LIMIT];

    int word_len = 0;
    bool WarnUser =false; //flag
    htab_pair_t *pair;


    while((word_len = read_word(word,WORD_LEN_LIMIT,stdin)) != EOF){ 
        pair = htab_lookup_add(hash_table,word);
        pair->value++;
        double avg = (double)htab_size(hash_table) / htab_bucket_count(hash_table); //average occupation in bucket
        if(AVG_LEN_MAX < avg){
            htab_resize(hash_table,(htab_bucket_count(hash_table)*2)); 
        }
        if(word_len > WORD_LEN_LIMIT -1)
            WarnUser = true;
    }

    if(WarnUser == true){
        warning_msg("word exceeded lenght limit!\n");
        WarnUser = false;
    }

    // print_htab(hash_table);
    // htab_for_each(hash_table,printh);
    htab_free(hash_table);
}