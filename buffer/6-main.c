#include "main.h"

int main(void)
{
    _printf("[%05d]\n", 98);
    _printf("[%08x]\n", 98);
    _printf("[%08X]\n", 98);
    _printf("[%-5d]\n", 98);
    _printf("%r\n", "School");
    _printf("%R\n", "Hello World");

    return (0);
}
