
log_wave -r /
set designtopgroup [add_wave_group "Design Top Signals"]
set coutputgroup [add_wave_group "C Outputs" -into $designtopgroup]
set data_OUT_group [add_wave_group data_OUT(axis) -into $coutputgroup]
add_wave /apatb_FFT_top/AESL_inst_FFT/data_OUT_TREADY -into $data_OUT_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/AESL_inst_FFT/data_OUT_TVALID -into $data_OUT_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/AESL_inst_FFT/data_OUT_TDATA -into $data_OUT_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set data_IN_group [add_wave_group data_IN(axis) -into $cinputgroup]
add_wave /apatb_FFT_top/AESL_inst_FFT/data_IN_TREADY -into $data_IN_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/AESL_inst_FFT/data_IN_TVALID -into $data_IN_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/AESL_inst_FFT/data_IN_TDATA -into $data_IN_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_start -into $blocksiggroup
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_done -into $blocksiggroup
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_idle -into $blocksiggroup
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_FFT_top/AESL_inst_FFT/ap_clk -into $clockgroup
set testbenchgroup [add_wave_group "Test Bench Signals"]
set tbinternalsiggroup [add_wave_group "Internal Signals" -into $testbenchgroup]
set tb_simstatus_group [add_wave_group "Simulation Status" -into $tbinternalsiggroup]
set tb_portdepth_group [add_wave_group "Port Depth" -into $tbinternalsiggroup]
add_wave /apatb_FFT_top/AUTOTB_TRANSACTION_NUM -into $tb_simstatus_group -radix hex
add_wave /apatb_FFT_top/ready_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_FFT_top/done_cnt -into $tb_simstatus_group -radix hex
add_wave /apatb_FFT_top/LENGTH_data_IN -into $tb_portdepth_group -radix hex
add_wave /apatb_FFT_top/LENGTH_data_OUT -into $tb_portdepth_group -radix hex
set tbcoutputgroup [add_wave_group "C Outputs" -into $testbenchgroup]
set tb_data_OUT_group [add_wave_group data_OUT(axis) -into $tbcoutputgroup]
add_wave /apatb_FFT_top/data_OUT_TREADY -into $tb_data_OUT_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/data_OUT_TVALID -into $tb_data_OUT_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/data_OUT_TDATA -into $tb_data_OUT_group -radix hex
set tbcinputgroup [add_wave_group "C Inputs" -into $testbenchgroup]
set tb_data_IN_group [add_wave_group data_IN(axis) -into $tbcinputgroup]
add_wave /apatb_FFT_top/data_IN_TREADY -into $tb_data_IN_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/data_IN_TVALID -into $tb_data_IN_group -color #ffff00 -radix hex
add_wave /apatb_FFT_top/data_IN_TDATA -into $tb_data_IN_group -radix hex
save_wave_config FFT.wcfg
run all
quit

