############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project OneDRegression
set_top getMse
add_files OneDRegression/one.cpp
add_files OneDRegression/one.h
add_files -tb OneDRegression/one_tb.cpp
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./OneDRegression/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
