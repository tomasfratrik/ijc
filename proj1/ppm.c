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


    FILE *fp = fopen(filename, "rb");
    if(fp == NULL){
        warning_msg("Nepodarilo sa otvorit subor!\n");
        return NULL;
    }

    char format[3]; //sem vlozim z hlavicky typ formatu, napr: P6
    unsigned long xsize;
    unsigned long ysize;
    char rgb_depth[4];
    
    int num_of_params = fscanf(fp,"%s %ld %ld %s\n",format,&xsize,&ysize,rgb_depth); //nacitam hlavicku
    unsigned long size = xsize*ysize*3;

    /* Kontrolujeme nacitanu hlavicku */

    if((strcmp(format,"P6") || (RGB_DEPTH_CONST < atoi(rgb_depth))) || num_of_params != 4 ){
        warning_msg("Zly format vstupu!\n");
        fclose(fp);
        return NULL;
    }

    if((xsize*ysize*3) > DATA_LIMIT){
        warning_msg("Bol prekroceny limit dat!\n");
        fclose(fp);
        return NULL;
    }

    struct ppm *p = malloc(sizeof(struct ppm)+size);
    if(p == NULL){
        warning_msg("Nepodarilo sa alokovat pamet!\n");
        fclose(fp);
        return NULL;
    }

    p->xsize = xsize;
    p->ysize = ysize;
    //nacitam data
    unsigned long data = fread(p->data, sizeof(char), size, fp);
    if (data != size) {
        warning_msg("Nepodarilo sa precitat subor!\n");
        fclose(fp);
        free(p);
		return NULL;
    }
    //kontrola EOF
    if(fgetc(fp) != EOF){
        warning_msg("Nenaslo sa zakoncenie suboru (EOF)\n");
        fclose(fp);
        free(p);
		return NULL;
    }
    fclose(fp);
    return p;
}
