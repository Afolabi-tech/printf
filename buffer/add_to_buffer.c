#include "main.h"

int add_to_buffer(char p_char, 
                  char buffer[], 
                  int *buf_index)
{
    buffer[*buf_index] = p_char;
    (*buf_index)++;

    if (*buf_index == BUFFER_SIZE)
        flush_buffer(buffer, buf_index);


    return (1);
}
