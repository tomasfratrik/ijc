/*
 * io.c
 * Riešenie IJC=DU2, priklad a), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */
#include<stdio.h>
#include "htab.h"
#include "io.h"
#include <ctype.h>
#include <stdbool.h>

 int read_word(char *s, int max, FILE *f){


     int i = 0;
     int c;


    bool behindWord = true;
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

         if(i == max-1)
            break;
         i++;
         *s++ = c;
     }

     if(i == 0) // found EOF
        return EOF;
    // s++;
    *s = '\0';
    return i;
    // for(int i = 0;(c= fgetc(f)) != EOF ;i++){
    //     if(c == " ")
    //         break;
    //     if(i == max-1)
    //         break;
    //     

    //     *s++ = c;
    // }
 }