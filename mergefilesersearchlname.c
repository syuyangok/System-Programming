/*
 *This program is to read text files and search certain name

 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct _data
{
    char *name;
    long number;
}book;


/*
 *This this function will open the file/stream 
 *@stream is FILE **, a pointer, by reference.
 *@return an integer indicating how many lines there are.
 */
int SCAN(FILE *(*stream))
{
    
    char *n;
    int cnt = 0;
	size_t num=0;

    while (1)
    {
       n=NULL;
		getline(&n, &num, *stream);
		free(n);
       if (feof(*stream)) break;
       cnt++;
    }

    return cnt;
}//scan end



/*
 *This this function will rewind file, create the dynamic array (of size), and read data to dynamic array 
 *@stream is FILE *, a pointer to the file.
 *@size is int, the size of the array.
 *@return an array of struct.
 */

struct _data *LOAD(FILE *stream, int size)
{

	char * line = NULL;
    size_t len = 0;
    size_t read;
    int i;


	rewind(stream);

    struct _data *indata;//Create pointer for struct
    indata = calloc(size, sizeof(book));

    if(indata==NULL)
    {
        printf("ERROR - could not allocate memory.\n");
        return 0;
    }


    for(i=0; i<size; i++)
    {
        read = getline(&line, &len, stream);
        //printf("Counter of line is: %d.\n", i);

        /* get the token */
        indata[i].name = strdup(strtok(line, " "));//use strdup to allocate space to name pointer
        indata[i].number = atoi(strtok(NULL, " "));

    }

	//free space
    if (line)
    {
        free(line);
		line = NULL;
    }

    return indata;

};//load end.



/*
 *This this function will search the anme in the dynamic array 
 *@BlackBox  struct _data * , the dynamic array
 *@size is int, the size of the array.
 *@name  is a char pointer, the name will be searched. 
 */

void SEARCH(struct _data *BlackBox, char *name, int size)
{
	int m;
	int nofound = 1;//set not found to be true first.

	for (m=0; m< size; m++)
	{
		if (!(strcmp(BlackBox[m].name, name)))
		{
			printf("**********************************************\n");
			printf("* The name was found at the %d entry.        *\n", m+1);
			printf("**********************************************\n");
			nofound = 0;// change not found to false.

		}
	}
	if (nofound)
	{
		printf("**********************************************\n");
		printf("* The name was NOT found.                    *\n");
		printf("**********************************************\n");
	}

}//search end.


/*
 *This this function will free up all of the dynamic memory we allocated 
 *@BlackBox  struct _data * , the dynamic array
 *@size is int, the size of the array.
 */

void FREE(struct _data *BlackBox, int size)
{
	int m;
	for (m=0; m< size; m++)
	{
		free (BlackBox[m].name);//free the space from strdup();
		BlackBox[m].name = NULL;
	}
	free (BlackBox);
	BlackBox = NULL;
}//Free end.



//int main(void)
int main( int argv, char **argc)
{

    FILE *data;
    int count;    

	if (argv != 2)
	{
		printf("**********************************************\n");
        printf("* You must include a name to search for.     *\n");
		printf("**********************************************\n");
        return 2;		

	}


    data = fopen("./hw5.data", "r");
    if (data == NULL)
    {
        printf("ERROR - file not opened.\n");
        return 2;
    }

	//read line number of file
	count = SCAN(&data);
	//printf("Counter of line is: %d.\n", count);

	//load data to struct
    //struct _data *mydata = calloc(count, sizeof(book));
    struct _data *mydata = LOAD(data, count);

	fclose(data);


	//search the name
	SEARCH(mydata, argc[1], count);

	//free space
    FREE(mydata, count);

    return 0;
}//main end





