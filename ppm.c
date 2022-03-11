/*
 * ppm.c
 * Riešenie IJC=DU1, priklad b), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ppm.h"
#include"error.h"

#define RGB_DEPTH_CONST 255
#define DATA_LIMIT 8000*8000*3


void ppm_free(struct ppm *p){
    free(p);
}

struct ppm * ppm_read(const char * filename){


    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        warning_msg("Nepodarilo sa otvorit subor!");
        return NULL;
    }
    char format[3];
    unsigned long xsize;
    unsigned long ysize;
    char rgb_depth[4];

    int num_of_params = fscanf(fp,"%s %ld %ld %s\n",format,&xsize,&ysize,rgb_depth);
    unsigned long size = xsize*ysize*3;


    if((strcmp(format,"P6") || (RGB_DEPTH_CONST < atoi(rgb_depth))) || num_of_params != 4 ){
        warning_msg("Zly format vstupu!");
        fclose(fp);
        return NULL;
    }

    if((xsize*ysize*3) > DATA_LIMIT){
        warning_msg("Bol prekroceny limit dat!");
        fclose(fp);
        return NULL;
    }

    struct ppm *p = malloc(sizeof(struct ppm)+size);
    if(p == NULL){
        warning_msg("Nepodarilo sa alokovat pamet!");
        fclose(fp);
        return NULL;
    }

    p->xsize = xsize;
    p->ysize = ysize;
    if (fread(p->data, sizeof(char), size, fp) != size) {
        warning_msg("Nepodarilo sa precitat subor!");
        fclose(fp);
        free(p);
		return NULL;
    }

    fclose(fp);
    return p;
}
