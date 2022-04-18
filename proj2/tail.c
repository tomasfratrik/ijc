/*
 * tail.c
 * Solution to IJC=DU2,  a), 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include <stdarg.h>
#include "error.h"
#define MAX 4095// max num of chars in a line


//function that converts given char *string to int, and returns it
int convert_to_num(char *str){
    char *endptr;
    int num = strtoul(str, &endptr, 10);
    if (endptr[0] != '\0'){
        return -1;
    }
    if(num < 0) 
        error_exit("Number argument cannot be lesser than 0!\n");
    return num;
}



int main(int argc, char *argv[]){
    int line_num = 10;
    FILE *fp = stdin;


    //parsing arguments
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


    char line[MAX+2]; //parsing line 

    char *buffer[line_num]; // creating cycle buffer of pointers to lines

    
    for(int i = 0; i < line_num; i++){
        buffer[i] = calloc(MAX,sizeof(char));
    }
    


    int c;
    int i = 0;
    bool ignoreChars = false;
    bool show_warning = false;

    while((c = fgetc(fp)) != EOF){
        int newLineFlag = 0;

        line[i] = c;
        if(i+1 == MAX && c != '\n'){ //if maximum is reached
            c = '\n';
            line[i+1] = '\n';
            ignoreChars = true; //we will ignore other chars
            show_warning = true;
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
            while((c = fgetc(fp)) != '\n'); //skip chars till \n occurs
            ignoreChars = false;
        }
        if(newLineFlag){
            for(int i =line_num; i != 0; i-- ){
                memcpy(buffer[i-1],buffer[i-2],MAX+2); //cycle
            }
                memcpy(buffer[0],line,MAX+2); //set new line to buffer[0]
                newLineFlag = 0;
        }
    }

    if(show_warning == true)
        warning_msg("More chars than MAX were used in a line!");

    //printing buffer to stdout
    for(int i = line_num-1; i >= 0; i--){
        printf("%s",buffer[i]);
    }


    //freeing allocated memmory
    for(int i = 0; i <line_num;i++){
        free(buffer[i]);
    }
} 