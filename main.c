
#include <stdio.h>
#include "resistance.h"

 

int main ()
{
	int count, voltage, i; 
	char conn;
	float resultat;

	printf("Ange spänningskälla i V: ");
 	scanf("%d", &voltage);

	printf("Ange koppling [S | P]: ");		
 	scanf( " %c", &conn);
									
	printf("Antal komponenter: ");
	scanf( "%d", &count);

	float array[count] ;
	
	 for (i = 0; i <= count-1; i++)
	   {
	     printf("Komponent %d i ohm: ", i+1 );
	     scanf("%f", &array[i]);
	   }	
	
	
	printf("Ersättningsresistans: %0.f\n", calc_resistance(count, conn, array));

  	return 0;

}



