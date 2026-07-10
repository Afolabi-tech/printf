#include "main.h"

int main(void)
{
    int n = 98;
    int *p = &n;

    _printf("%p\n", p);
    _printf("%p\n", NULL);

    return (0);
}
