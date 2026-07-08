#include "main.h"

/**
*printf - function that produces output according  to a format
*
*@c: count characters
*@s: count strings
*@%: count percentage
*@d: decimal numbers
*@i: integer
*@b: binary
*/



int _printf(const char *format, ...) {
    va_list p_args;
    int index = 0;
    int count = 0;

    if (!format)
        return -1;

    va_start (p_args, format);

    while (format[index]) {
        if (format [index] == '%' && format[index + 1] != '\0') {
            index++;

            if (format[index] == 'c')
                count += print_char(va_arg(p_args, int));

            else if (format[index] == 's')
                count += print_string(va_arg(p_args, char *));


            else if (format[index] == 'd' || format[index] == 'i')
            {
                count += print_int(va_arg(p_args, int)); 
            }
            
            else if (format[index] == 'b')
                count += print_binary(va_arg(p_args, unsigned int));

            else if (format[index] == '%')
                count += write(1, "%", 1);

            else 
            {
                count += write(1, "%", 1);
                count += write (1, &format[index], 1);
            }

        }
        
        else
        {
            count += write(1, &format[index], 1);
        }

        index++;
    }

    va_end(p_args);

    return count;

}
