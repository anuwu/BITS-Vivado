############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project DigitRecognizer
set_top forward
add_files DigitRecognizer/minibatch.cpp
add_files -tb DigitRecognizer/minibatch_tp.cpp -csimflags "100"
open_solution "solution1"
set_part {xc7vx485tffg1157-1}
create_clock -period 10 -name default
#source "./DigitRecognizer/solution1/directives.tcl"
csim_design -argv {100}
csynth_design
cosim_design
export_design -format ip_catalog
