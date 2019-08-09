#include <stdio.h>
#include "encrypt.h"


int main(void)
{
    char msg[80];
    puts("Enter message to encrypt:");
    fgets(msg, 80, stdin);

    encrypt(msg);
    printf("%s", msg);

}
