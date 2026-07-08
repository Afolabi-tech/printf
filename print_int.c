#include "main.h"


int print_int(int n)
{
    unsigned int num;
    int count;
    char digit;

    count = 0;

    if (n < 0)
    {
        count += write(1,"-", 1);
        num = -n;
    }

    else 
        num = n;

    if (num / 10)

    {
        count += print_int(num / 10);

    }

    digit = ((num % 10) + '\0');
    count += write(1, &digit, 1);
    
    return (count);
    
}
