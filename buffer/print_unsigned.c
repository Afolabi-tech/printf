#include "main.h"

int print_unsigned(unsigned int n,
                   char buffer[],
                   int *buf_index)
{
    return (print_base(n, 
                       "0123456789",
                       buffer,
                       buf_index));
}
