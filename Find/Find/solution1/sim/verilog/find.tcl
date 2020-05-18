
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set out_vec_group [add_wave_group out_vec(fifo) -into $coutputgroup]
add_wave /apatb_find_top/AESL_inst_find/out_vec_write -into $out_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/AESL_inst_find/out_vec_full_n -into $out_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/AESL_inst_find/out_vec_din -into $out_vec_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set in_vec_group [add_wave_group in_vec(fifo) -into $cinputgroup]
add_wave /apatb_find_top/AESL_inst_find/in_vec_read -into $in_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/AESL_inst_find/in_vec_empty_n -into $in_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/AESL_inst_find/in_vec_dout -into $in_vec_group -radix hex
set val_group [add_wave_group val(wire) -into $cinputgroup]
add_wave /apatb_find_top/AESL_inst_find/val_r -into $val_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_find_top/AESL_inst_find/ap_start -into $blocksiggroup
add_wave /apatb_find_top/AESL_inst_find/ap_done -into $blocksiggroup
add_wave /apatb_find_top/AESL_inst_find/ap_idle -into $blocksiggroup
add_wave /apatb_find_top/AESL_inst_find/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_find_top/AESL_inst_find/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_find_top/AESL_inst_find/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_find_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_find_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_find_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_find_top/LENGTH_val_r -into $tb_portdepth_group -radix hex
add_wave /apatb_find_top/LENGTH_in_vec -into $tb_portdepth_group -radix hex
add_wave /apatb_find_top/LENGTH_out_vec -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_out_vec_group [add_wave_group out_vec(fifo) -into $tbcoutputgroup]
add_wave /apatb_find_top/out_vec_write -into $tb_out_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/out_vec_full_n -into $tb_out_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/out_vec_din -into $tb_out_vec_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_in_vec_group [add_wave_group in_vec(fifo) -into $tbcinputgroup]
add_wave /apatb_find_top/in_vec_read -into $tb_in_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/in_vec_empty_n -into $tb_in_vec_group -color #ffff00 -radix hex
add_wave /apatb_find_top/in_vec_dout -into $tb_in_vec_group -radix hex
set tb_val_group [add_wave_group val(wire) -into $tbcinputgroup]
add_wave /apatb_find_top/val_r -into $tb_val_group -radix hex
save_wave_config find.wcfg
run all
quit

