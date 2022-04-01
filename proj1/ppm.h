/*
 * ppm.h
 * Riešenie IJC=DU1, priklad b), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */

#ifndef PPM_H
#define PPM_H



struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bajty, celkem 3*xsize*ysize
    };

struct ppm * ppm_read(const char * filename);
void ppm_free(struct ppm *p);

#endif