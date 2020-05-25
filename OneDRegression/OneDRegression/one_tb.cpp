#include <stdio.h>
#include "one.h"

fix_t getMse (fix_t wt, fix_t b) ;

int main ()
{
	fix_t wt, b ;
	wt = 1 ;
	b = 1 ;
	fix_t mse = getMse (wt, b) ;

	printf ("MSE = %f\n", (double)mse) ;

	return 0 ;
}
