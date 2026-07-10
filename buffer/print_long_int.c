#include "main.h"

int print_long_int(long n,
                   char buffer[],
                   int *buf_index)
{
    int count;

    count = 0;

    if (n < 0)
    {
        count += add_to_buffer('-', buffer, buf_index);
        n = -n;
    }

    if (n / 10)
        count += print_long_int(n / 10,
                                buffer,
                                buf_index);

    count += add_to_buffer((n % 10) + '0',
                           buffer,
                           buf_index);

    return (count);
}
