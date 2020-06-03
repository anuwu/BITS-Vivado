#include <stdio.h>
#include <ap_fixed.h>

typedef ap_fixed<16, 5> fix_t ;

fix_t distFix (fix_t x1, fix_t y1, fix_t x2, fix_t y2) ;
double distFloat (float x1, float y1, float x2, float y2) ;
double distDouble (double x1, double y1, double x2, double y2) ;

int main ()
{
	double Ax, Ay ;
	double Bx, By ;

	Ax = 3 ;
	Ay = 0 ;
	Bx = 0 ;
	By = 4 ;

	double dist_double = distDouble (Ax, Ay, Bx, By) ;
	float dist_float = distFloat ((float)Ax, (float)Ay, (float)Bx, (float)By) ;
	fix_t dist_fixed = distFix ((fix_t)Ax, (fix_t)Ay, (fix_t)Bx, (fix_t)By) ;

	printf ("Distance between A-B(DOUBLE):%f\n", (float)dist_double) ;
	printf ("Distance between A-B(FLOAT):%f\n", (float)dist_float) ;
	printf ("Distance between A-B(FIXED):%f\n", (float)dist_fixed) ;
	return 0 ;
}
