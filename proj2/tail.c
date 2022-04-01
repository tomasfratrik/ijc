/*
 * tail.c
 * Riešenie IJC=DU2, priklad a), 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 4095 // max num of chars in line

int convert_to_num(char *str){
    char *endptr;
    int num = strtoul(str, &endptr, 10);
    if (endptr[0] != '\0'){
        return -1;
    }
    return num;
}



int main(int argc, char *argv[]){

    int line_num = 10;
    FILE *fp = stdin;

    if(argc > 4){
        fprintf(stderr, "Too many arguments!\n");
        return 1;
    }


    if(argc >= 3){
        if (strcmp(argv[1],"-n")){
            fprintf(stderr, "Wrong parameter used!\n");
            return 1;
        }
        if((line_num = convert_to_num(argv[2])) == -1){
            fprintf(stderr, "Argument isnt a number!\n");
            return 1;
        }
        if(argc == 4){
            fp = fopen(argv[3],"r");
            if(fp == NULL){
                fprintf(stderr,"Could not open a file!\n");
                return 1;   
            }
        }

    }


    char buffer[line_num][MAX];
    char line[MAX];

    /* We parse line to char line
    and we shift whole  array of lines by 1
    and we place line to buffer[0] */
    while(fgets(line,MAX,fp)!= NULL){
        //shifting
        for(int i =line_num; i != 0; i-- ){
            strcpy(buffer[i],buffer[i-1]);
        }
            strcpy(buffer[0],line);
    }
    for(int i = line_num-1; i >= 0; i--){
        printf("%s",buffer[i]);
    }
} // main end
