/*
 *This program is to merge 3 text files to a new file alphabetically
 */

#include <stdlib.h>

int main (void)
{ 
    system("cat american0.txt american1.txt american2.txt | sort > words.txt");	

    return 0;

}
