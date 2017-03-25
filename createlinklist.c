/*
 *This program is to populate numbers to double linked list

 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int num;	
    struct node *next;
	struct node *prev;
};





void ADDING (struct node *(*head), struct node *(*tail),int n)
{
    struct node *temp;
	
	// build a new node to store data		
	temp = (struct node *)malloc(sizeof(struct node));			
	if(temp==NULL)
	{
		  printf("ERROR - could not allocate memory.\n");
		  exit(0);
	}
	//store data to node
	temp->num = n;
	temp->next = NULL;
	temp->prev = NULL;	


	
	// deal with head;
	if((*head) == NULL )
	{	
		(*head) = temp;
		(*tail) = (*head);
	} 		

	else// add to tail;
	{
		(*tail)->next = temp;
		temp->prev = (*tail);
		(*tail) = temp;

	}
	
}//add end






void TRAVERSE (struct node *head)
{
    
    struct node *current;
	current = head;
	
	
	while(current)
	{
		printf("Left to right output:	%3d\n", current->num);
		current = current->next;
	}
	

}

void TRAVERSEBACK (struct node *tail)//function to display list backward
{
    
    struct node *current;
	current = tail;
		
	
	while(current)
	{
		printf("Right to left output:	%3d\n", current->num);
		current = current->prev;
	}
	

}

void freelink (struct node *(*head))
{
    
    struct node *current= (*head);
	struct node *next;

	while(current !=NULL)
	{
		next = current->next;		
		
		free(current);	
		current = NULL;
		current = next;	
	}	
	(*head) = NULL;
	
}



int main (int argv, char **argc)
{
    struct node *head, *tail;
    head = NULL;
	tail = NULL;

	int count, i;


	if (argv != 2)
	{
		printf("**********************************************\n");
        printf("* You must input proper nubmer to run.     *\n");
		printf("**********************************************\n");
        return 2;		

	}



	count = atoi(argc[1]);	


	printf("Command line argument:	%3d\n", count);
	puts("");
    for(i=0; i<count+1; i++)
    {		    

		ADDING(&head, &tail, i);
		printf("Input data:	%11d\n", i);
		
    }	
	


	puts("");
    TRAVERSE(head);// display list from front
	puts("");
	TRAVERSEBACK(tail);// display list from back
	puts("");

	freelink(&head);
	
	
	
    return 0;
}


