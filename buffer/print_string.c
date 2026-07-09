#include "main.h"

/**
*print_string - return strings
*/


int print_string(char *p_string,
                 char buffer[],
                 int *buf_index)
{
    int index = 0;
    int count = 0;

    if (p_string == NULL) 
        p_string = "(null)";
   

    while (p_string[index] != '\0') 
    {

        count += add_to_buffer(p_string[index], buffer, buf_index);
        index++;

    }

    return (count);


  

}
