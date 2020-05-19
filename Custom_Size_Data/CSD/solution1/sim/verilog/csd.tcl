
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set agg_group [add_wave_group agg(wire) -into $coutputgroup]
add_wave /apatb_csd_top/AESL_inst_csd/ap_return -into $agg_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set op_group [add_wave_group op(wire) -into $cinputgroup]
add_wave /apatb_csd_top/AESL_inst_csd/op -into $op_group -radix hex
set B_group [add_wave_group B(wire) -into $cinputgroup]
add_wave /apatb_csd_top/AESL_inst_csd/B_V -into $B_group -radix hex
set A_group [add_wave_group A(wire) -into $cinputgroup]
add_wave /apatb_csd_top/AESL_inst_csd/A_V -into $A_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_csd_top/AESL_inst_csd/ap_start -into $blocksiggroup
add_wave /apatb_csd_top/AESL_inst_csd/ap_done -into $blocksiggroup
add_wave /apatb_csd_top/AESL_inst_csd/ap_idle -into $blocksiggroup
add_wave /apatb_csd_top/AESL_inst_csd/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_csd_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_csd_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_csd_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_csd_top/LENGTH_A_V -into $tb_portdepth_group -radix hex
add_wave /apatb_csd_top/LENGTH_B_V -into $tb_portdepth_group -radix hex
add_wave /apatb_csd_top/LENGTH_op -into $tb_portdepth_group -radix hex
add_wave /apatb_csd_top/LENGTH_ap_return -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_agg_group [add_wave_group agg(wire) -into $tbcoutputgroup]
add_wave /apatb_csd_top/ap_return -into $tb_agg_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_op_group [add_wave_group op(wire) -into $tbcinputgroup]
add_wave /apatb_csd_top/op -into $tb_op_group -radix hex
set tb_B_group [add_wave_group B(wire) -into $tbcinputgroup]
add_wave /apatb_csd_top/B_V -into $tb_B_group -radix hex
set tb_A_group [add_wave_group A(wire) -into $tbcinputgroup]
add_wave /apatb_csd_top/A_V -into $tb_A_group -radix hex
save_wave_config csd.wcfg
run all
quit

