#include "main.h"


int print_int(int n,
              char buffer[],
              int *buf_index)

{
    unsigned int num;
    int count;

    count = 0;

    if (n < 0)
    {
        count += add_to_buffer('-', buffer, buf_index);

        if (n == -2147483648)
            return (count + 
                    print_string("2147483648",
                                buffer,
                                buf_index));

        num = -n;
    }

    else 
        num = n;

    if (num / 10)

    {
        count += print_int(num / 10,
                            buffer,
                            buf_index);

    }

    
    count += add_to_buffer((n % 10) + '0',
                        buffer,
                        buf_index);
    
    return (count);
    
}
