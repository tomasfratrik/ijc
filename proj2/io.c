/*
 * io.c
 * Solution to IJC=DU2,  b), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#include<stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "htab.h"
#include "io.h"
#include "error.h"
#define WORD_LEN_LIMIT 4

//function reads word from *f, and returns its lenght
int read_word(char *s, int max, FILE *f){

    if(f == NULL){
        warning_msg("Couldnt open a file!\n");
        return EOF;
    }


    int counter = 0;
    int c;

    bool behindWord = true; //bool to skip spaces behind word
    while((c = fgetc(f) )!= EOF){
        if(isspace(c)){
        if(behindWord)
            continue;
        else{
            break;
        }
        }
        else
        behindWord = false;

        if(counter < max-1){
        *s++ = c; //add to *s then increment pointer
        }
        counter++;

    }

    if(counter == 0) // found EOF
    return EOF;
    
*s = '\0'; // at the end
return counter; // return lenght
}