
 #include <stdio.h>
 
 int main()
 {
   float latitude;
   float longitude;
   char info[80];
   
 
  
   while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3) 
	{

		if ((latitude >20) &&  (latitude <30) )
		{
				if ((longitude > 20) &&  (longitude < 30) )
				{

					printf("%f,%f,%s\n", latitude, longitude, info);
				}
	
		 
	   }
	}
   
   return 0;
}
