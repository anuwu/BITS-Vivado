#include "hls_math.h"
#include <math.h>
#include <ap_fixed.h>

typedef ap_fixed<16, 5> fix_t ;

double distDouble (double x1, double y1, double x2, double y2)
{
	return hls::sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2)) ;
}

double distFloat (float x1, float y1, float x2, float y2)
{
	return hls::sqrt (pow (x2 - x1, 2) + pow (y2 - y1, 2)) ;
}

fix_t distFix (fix_t x1, fix_t y1, fix_t x2, fix_t y2)
{
	return hls::sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) ;
}
