/*
 * error.h
 * Solution to IJC=DU2,  from DU1, 19.4.2022
 * Author: Tomáš Frátrik (xfratr01), FIT
 * Compiled: gcc 9.4.0
 */

#ifndef ERROR_H
#define ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif