#include "main.h"

/**
*print_string - return strings
*/


int print_string(char *p_string){
    int index = 0;

    if (p_string == NULL) 
        p_string = "(null)";
   

    while (p_string[index] != '\0') {

        write(1, &p_string[index], 1);
        index++;

    }

    return (index);


  

}
