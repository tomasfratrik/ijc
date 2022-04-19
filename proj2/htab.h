/*
 * htab.h
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>     
#include <stdbool.h>   



struct htab;    // neúplná deklarace struktury - uživatel nevidí obsah
typedef struct htab htab_t;     // typedef podle zadání

struct htab_item;
typedef struct htab_item htab_item_t;


typedef const char * htab_key_t;       
typedef int htab_value_t;       

typedef struct htab_pair {
    htab_key_t    key;          
    htab_value_t  value;        
} htab_pair_t;             


size_t htab_hash_function(htab_key_t str);

// Funkce pro práci s tabulkou:
htab_t *htab_init(size_t n);                    // initialize hash table
size_t htab_size(const htab_t * t);             // počet záznamů v tabulce
size_t htab_bucket_count(const htab_t * t);     // velikost pole
void htab_resize(htab_t *t, size_t newn);       // změna velikosti pole
                                                // (umožňuje rezervaci místa)
htab_pair_t * htab_add(htab_t *t,htab_key_t key);                                                

htab_pair_t * htab_find(htab_t * t, htab_key_t key);  // hledání
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

bool htab_erase(htab_t * t, htab_key_t key);    // ruší zadaný záznam

// for_each: projde všechny záznamy a zavolá na ně funkci f
// Pozor: f nesmí měnit klíč .key ani přidávat/rušit položky
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

void htab_clear(htab_t * t);    // ruší všechny záznamy
void htab_free(htab_t * t);     // destruktor tabulky

#endif // __HTAB_H__