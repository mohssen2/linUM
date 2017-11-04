#include "component.h"

#define maxE12Counter 12
const float accuracy = 0.00001;
const int e12List[maxE12Counter] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};

//max allowed resistors
static int maxResCount = 3;

int e_resistence(float orig_resistence, float *res_array)
{
	// number of resistors in new component
	int resCount = 0;
	// the combined resistence of the new resistors
	int resultingRes = 0;
	// the new resistence is equal to orig_resistence 
	int resEqual = 0;


	while(resCount < maxResCount && !resEqual)
	{
		float resRest = orig_resistence - resultingRes;
		float exponent = floor(log10(resRest)) - 1;
		float baseValue = pow(10, exponent);
		
		int e12Counter = 0;
		while(e12Counter < maxE12Counter)
		{
			if(e12List[e12Counter + 1]*baseValue > resRest)
			{
				break;
			}
			e12Counter++;
		}
	
		float newRes = e12List[e12Counter]*baseValue;
		resultingRes += newRes;
		if(resultingRes < (orig_resistence + accuracy) && 
			resultingRes > (orig_resistence - accuracy))
		{
			resEqual = 1;
		}

		res_array[resCount] = newRes;
		resCount++;
	}
	return resCount;
}
