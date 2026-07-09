#include "main.h"

void flush_buffer(char buffer[], int *buf_index)
{
    if (*buf_index > 0)
    {
        write(1, buffer, *buf_index);
        *buf_index = 0;
    }
    
}
