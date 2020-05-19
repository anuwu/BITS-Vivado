
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set agg_group [add_wave_group agg(wire) -into $coutputgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_return -into $agg_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set y2_group [add_wave_group y2(wire) -into $cinputgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/y2_V -into $y2_group -radix hex
set x2_group [add_wave_group x2(wire) -into $cinputgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/x2_V -into $x2_group -radix hex
set y1_group [add_wave_group y1(wire) -into $cinputgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/y1_V -into $y1_group -radix hex
set x1_group [add_wave_group x1(wire) -into $cinputgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/x1_V -into $x1_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_start -into $blocksiggroup
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_done -into $blocksiggroup
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_idle -into $blocksiggroup
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_distFix_top/AESL_inst_distFix/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_distFix_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_distFix_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_distFix_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_distFix_top/LENGTH_x1_V -into $tb_portdepth_group -radix hex
add_wave /apatb_distFix_top/LENGTH_y1_V -into $tb_portdepth_group -radix hex
add_wave /apatb_distFix_top/LENGTH_x2_V -into $tb_portdepth_group -radix hex
add_wave /apatb_distFix_top/LENGTH_y2_V -into $tb_portdepth_group -radix hex
add_wave /apatb_distFix_top/LENGTH_ap_return -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_agg_group [add_wave_group agg(wire) -into $tbcoutputgroup]
add_wave /apatb_distFix_top/ap_return -into $tb_agg_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_y2_group [add_wave_group y2(wire) -into $tbcinputgroup]
add_wave /apatb_distFix_top/y2_V -into $tb_y2_group -radix hex
set tb_x2_group [add_wave_group x2(wire) -into $tbcinputgroup]
add_wave /apatb_distFix_top/x2_V -into $tb_x2_group -radix hex
set tb_y1_group [add_wave_group y1(wire) -into $tbcinputgroup]
add_wave /apatb_distFix_top/y1_V -into $tb_y1_group -radix hex
set tb_x1_group [add_wave_group x1(wire) -into $tbcinputgroup]
add_wave /apatb_distFix_top/x1_V -into $tb_x1_group -radix hex
save_wave_config distFix.wcfg
run all
quit

