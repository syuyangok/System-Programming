#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 int main(int argc, char *argv[])
 {

   char line[80];

   if (argc != 4)
   {
       fprintf(stderr, "Please enter 5 arguments\n");
       return 1;
   }
   //Build file handles
   FILE *in;
   if( !(in = fopen("gps.csv", "r")))
      {
        fprintf(stderr, "Can't open the file.\n");
       return 1;
      }

   FILE *file1 = fopen("argv[2]", "w");

   FILE *file2 = fopen("argv[3]", "w");

   //read files
   while (fscanf(in, "%79[^\n]\n",line) == 1)
   {
       if (strstr(line, argv[1]))
       {
           fprintf(file1, "%s\n", line);
       }

       else
       {
           fprintf(file2, "%s\n", line);
       }

   }

   fclose(file1);
   fclose(file2);


   return 0;
}//main end
