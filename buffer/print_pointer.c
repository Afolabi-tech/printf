#include "main.h"

int print_pointer(void *ptr,
                  char buffer[],
                  int *buf_index)
{
    int count;

    count = 0;

    if (ptr == NULL)
        return (print_string("(nil)",
                             buffer,
                             buf_index));

    count += add_to_buffer('0',
                           buffer,
                           buf_index);

    count += add_to_buffer('x',
                           buffer,
                           buf_index);

    count += print_ulong_base(
                 (unsigned long)ptr,
                 "0123456789abcdef",
                 buffer,
                 buf_index);

    return (count);
}
