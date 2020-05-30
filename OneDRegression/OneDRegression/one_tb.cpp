#include <stdio.h>
#include "one.h"

float real_wt = 7.131657, real_b = 1.638081 ;

int main ()
{
	/*
	fix_t wt, b ;
	wt = 1 ;
	b = 1 ;
	fix_t mse = getMse (wt, b) ;
	*/

	float wt, b, mse_result ;
	wt = 5 ;
	b = 5 ;

	int i = 0 ;
	while (i < 200)
	{
		getMse1 (&wt, &b) ;
		//printf ("MSE = %f\n", (double)mse_result) ;
		i++ ;
	}

	printf ("real_wt = %f, wt = %f\n", (double)real_wt, (double)wt) ;
	printf ("real_b = %f, b = %f\n", (double)real_b, (double)b) ;

	return 0 ;
}
