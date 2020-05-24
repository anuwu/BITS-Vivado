############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FFT
set_top FFT
add_files ../teach-fpga/01-fft/vhls/fixed/fft.cpp
add_files -tb ../teach-fpga/01-fft/vhls/fixed/fft_tb.cpp
add_files -tb ../teach-fpga/01-fft/build/inp_cpp.txt
add_files -tb ../teach-fpga/01-fft/build/out_cpp.txt
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./FFT/solution1/directives.tcl"
csim_design
csynth_design
cosim_design -trace_level all -tool xsim
export_design -format ip_catalog
