#include "main.h"

int print_rot13(char *s,
                char buffer[],
                int *buf_index)
{
    int i;
    int j;
    int count;

    char alpha[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    char rot[] =
        "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    count = 0;

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i]; i++)
    {
        for (j = 0; alpha[j]; j++)
        {
            if (s[i] == alpha[j])
            {
                count += add_to_buffer(
                    rot[j],
                    buffer,
                    buf_index);
                break;
            }
        }

        if (!alpha[j])
            count += add_to_buffer(
                s[i],
                buffer,
                buf_index);
    }

    return (count);
}
