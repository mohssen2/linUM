
#include <stdio.h>
#include "resistors.h"


 

int main ()
{
	int count, voltage; 
	char conn;
	float resultat;

	printf("Ange spänningskälla i V: ");
 	scanf("%d", &voltage);

	printf("Ange koppling [S | P]: ");		
 	scanf( " %c", &conn);
									
	printf("Antal komponenter: ");
	scanf( "%d", &count);

	float array[count];

//	printf("Den resulterande resistansen blir: %.0f\n", calc_resistance(count, conn, array));

  	return 0;

}


/*
 int voltage = 0, conn = 0, count = 0, i;
  
int main()
{
 printf("Ange spänningskälla i V: ");
 scanf("%d", &voltage);
 printf("Ange koppling[S | P]: ");
 getchar();
 conn = getchar();
 printf("Antal komponenter : ");
 scanf("%d", &count);

 float array[count];
 for (i = 1; i <= count; i++)
	{
	 printf("Komponent %d i ohm: ", i );
	 scanf("%f", &array[i]);
	}
 	
  
  float *p;
  p = array;
  for (i = 1; i <= count; i++)
        printf("%0.1f \n", *(p+i)); */
           
             
 
