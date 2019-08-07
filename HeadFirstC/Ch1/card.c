/*
 *This program is change Cards to number value
 *@author: Yuyang Sun
 *@Headfirst C, chapter 1
 */


#include <stdio.h>
#include <stdlib.h>

int main(){

    char cardName[3];
    puts("Enter card name:");
    scanf("%2s", cardName);

    int val=0;

    printf("val store at : %p\n", &val);

    switch(cardName[0]){

    case 'K':
    case 'J':
    case 'Q':
    case 'A':
        val = 10;
        break;

    default:
        val = atoi(cardName);
    }

    /*
    if((cardName[0] == 'K')|| (cardName[0] == 'Q') ||(cardName[0] == 'J') ||(cardName[0] == 'A')){
        val = 10;
    }
    else{
        val = atoi(cardName);
    }
    */

    printf("The card value is: %i\n", val);

    return 0;
}
