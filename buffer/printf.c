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
    int plus_flag;
    int space_flag;
    int hash_flag;
    int long_flag;
    int short_flag;
    int width;

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
            continue;
        }


        else
        {
            i++;

            plus_flag = 0;
            space_flag = 0;
            hash_flag = 0;
            long_flag = 0;
            short_flag = 0;
            width = 0;

            /* Parse Flag character +, space and # */
            while (format[i] == '+' ||
                   format[i] == ' ' ||
                   format[i] == '#')
            {
                if (format[i] == '+')
                    plus_flag = 1;
                else if (format[i] == ' ')
                    space_flag = 1;
                else 
                    hash_flag = 1;

                i++;
            }
    
            /*Parse Length modifier l-long_flag and h-short_flag */
            while (format[i] == 'l' ||
                   format[i] == 'h')
            {
                if (format[i] == 'l')
                    long_flag = 1;
                else
                    short_flag = 1;

                i++;
            }

            /*Parse Field Width */
            while (format[i] >= '0' && 
                    format[i] <= '9')
            {
                width = width * 10 + 
                        (format[i] - '0');
                i++;
            }


            if (format[i] == '\0')
            {
                flush_buffer(buffer,
                             &buf_index);
                va_end(p_args);
                return (0);
            }

            switch (format[i])
            {
                case 'c':

                    count += print_padding(width,
                                           1,
                                           buffer,
                                           &buf_index);

                    count += print_char(
                        va_arg(p_args, int),
                        buffer,
                        &buf_index);
                    break;


                case 's':
                {
                    char *s;
                    int len;

                    s = va_arg(p_args, char *);
                    len = str_len(s);

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);

                    count += print_string(
                                           s,
                                           buffer,
                                           &buf_index);
                    break;
                }

                    
                case 'd':
                case 'i':
                {
                    long n;
                    int len;

                    if (long_flag)
                        n = va_arg(p_args, long);
                    else if (short_flag)
                        n = (short)va_arg(p_args, int);
                    else
                        n = va_arg(p_args, int);

                    if (n >= 0)
                    {
                        
                        if (plus_flag)
                            count += add_to_buffer('+',
                                                   buffer,
                                                   &buf_index);

                        else if (space_flag)
                            count += add_to_buffer(' ',
                                                   buffer,
                                                   &buf_index);
                    }
                
                    len = int_len(n);

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);

                    count += print_long_int(n,
                                       buffer,
                                       &buf_index);
                    break;
                }

            
                case 'b':
                    count += print_binary(
                        va_arg(p_args, unsigned int),
                        buffer,
                        &buf_index);
                    break;
            
                case 'u':
                {
                    unsigned long n;
                    int len;
                    

                    if (long_flag)
                        n = va_arg(p_args, unsigned long);
                    else if (short_flag)
                        n = (unsigned short)
                            va_arg(p_args, unsigned int);
                    else
                        n = va_arg(p_args, unsigned int);

                    len = base_len(n, 10);

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);


                    count += print_ulong_base(
                        n,
                        "0123456789",
                        buffer,
                        &buf_index);
                    break;
                }


                case'o':
                {
                    unsigned long n;
                    int len;

                    if (long_flag)
                        n = va_arg(p_args, unsigned long);
                    else if (short_flag)
                        n = (unsigned short)
                            va_arg(p_args, unsigned int);
                    else 
                        n = va_arg(p_args, unsigned int);

                    len = base_len(n, 8);

                    if (hash_flag && n != 0)
                        len++;

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);
                  

                    if (hash_flag && n != 0)
                        count += add_to_buffer('0',
                                               buffer,
                                               &buf_index);

                    count += print_ulong_base(n, 
                                        "01234567",
                                        buffer,
                                        &buf_index);
                    break;
                }


                case'x':
                {
                    unsigned long n;
                    int len;

                    if (long_flag)
                        n = va_arg(p_args, unsigned long);
                    else if (short_flag)
                        n = (unsigned short)
                            va_arg(p_args, unsigned int);
                    else
                        n = va_arg(p_args, unsigned int);

                    len = base_len(n, 16);

                    if (hash_flag && n != 0)
                        len += 2;

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);

                    if (hash_flag && n != 0)
                    {
                        count += add_to_buffer('0',
                                                buffer,
                                                &buf_index);

                        count += add_to_buffer('x',
                                               buffer,
                                               &buf_index);

                    }
                    count += print_ulong_base(n,
                        "0123456790abcdef",
                        buffer,
                        &buf_index);
                    break;
                }


                case 'X':
                {
                    unsigned long n;
                    int len;

                    if (long_flag)
                        n = va_arg(p_args, unsigned long);
                    else if (short_flag)
                        n = (unsigned short)
                            va_arg(p_args, unsigned int);
                    else
                        n = va_arg(p_args, unsigned int);
                    
                    len = base_len(n, 16);

                    if (hash_flag && n != 0)
                        len += 2;

                    count += print_padding(width,
                                           len,
                                           buffer,
                                           &buf_index);
                    if (hash_flag && n != 0)
                    {
                        count += add_to_buffer('0',
                                               buffer,
                                               &buf_index);

                        count += add_to_buffer('X',
                                               buffer,
                                               &buf_index);
                    }

                    count += print_ulong_base(n,
                        "0123456790ABCDEF",
                        buffer,
                        &buf_index);
                    break;
                }


                case '%':
                    count += add_to_buffer(
                        '%',
                        buffer,
                        &buf_index);
                    break;


               

                case 'S':
                    count += print_special_string(
                        va_arg(p_args, char *),
                        buffer,
                        &buf_index);
                    break;

                case 'p':
                    count += print_pointer(
                                        va_arg(p_args, void *),
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
