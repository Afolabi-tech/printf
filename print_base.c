#include "main.h"

int print_base(unsigned int n, char *base)
{
    int count;
    int base_len;
    char c;

    count = 0;
    base_len = 0;

    while (base[base_len] != '\0')
        base_len++;

    if (n >= (unsigned int)base_len)
        count += print_base(n / base_len, base);

    c = base[n % base_len];
    count += write(1, &c, 1);

    return (count);
}
