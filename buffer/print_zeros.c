#include "main.h"

int print_zeros(int zeros,
                char buffer[],
                int *buf_index)
{
    int count;

    count = 0;

    while (zeros > 0)
    {
        count += add_to_buffer('0',
                               buffer,
                               buf_index);
        zeros--;
    }

    return (count);
}
