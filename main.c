#include <stdio.h>
#include "resistance.h"
#include "power.h"

int main ()
{
	//Code by Mohssen
	int count, voltage, i, tmp_power; 
	char conn;
	float power_return, power_result, result;

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
	
	
	printf("Ersättningsresistans:\n%.1f ohm\n", calc_resistance(count, conn, array));
	//Code by Tommy
	//Needed to adjust the power value below, otherwise compiler rounds up the value
	power_return =(calc_power_i(voltage, calc_resistance(count,conn,array)));
	tmp_power = power_return*100;
	power_result = tmp_power/100.0;
	printf("Effekt:\n%.2f W\n", power_result);
	//Code for library3 by x
  	return 0;

}



