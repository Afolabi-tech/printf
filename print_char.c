#include "main.h"

/**
*print_char - return characters
*/


int print_char(char p_char){
    return (write(1, &p_char, 1));
}
