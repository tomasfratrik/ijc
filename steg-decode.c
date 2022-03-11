/*
 * steg-decode.c
 * Riešenie IJC=DU1, priklad b), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include "ppm.h"
#include "bitset.h"
#include"eratosthenes.h"

int main() {

    struct ppm * ppm_p = ppm_read("du1-obrazek.ppm");
    if(ppm_p == NULL){
        error_exit("Nepodarilo sa precitat ppm format!");
    }

    unsigned long size = ppm_p->xsize*ppm_p->ysize*3;
    bitset_alloc(msgArray, size);
	Eratosthenes(msgArray);

	bitset_create(single_char, 8); 
    int counter = 0;

    for (unsigned long i = 29;i < size ;i++) {
        if (bitset_getbit(msgArray,i) == 0) {
            int bit = ppm_p->data[i] & 1;
            bitset_setbit(single_char, counter, bit);
            counter++;
            if(counter == 8) {
				if(single_char[1] == '\0') {
					printf("\n");
					ppm_free(ppm_p);
					bitset_free(msgArray);
					return 0;
				}
                putchar((char) single_char[1]);
				counter = 0;
            }
        }
    }


    bitset_free(msgArray);
    ppm_free(ppm_p);
    
    return 0;
}
