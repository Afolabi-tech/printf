#include "main.h"

/**
*print_binary- custom specifier that convert an unsigned int to binary
*
*@b: return binary
*/

int print_binary(unsigned int n,
                 char buffer[],
                 int *buf_index)

{
    int count;


    count = 0;

    if (n >= 2)
        count += print_binary(n / 2,
                              buffer,
                              buf_index);

    count += add_to_buffer((n % 2) + '0',
                           buffer,
                           buf_index);
   

    return (count);
}
