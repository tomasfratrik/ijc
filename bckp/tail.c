/*
 * tail.c
 * Riešenie IJC=DU2, priklad a), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdarg.h>
#include "error.h"
#define MAX 4095// max num of chars in a line



int convert_to_num(char *str){
    char *endptr;
    int num = strtoul(str, &endptr, 10);
    if (endptr[0] != '\0'){
        return -1;
    }
    if(num < 0) 
        error_exit("Argument cislo je mensie ako 0\n");
    return num;
}



int main(int argc, char *argv[]){
    int line_num = 10;
    FILE *fp = stdin;

    if(argc > 4){
        error_exit("Too many arguments!\n");
    }
    if(argc == 2){
        fp = fopen(argv[1],"r");
        if(fp == NULL){
            error_exit("Could not open a file!\n"); 
        }
    }

    if(argc >= 3){
        if (strcmp(argv[1],"-n")){
            error_exit("Wrong parameter used!\n");
        }
        if((line_num = convert_to_num(argv[2])) == -1){
            error_exit("Argument isnt a number!\n");
        }
        if(argc == 4){
            fp = fopen(argv[3],"r");
            if(fp == NULL){
                error_exit("Could not open a file!\n");
                 
            }
        }

    }

    // void *buff   
    // char buffer[line_num][MAX];
    char line[MAX+2];

    char *buffer[line_num];

    
    for(int i = 0; i < line_num; i++){
        buffer[i] = calloc(MAX,sizeof(char));   
    }
    


    int c;
    int i = 0;
    int ignoreChars = 0;

    while((c = fgetc(fp)) != EOF){
        int newLineFlag = 0;

        line[i] = c;
        if(i+1 == MAX && c != '\n'){
            c = '\n';
            line[i+1] = '\n';
            ignoreChars = 1;
        }
        i++;


        
        if(c == '\n'){
            newLineFlag = 1;
            if(ignoreChars)
                line[i+1] = '\0';
            else
                line[i] = '\0';
            i = 0;
        }
        
        if(ignoreChars){
            while((c = fgetc(fp)) != '\n'); 
            ignoreChars = 0;
        }
        if(newLineFlag){
            for(int i =line_num; i != 0; i-- ){
                memcpy(buffer[i-1],buffer[i-2],MAX+2);
            }
                memcpy(buffer[0],line,MAX+2);
                newLineFlag = 0;
        }
    }

    for(int i = line_num-1; i >= 0; i--){
        printf("%s",buffer[i]);
    }

    for(int i = 0; i <line_num;i++){
        free(buffer[i]);
    }


} 


    // while(fgets(line,MAX,fp)!= NULL){

    //     if(line == NULL)printf("found");
    //     for(int i =line_num; i != 0; i-- ){
    //         memcpy(buffer[i-1],buffer[i-2],MAX);
    //     }
    //         memcpy(buffer[0],line,MAX);
    // }
    // for(int i = line_num-1; i >= 0; i--){
    //     printf("%s",buffer[i]);
    // }

    // for(int i = 0; i <line_num;i++){
    //     free(buffer[i]);
    // }

