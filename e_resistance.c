#include <stdio.h>
#include <stdio.h>
#include "e_resistance.h"

int e_resistance(float orig_resistance, float *res_array )
{
int count=0;
int e12[12]={10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82};
int len=12;
int resistance;
//float res_array[3]={0.0, 0.0, 0.0};


printf("Type resistance (2 digits):");
scanf("%d", &resistance);

if (resistance>=100 && resistance<=9)
{
	printf("Wrong input format. Input an integer between 10 and 99.");
}
else
{
	for (int i=len-1; i>=0; i--)
	{
		for (int j=len-1; j>=0; j--)
		{
			for (int k=len-1; k>=0; k--)
			{
				if (resistance-e12[i]==0)
				{
					res_array[0]=e12[i];
					res_array[1]=0;
					res_array[2]=0;
					return 1;
					i,j,k=-1;
				}
				else if (resistance-e12[i]-e12[j]==0)
				{
		                        res_array[0]=e12[i];
			                res_array[1]=e12[j];
					res_array[2]=0;
					return 2;
					i,j,k=-1;		
				}
				else if (resistance-e12[i]-e12[j]-e12[k]==0)
				{
                                        res_array[0]=e12[i];
                                        res_array[1]=e12[j];
                                        res_array[2]=e12[k];
					return 3;
					i,j,k=-1;
				}
			}
		}
	}
}
}
