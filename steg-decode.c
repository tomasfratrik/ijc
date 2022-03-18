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
#include "eratosthenes.h"

int main(int argc,char *argv[]) {

    if(argc != 2){
        error_exit("Nespravny pocet argumentov!\n");
        return 1;
    }
    struct ppm * ppm_p = ppm_read(argv[1]);
    if(ppm_p == NULL){
        error_exit("Nepodarilo sa precitat ppm format!\n");
        return 1;
    }

    unsigned long size = ppm_p->xsize*ppm_p->ysize*3;
    bitset_alloc(msgArray, size);
	Eratosthenes(msgArray);

	bitset_create(single_char, CHAR_BIT); // Mame tu ze vytvarame 8 bitov, ale aj tak sa vytvori unsigned long * 8 , je to len pre pochopenie
    int counter = 0;

    for (unsigned long i = 29;i < size ;i++) {
        if (bitset_getbit(msgArray,i) == 0) {
            int bit = ppm_p->data[i] & 1; // pomocou masky AND -> zistime LSB
            bitset_setbit(single_char, counter, bit);
            counter++;
            if(counter == 8) { //Ak uz mame potrebny pocet bitov na vytvorenie bajtu
				if(single_char[1] == '\0') {
					printf("\n");
					ppm_free(ppm_p);
					bitset_free(msgArray);
					return 0;
				}
                putchar(single_char[1]);
				counter = 0;
                //vynulujem naspet bity
                for(int j = 0; j< CHAR_BIT;j++){
                    bitset_setbit(single_char,j,0);
                }
            }
        }
    }


    bitset_free(msgArray);
    ppm_free(ppm_p);
    
    return 0;
}
