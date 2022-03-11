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
// #define IMG_SIZE_LIMIT 8000*8000*3


void ppm_free(struct ppm *p){
    free(p);
}

// struct ppm *ppm_read(const char *filename) {

//     FILE *file = fopen(filename, "r");
//     if (file == NULL) {
//         warning_msg("%s : Subor sa nepodarilo otvorit\n", filename);
//         fclose(file);
// 		return NULL;
//     }

//     char imgformat[3];
//     unsigned int imgxsize,imgysize;
//     int tmp;

//     if ((fscanf(file, "%s %u %u %d\n", imgformat, &imgxsize, &imgysize, &tmp)) != 4) {
//         warning_msg("%s : Hlavicka suboru sa nepodarila nacitat\n", filename);
//         fclose(file);
// 		return NULL;
//     }

//     unsigned long imgsize = imgxsize*imgysize*3;

// 	if (imgsize > IMG_SIZE_LIMIT) {
// 		warning_msg("%s : Velkost obrazku je vacsia ako limit (%d)\n", filename, IMG_SIZE_LIMIT);
// 		fclose(file);
// 		return NULL;
// 	}

//     if (strcmp(imgformat,"P6") != 0) {
//         warning_msg("%s : Subor ma nespravny format\n", filename);
//         fclose(file);
// 		return NULL;
//     }

//     struct ppm *img = malloc(sizeof(struct ppm)+imgsize);

//     if (img == NULL) {
//         warning_msg("%s : Alokacia pamate sa nepodarila\n", filename);
//         fclose(file);
// 		return NULL;
//     }

//     img->xsize=imgxsize;
//     img->ysize=imgysize;
    
//     if (fread(img->data, sizeof(char), imgsize, file) != imgsize) {
//         warning_msg("%s : Velkost obrazku v hlavicke suboru sa nazhoduje s velkostou obrazku v datach\n", filename);
//         fclose(file);
//         free(img);
// 		return NULL;
//     }

// 	if (fgetc(file) != EOF) {
// 		warning_msg("%s : Subor nie je ukonceny alebo sa nenacitali vsetky znaky\n", filename);
// 		fclose(file);
// 		free(img);
// 		return NULL;
// 	}

//     fclose(file);
//     return img;
// }

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

//     if (fgetc(fp) != EOF) {
//         warning_msg("%s : Subor nie je ukonceny alebo sa nenacitali vsetky znaky\n", filename);
//         fclose(fp);
//         free(p);
//         return NULL;
// }
    fclose(fp);
    return p;
}
