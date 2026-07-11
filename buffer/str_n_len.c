#include "main.h"

int str_n_len(char *s, int precision)
{
    int len;

    len = 0;

    if (s == NULL)
        s = "(null)";

    while (s[len] &&
           (precision < 0 || len < precision))
        len++;

    return (len);
}
