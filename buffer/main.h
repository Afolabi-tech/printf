#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdarg.h>
#include <unistd.h>


int _printf(const char *format, ...);


int print_char(char p_char, 
               char buffer[],
               int *buf_index);
int print_string(char *p_string, 
                 char buffer[], 
                 int *buf_index);
int print_int(int n, 
              char buffer[], 
              int *buf_index);

int print_binary(unsigned int n, 
                 char buffer[], 
                 int *buf_index);

int print_unsigned(unsigned int n, 
                   char buffer[], 
                   int *buf_index);

int print_base(unsigned int n, 
               char *base,
               char buffer[], 
               int *buf_index);

void flush_buffer(char buffer[], 
                  int *buf_index);

int add_to_buffer(char p_char, 
                  char buffer[], 
                  int *buf_index);

#endif
