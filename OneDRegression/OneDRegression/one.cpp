#include "hls_math.h"
#include "one.h"
#include <math.h>

fix_t data[10][2] = {{2.0,4.0},
				{3.0,7.0},
				{4.0,7.6},
				{5.0,11.0},
				{5.0,11.5},
				{5.0,10.0},
				{1.0,1.5},
				{3.0,5.0},
				{4.0,8.2},
				{6.0,11.7}
} ;

fix_t getMse (fix_t wt, fix_t b)
{
	fix_t mse = 0 ;
	fix_t term, termSq ;
	for (int i = 0 ; i < 10 ; i++)
	{
		term = data[i][1] - (wt*data[i][0] + b) ;
		termSq = term*term ;
		mse += termSq ;
		printf ("The term = %f, termSq = %f, mse = %f\n", (double)term, (double)termSq, (double)mse) ;
		//mse += hls::pow (data[i][1] - (wt*data[i][0] + b) , 2) ;
	}

	return mse ;
}
