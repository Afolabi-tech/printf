#include "main.h"

int print_char_n(char c,
                 int n,
                 char buffer[],
                 int *buf_index)
{
int count;

    count = 0;

    while (n > 0)
    {
        count += add_to_buffer(c,
                               buffer,
                               buf_index);
        n--;
    }

    return (count);
}
