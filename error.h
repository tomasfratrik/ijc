/*
 * error.h
 * Riešenie IJC=DU1, priklad a), 20.3.2022
 * Autor: Tomáš Frátrik (xfratr01), FIT
 * Preložene: gcc 9.3.0
 */


#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif