 /*
 * htab_private.h
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */


#ifndef __HTAB_PRIVATE_H__
#define __HTAB_PRIVATE_H__



void print_htab(htab_t *table);
htab_item_t *htab_item_ctor(htab_key_t key);

#endif // __HTAB_PRIVATE_H__