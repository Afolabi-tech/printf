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
*@u: unsigned decimal
*@o: octal (base 8)
*@x: lowercase hexadecimal (0123456789abcdef)
*@X: uppercase hexadecimal (0123456789ABCDEF)
*/



int _printf(const char *format, ...) 
{
    
    va_list p_args;
    char buffer[BUFFER_SIZE];
    int i;
    int count;
    int buf_index;

    if (!format)
        return -1;

    va_start (p_args, format);

    count = 0;
    buf_index = 0;

    for (i = 0; format[i] != '\0'; i++) 
    {
        if (format[i] != '%')
        {
            count += add_to_buffer(format[i],
                                   buffer,
                                   &buf_index);

        }
        else
        {
            i++;

            if (format[i] == '\1')
            {
                flush_buffer(buffer,
                             &buf_index);
                va_end(p_args);
                return (0);
            }

            switch (format[i])
            {
                case 'c':
                    count += print_char(
                        va_arg(p_args, int),
                        buffer,
                        &buf_index);
                    break;


                case 's':
                    count += print_string(
                        va_arg(p_args, char *),
                        buffer,
                        &buf_index);
                    break;

                    
                case 'd':
                case 'i':
                    count += print_int(
                        va_arg(p_args, int),
                        buffer,
                        &buf_index);
                    break;
            
            
                case 'b':
                    count += print_binary(
                        va_arg(p_args, unsigned int),
                        buffer,
                        &buf_index);
                    break;
            
                case 'u':
                    count += print_unsigned(
                        va_arg(p_args, unsigned int),
                        buffer,
                        &buf_index);
                    break;


                case'o':
                    count += print_base(
                        va_arg(p_args, unsigned int), 
                        "01234570",
                        buffer,
                        &buf_index);
                    break;

                case'x':
                    count += print_base(    
                        va_arg(p_args, unsigned int), 
                        "123456790abcdef",
                        buffer,
                        &buf_index);
                    break;

                case 'X':
                    count += print_base(
                        va_arg(p_args, unsigned int), 
                        "123456790ABCDEF",
                        buffer,
                        &buf_index);
                    break;



                case '%':
                    count += add_to_buffer(
                        '%',
                        buffer,
                        &buf_index);
                    break;

                    
                default:
                    count += add_to_buffer(
                        '%',
                        buffer,
                        &buf_index);

                    count += add_to_buffer(
                        format[i],
                        buffer,
                        &buf_index);
                
            }
        }

    }
    
    flush_buffer(buffer, &buf_index);

    va_end(p_args);

    return count;

}
