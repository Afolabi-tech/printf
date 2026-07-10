#include "main.h"

int is_printable(char c)
{
    return (c >= 32 && c < 127);

}

int print_special_string(char *str,
                         char buffer[],
                         int *buf_index)

{
    int count;
    int i;
    unsigned char c;
    char *hex;

    count = 0;
    i = 0;
    hex = "0123456789ABCDEF";

    if (str == NULL)
        str = "(null)";

    while (str[i] != '\0')
    {

        c = str[i];

        if (c >= 32 && c < 127)
        {
            count += add_to_buffer(c,
                                   buffer,
                                   buf_index);

        }

        else
        {
            count += add_to_buffer('\\',
                                    buffer,
                                    buf_index);

            count += add_to_buffer('x', 
                                    buffer,
                                    buf_index);

            count += add_to_buffer(
                                hex[c / 16],
                                buffer,
                                buf_index);

            count += add_to_buffer(
                                hex[c % 16],
                                buffer,
                                buf_index);

         } 

         i++;

    }

    return (count);
}
