#include <ap_int.h>

ap_uint<17> csd (ap_uint<17> inA, ap_uint<17> inB, unsigned char op)
{
	if (op == 1)
		return inA + inB ;
	else
		return inA - inB ;
}
