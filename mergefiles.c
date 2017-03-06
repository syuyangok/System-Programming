/*
 *This program is to merge 3 int text files to a new file
 *This program didn't use system commands.
 */


#include <stdio.h>
#include <stdlib.h>

/*
 * bubble sort function to sort a int array in increasing order.
 * param list is the array to be sort.
 * param n is the length of the array.
 */
void bubblesort(int list[], int n)
{
    int c, d, temp;
    for (c = 0 ; c < ( n - 1 ); c++)
      {
        for (d = 0 ; d < (n - c - 1); d++)
        {
          if (list[d] > list[d+1]) /* For decreasing order use < */
          {
            temp = list[d];
            list[d]   = list[d+1];
            list[d+1] = temp;
          }
        }
      }
}


int main(void)
{

    int *mylist;
    int length = 0;
    int size0, size1, size2;
    int i = 0;
    int j;

    //open 3 files
    FILE *file0;
    if ((file0 = fopen("list0.txt", "r"))== NULL)
    {
		fprintf(stderr, "Invalid file!\n");
        return 2;
    }


    FILE *file1;
    if ((file1 = fopen("list1.txt", "r"))== NULL)
    {
		fprintf(stderr, "Invalid file!\n");
        return 2;
    }

    FILE *file2;
    if ((file2 = fopen("list2.txt", "r"))== NULL)
    {
		fprintf(stderr, "Invalid file!\n");
        return 2;
    }


    // Calculat 3 files size
    fseek(file0,0,SEEK_END);
    size0 = ftell(file0); //current file position
    fseek(file0,0,SEEK_SET);


    fseek(file1,0,SEEK_END);
    size1 = ftell(file1); //current file position
    fseek(file1,0,SEEK_SET);

    fseek(file2,0,SEEK_END);
    size2 = ftell(file2); //current file position
    fseek(file2,0,SEEK_SET);

    mylist = malloc(size0 + size1 + size2);//Allocate size to the list

    //read from file0
    while (fscanf(file0, "%d,", &mylist[i] ) == 1)
    {
        i++;
    }
    fclose(file0);

    //read from file1
    while (fscanf(file1, "%d,", &mylist[i] ) == 1)
    {
        i++;
    }
    fclose(file1);

    //read from file2
    while (fscanf(file2, "%d,", &mylist[i] ) == 1)
    {
        i++;
    }
    fclose(file2);


    //bubble sort list
    bubblesort(mylist, i);


    //Write to file.
    FILE *output = fopen("hw3.out", "w");
    for (j = 0; j < i; j++)
    {
           fprintf(output, "%d\n", mylist[j]);
    }

    fclose(output);
    free(mylist);

    return 0;
}//main end
