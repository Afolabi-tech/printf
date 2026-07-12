#include "main.h"

int print_reverse(char *s,
                  char buffer[],
                  int *buf_index)
{
    int i;
    int len;
    int count;

    count = 0;

    if (s == NULL)
        s = "(null)";

    len = str_len(s);

    for (i = len - 1; i >= 0; i--)
    {
        count += add_to_buffer(
            s[i],
            buffer,
            buf_index);
    }

    return (count);
}
