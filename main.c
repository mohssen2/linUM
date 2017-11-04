#include <stdio.h>
#include "resistance.h"
#include "power.h"
#include "component.h" 

int main ()
{
	//Code by Mohssen
	int count, voltage, i, tmp_power; 
	char conn;
	float power_return, power_result, result, results[3], orig;

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
	
	float calculated_resistence = calc_resistance(count, conn, array);
	printf("Ersättningsresistans:\n%.1f ohm\n", calculated_resistence);
	//Code by Tommy
	//Needed to adjust the power value below, otherwise compiler rounds up the value
	power_return =(calc_power_r(voltage, calc_resistance(count,conn,array)));
	tmp_power = power_return*100;
	power_result = tmp_power/100.0;
	printf("Effekt:\n%.2f W\n", power_result);
	
	//Code by Dennis
	float resistor_array[3];
	int resistors_count = e_resistence(calculated_resistence, resistor_array);
	printf("Ersättningresistanser i E12-serien kopplade i serie:\n");
	for(i = 0; i < resistors_count; i++)
	{
		printf("%.0f\n", resistor_array[i]);
	}

  	return 0;
}
