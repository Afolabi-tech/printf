#include "main.h"

int print_padding(int width,
                  int len,
                  char buffer[],
                  int *buf_index)
{
    int count;
    int spaces;

    count = 0;
    spaces = width - len;

    while (spaces > 0)
    {
        count += add_to_buffer(' ',
                               buffer,
                               buf_index);
        spaces--;
    }

    return (count);
}
