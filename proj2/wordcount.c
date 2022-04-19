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
#define HASH_TABLE_SIZE 10000
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
    // htab_erase(hash_table,"riadok");
    // htab_erase(hash_table,"text");
    // htab_erase(hash_table,"siedmi");
    // htab_erase(hash_table,"desiaty");
    // htab_erase(hash_table,"treti");
    // htab_erase(hash_table,"5");
    // htab_erase(hash_table,"4");
    // htab_erase(hash_table,"osmi");
    // htab_erase(hash_table,"je");
    // htab_erase(hash_table,"siesty");


    htab_lookup_add(hash_table,"test");
    htab_lookup_add(hash_table,"test");
    htab_lookup_add(hash_table,"xdd");
    htab_lookup_add(hash_table,"lmaooo");
    htab_lookup_add(hash_table,"neheh");
    // htab_erase(hash_table,"test");
    // htab_erase(hash_table,"lmaooo");
    // htab_lookup_add(hash_table,"divocak");
    // print_htab(hash_table);
    // htab_resize(hash_table,4);
    print_htab(hash_table);

    htab_free(hash_table);
}