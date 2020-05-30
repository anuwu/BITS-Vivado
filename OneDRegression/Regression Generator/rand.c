#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SIZE 100

float getRand ()
{
	float f = rand()/(float)RAND_MAX ;

	return f ;
}

int main ()
{
	srand (time(0)) ;
	int i ;
	float wt, b ;
	float x[SIZE], y[SIZE] ;

	wt = 1 + getRand () * 9 ;
	b = getRand () * 5 ;

	printf ("wt = %f, b = %f\n", wt, b) ;

	for (i = 0 ; i < SIZE ; i++)
	{
		x[i] = getRand () * 100 ;
		y[i] = wt * x[i] + b + (getRand () - 0.5) * wt * x[i]/2 ;

		printf ("[%f, %f],\n", x[i], y[i]) ;
	}

	return 0 ;
}