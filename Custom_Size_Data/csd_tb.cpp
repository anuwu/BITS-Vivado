#include <ap_int.h>
#include <stdio.h>
ap_uint<17> csd (ap_uint<17> inA, ap_uint<17> inB, unsigned char op) ;

int main ()
{
	ap_uint<17> A = 10 ;
	ap_uint<17> B = 8 ;
	ap_uint<17> sum, diff ;

	sum = csd (A, B, 1) ;
	diff = csd (A, B, 0) ;

	printf ("Sum = %d\n", (unsigned int)sum) ;
	printf ("Diff = %d\n", (unsigned int)diff) ;
}
