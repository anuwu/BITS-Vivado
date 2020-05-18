// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "E:/Vivado/Find/Find/find.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "E:/Vivado/Find/Find/find.cpp"
void find (char val, char in_vec[10], char out_vec[10])
{

#pragma HLS INTERFACE ap_fifo port=in_vec
#pragma HLS INTERFACE ap_fifo port=out_vec
 for (int idx = 0 ; idx < 10 ; idx++)
 {
  if (in_vec[idx] == val)
   out_vec[idx] = 1 ;
  else
   out_vec[idx] = 0 ;
 }
}
