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

int print_special_string(char *str,
                         char buffer[],
                         int *buf_index);

int print_pointer(void *ptr,
                  char buffer[],
                  int *buf_index);

int print_ulong_base(unsigned long n,
                    char *base,
                    char buffer[],
                    int *buf_index);

int print_long_int(long n,
                   char buffer[],
                   int *buf_index);

int print_padding(int width,
                  int len,
                  char buffer[],
                  int *buf_index);

int str_len(char *s);

int int_len(long n);

int base_len(unsigned long n, int base);

int print_zeros(int zeros,
                char buffer[],
                int *buf_index);

int str_n_len(char *s, int precision);

int print_char_n(char c,
                 int n,
                 char buffer[],
                 int *buf_index);

int print_reverse(char *s,
                  char buffer[],
                  int *buf_index);

int print_rot13(char*s,
                char buffer[],
                int *buf_index);

#endif
