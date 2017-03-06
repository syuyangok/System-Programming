/*
 *This program is to read text files and search certain name
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int myargv;

struct _data
{
    char *first, *middle, *last;	
    long number;
};



int SCAN(FILE *(*stream))
{
    
    char *text;
	size_t n;
    int cnt = 0;

   while (1) 
	{      				
	 text = NULL;
		n = 0;
      getline(&text, &n, *stream);	// getline expects 3 pointer arguments.
	  free(text);
      if (feof(*stream)) break;
      cnt++;
   }	
	
	return cnt;
}//scan end



struct _data *LOAD(FILE *stream, int size)
{

	char * line;
    size_t len = 0;
    size_t read;
    int i;


	rewind(stream);

    struct _data *indata;//Create pointer for struct
    indata = (struct _data*)calloc(size, sizeof(struct _data));

    if(indata==NULL)
    {
        printf("ERROR - could not allocate memory.\n");
        exit(0);
    }

	
    for(i=0; i<size; i++)
    {
		line = NULL;
		len = 0;
        read = getline(&line, &len, stream);        

        /* get the token */
        indata[i].first = strdup(strtok(line, " "));//use strdup to allocate space to name pointer		
		indata[i].middle = strdup(strtok(NULL, " "));//use strdup to allocate space to name pointer		
		indata[i].last = strdup(strtok(NULL, " "));//use strdup to allocate space to name pointer	
        indata[i].number = atoi(strtok(NULL, " "));
		free(line);	
		//printf("Counter of line is: %d.\n", i);
		
    }	
	
    return indata;

};//load end.





void SEARCH(struct _data *BlackBox, int size, char *name)
{
	int m;
	int nofound = 1;//set not found to be true first.
	char *newname;
	char ch = '_';
	char *cch = "_";

	
	
	if (myargv==2)// search fist name.
	{
		
		for (m=0; m< size; m++)
		{
			if (!(strcmp(BlackBox[m].first, name)))
			{
				printf("**********************************************\n");
				printf("* The name was found at the %d entry.        *\n", m+1);
				printf("**********************************************\n");
				nofound = 0;// change not found to false.

			}
		}
	}

	else 
	{				
		
			
		for (m=0; m< size; m++)
			{
				if (strchr(name, ch))//search by first wildcard last name.
				{
					newname = calloc(strlen(BlackBox[m].first)+strlen(BlackBox[m].last)+2, sizeof(char));
					strcpy(newname, BlackBox[m].first);
					strcat(newname, cch);
					strcat(newname, BlackBox[m].last);
				}
				else//search by first middle last name.
				{
					newname = calloc(strlen(BlackBox[m].first)+strlen(BlackBox[m].middle)+strlen(BlackBox[m].last)+1, sizeof(char));
					strcpy(newname, BlackBox[m].first);
					strcat(newname, BlackBox[m].middle);
					strcat(newname, BlackBox[m].last);
				}

				if(!(strcmp(newname, name)))
				{
						printf("**********************************************\n");
						printf("* The name was found at the %d entry.        *\n", m+1);
						printf("**********************************************\n");
						nofound = 0;// change not found to false.
				}	
				free(newname);
				newname = NULL;			

		}//for loop end	

	}


	if (nofound)
	{
		printf("**********************************************\n");
		printf("* The name was NOT found.                    *\n");
		printf("**********************************************\n");
	}

}//search end.



void FREE(struct _data *BlackBox, int size)
{
	int m;
	for (m=0; m< size; m++)
	{
		free (BlackBox[m].first);//free the space from strdup();
		free (BlackBox[m].middle);
		free (BlackBox[m].last);
		BlackBox[m].first = NULL;
		BlackBox[m].middle = NULL;
		BlackBox[m].last = NULL;
	}
	free (BlackBox);
	BlackBox = NULL;
}//Free end.



//int main(void)
int main( int argv, char **argc)
{

    FILE *data;
	char *inName;
    int count;    
	myargv = argv;
	int flen=0;
	int mlen=0;
	int llen=0;

	if (argv == 1)//catch error no name input
	{
		printf("**********************************************\n");
        printf("* You must include a name to search for.     *\n");
		printf("**********************************************\n");
        return 2;		

	}

	if (argv == 3)//catch error no middlename/wildcard input
	{
		printf("**********************************************\n");
        printf("* You must inlcude correct name to search.   *\n");
		printf("**********************************************\n");
        return 2;		

	}

    data = fopen("./hw6.data", "r");
    if (data == NULL)
    {
        printf("ERROR - file not opened.\n");
        exit(0);
    }

	//read line number of file
	count = SCAN(&data);	
	
	//load data to struct
    //struct _data *mydata = calloc(count, sizeof(book));
    struct _data *mydata = LOAD(data, count);

	fclose(data);	


	if (argv == 2)//only have fist name
	{

		SEARCH(mydata, count, argc[1]);	


	}

	else //search by first last or first middle last
	{
		flen = strlen(argc[1]);
		mlen = strlen(argc[2]); 
		llen = strlen(argc[3]);
		
		inName = calloc(flen+mlen+llen+1, sizeof(char));
		strcpy(inName, argc[1]);
		strcat(inName, argc[2]);
		strcat(inName, argc[3]);

		//search the name
		SEARCH(mydata, count, inName);	

		//free space
		free(inName);
		inName = NULL;

	}


    FREE(mydata, count);

    return 0;
}//main end





