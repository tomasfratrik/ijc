/*
 * error.c
 * Riešenie IJC=DU2, 19.4.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.4.0
 */

#include "error.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


void warning_msg(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void error_exit(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    fprintf(stderr,"CHYBA: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
    exit(1);
}