#include "encrypt.h"

void encrypt (char *m)
{
    char c;
    while(*m)
    {
        *m = *m^31;
        m++;
    }
}
