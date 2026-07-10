#include "main.h"

int main(void)
{
    _printf("%hd\n", (short)32000);
    _printf("%ld\n", 1234567890L);

    _printf("%hu\n", (unsigned short)65000);
    _printf("%lu\n", 4000000000UL);

    _printf("%lx\n", 4294967295UL);
    _printf("%ho\n", (unsigned short)511);

    return (0);
}
