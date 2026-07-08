#include "main.h"

/**
*print_binary- custom specifier that convert an unsigned int to binary
*
*@b: return binary
*/

int print_binary(unsigned int n)
{
    int count;
    char digit;

    count = 0;

    if (n / 2)
        count += print_binary(n / 2);

    digit = (n % 2) + '0';
    count += write(1, &digit, 1);

    return (count);
}
