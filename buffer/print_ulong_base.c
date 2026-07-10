#include "main.h"

int print_ulong_base(unsigned long n,
                     char *base,
                     char buffer[],
                     int *buf_index)
{
    int count;
    int base_len;

    count = 0;
    base_len = 0;

    while (base[base_len])
        base_len++;

    if (n >= (unsigned long)base_len)
        count += print_ulong_base(
                     n / base_len,
                     base,
                     buffer,
                     buf_index);

    count += add_to_buffer(
                 base[n % base_len],
                 buffer,
                 buf_index);

    return (count);
}
