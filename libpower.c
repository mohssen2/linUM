#include <stdio.h>
#include "power.h"
//library 2 by Tommy
//Calculates totally power process in a circuit (in 2 ways)
float calc_power_r(float volt, float resistance)
{
	float p;
	p=(volt*volt)/resistance;
	return p;
}

float calc_power_i(float volt, float current)
{
	float p;
	p=volt*current;
	return p;
}

