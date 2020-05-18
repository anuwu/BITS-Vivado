
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set R_group [add_wave_group R(wire) -into $coutputgroup]
add_wave /apatb_divide_top/AESL_inst_divide/R_ap_vld -into $R_group -color #ffff00 -radix hex
add_wave /apatb_divide_top/AESL_inst_divide/R -into $R_group -radix hex
set Q_group [add_wave_group Q(wire) -into $coutputgroup]
add_wave /apatb_divide_top/AESL_inst_divide/Q_ap_vld -into $Q_group -color #ffff00 -radix hex
add_wave /apatb_divide_top/AESL_inst_divide/Q -into $Q_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set D_group [add_wave_group D(wire) -into $cinputgroup]
add_wave /apatb_divide_top/AESL_inst_divide/D -into $D_group -radix hex
set N_group [add_wave_group N(wire) -into $cinputgroup]
add_wave /apatb_divide_top/AESL_inst_divide/N -into $N_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_divide_top/AESL_inst_divide/ap_start -into $blocksiggroup
add_wave /apatb_divide_top/AESL_inst_divide/ap_done -into $blocksiggroup
add_wave /apatb_divide_top/AESL_inst_divide/ap_idle -into $blocksiggroup
add_wave /apatb_divide_top/AESL_inst_divide/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_divide_top/AESL_inst_divide/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_divide_top/AESL_inst_divide/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_divide_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_divide_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_divide_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_divide_top/LENGTH_N -into $tb_portdepth_group -radix hex
add_wave /apatb_divide_top/LENGTH_D -into $tb_portdepth_group -radix hex
add_wave /apatb_divide_top/LENGTH_Q -into $tb_portdepth_group -radix hex
add_wave /apatb_divide_top/LENGTH_R -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_R_group [add_wave_group R(wire) -into $tbcoutputgroup]
add_wave /apatb_divide_top/R_ap_vld -into $tb_R_group -color #ffff00 -radix hex
add_wave /apatb_divide_top/R -into $tb_R_group -radix hex
set tb_Q_group [add_wave_group Q(wire) -into $tbcoutputgroup]
add_wave /apatb_divide_top/Q_ap_vld -into $tb_Q_group -color #ffff00 -radix hex
add_wave /apatb_divide_top/Q -into $tb_Q_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_D_group [add_wave_group D(wire) -into $tbcinputgroup]
add_wave /apatb_divide_top/D -into $tb_D_group -radix hex
set tb_N_group [add_wave_group N(wire) -into $tbcinputgroup]
add_wave /apatb_divide_top/N -into $tb_N_group -radix hex
save_wave_config divide.wcfg
run all
quit

