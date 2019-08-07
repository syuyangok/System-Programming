#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void reverse(char *s)
{
	size_t len = strlen(s);

	//find s address, then add len -1 to find last char address
	char *t = s + len - 1;

	while (t >= s)
	{
		printf("%c", *t);
		t = t -1;

	}

	puts ("");



}


int main(void)
{

	char s[] = "onetwothreefour";
	int start = 2;

	if (0)
	{
		reverse (s);
	}
	else
		printf("This is end!");

	/*
	char *t = s;

	printf("The size of the message is %d \n", (int)sizeof(s));
	printf("The size of the message is %d \n", (int)sizeof(t));
	printf("\n");

	int drink[] = {4, 2, 3};
	printf("Drink  %d \n", 2[drink]);
	printf("Drink  %p \n", drink);
	printf("Drink  %d \n", *(drink + 2));
	printf("Drink  %p \n", drink);
	*/

	return 0;
}


