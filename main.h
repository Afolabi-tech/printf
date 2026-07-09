#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);
int print_char(char p_char);
int print_string(char *p_string);
int print_int(int n);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_base(unsigned int n, char *base);


#endif
