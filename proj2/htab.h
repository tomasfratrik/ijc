/*
 * htab.h
 * Riešenie IJC=DU2, priklad b), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#ifndef __HTAB_H__
#define __HTAB_H__

#include <string.h>     
#include <stdbool.h>    

typedef struct htab {
    unsigned long int size;
    usingned long int arr_size;
    htab_item_t *arr_ptr[]
}htab_t;     

typedef struct htab_item{
    htab_item_t *next;
    htab_pair pair;

}htab_item_t;

// Typy:
typedef const char * htab_key_t;       
typedef int htab_value_t;               

// Dvojice dat v tabulce:
typedef struct htab_pair {
    htab_key_t    key;          
    htab_value_t  value;        
} htab_pair_t;             


size_t htab_hash_function(htab_key_t str);

// Funkce pro práci s tabulkou:
htab_t *htab_init(size_t n);                    // konstruktor tabulky
size_t htab_size(const htab_t * t);             // počet záznamů v tabulce
size_t htab_bucket_count(const htab_t * t);     // velikost pole
void htab_resize(htab_t *t, size_t newn);       // změna velikosti pole
                                                // (umožňuje rezervaci místa)
                                                
htab_pair_t * htab_find(htab_t * t, htab_key_t key);  // hledání
htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key);

bool htab_erase(htab_t * t, htab_key_t key);    // ruší zadaný záznam

// for_each: projde všechny záznamy a zavolá na ně funkci f
// Pozor: f nesmí měnit klíč .key ani přidávat/rušit položky
void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data));

void htab_clear(htab_t * t);    // ruší všechny záznamy
void htab_free(htab_t * t);     // destruktor tabulky

#endif // __HTAB_H__