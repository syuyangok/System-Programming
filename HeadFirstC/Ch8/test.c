#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main()
{
    char msg[80];
    puts("Enter message to encrypt:");
    fgets(msg, 80, stdin);

    encrypt(msg);
    printf("%s \n", msg);

    printf("Checksum: %i \n", checksum(msg));
    

    encrypt(msg);
    printf("Decrypted back to: %s \n", msg);


}
