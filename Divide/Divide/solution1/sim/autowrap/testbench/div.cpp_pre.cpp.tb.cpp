// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "E:/Vivado/Divide/Divide/div.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "E:/Vivado/Divide/Divide/div.cpp"
void divide (unsigned char N, unsigned char D, unsigned char *Q, unsigned char *R)
{
 if (D != 0)
 {
  *Q = 0 ;
  *R = 0 ;

  for (int i = 7 ; i >= 0 ; i--)
  {
   *R = *R << 1 ;

   char iBitN = (N & ( 1 << i)) >> i ;

   *R ^= (-iBitN ^ (*R)) & (1 << 0) ;

   if ((*R) >= D)
   {
    *R = *R - D ;
    *Q |= 1 << i ;
   }
  }
 }
}
