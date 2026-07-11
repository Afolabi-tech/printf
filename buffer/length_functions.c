#include "main.h"

int str_len(char *s)
{
    int len;

    len = 0;

    if (s == NULL)
        s = "(null)";

    while (s[len] != '\0')
        len++;

    return (len);
}

int int_len(long n)
{
    int len;

    len = 0;

    if (n <= 0)
    {
        len++;
        n = -n;
    }

    while (n)
    {
        len++;
        n /= 10;
    }

    return (len);
}

int base_len(unsigned long n, int base)
{
    int len;

    len = 1;

    while (n >= (unsigned long)base)
    {
        len++;
        n /= base;
    }

    return (len);
}
