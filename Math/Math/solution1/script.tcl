############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project Math
set_top distFix
add_files math.cpp
add_files -tb math_tb.cpp
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./Math/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
