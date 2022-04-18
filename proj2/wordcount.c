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
//

//I tested few full A4 documents, average unique words were 260,
//but then we would need to realloc a lot
//let say we have 10*a4 papers, than that is 2600
//for division we use closes prime number so 2609
#define HASH_TABLE_SIZE 10
#define WORD_LEN_LIMIT 127


int main(){
    htab_t *hash_table;
    hash_table = htab_init(HASH_TABLE_SIZE);

    char word[WORD_LEN_LIMIT];

    int word_len = 0;
    bool WarnUser =false;

    while((word_len = read_word(word,WORD_LEN_LIMIT,stdin)) != EOF){
        htab_lookup_add(hash_table,word);
        if(word_len > WORD_LEN_LIMIT -1)
            WarnUser = true;
    }

    if(WarnUser == true){
        warning_msg("word exceeded lenght limit!\n");
        WarnUser = false;
    }

    print_htab(hash_table);
    htab_resize(hash_table,20);
    print_htab(hash_table);

    htab_free(hash_table);
}