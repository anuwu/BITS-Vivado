#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_start", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_done", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_idle", 1, hls_out, -1, "", "", 1),
	Port_Property("ap_ready", 1, hls_out, -1, "", "", 1),
	Port_Property("val_r", 8, hls_in, 0, "ap_none", "in_data", 1),
	Port_Property("in_vec_dout", 8, hls_in, 1, "ap_fifo", "fifo_data", 10),
	Port_Property("in_vec_empty_n", 1, hls_in, 1, "ap_fifo", "fifo_status", 10),
	Port_Property("in_vec_read", 1, hls_out, 1, "ap_fifo", "fifo_update", 10),
	Port_Property("out_vec_din", 8, hls_out, 2, "ap_fifo", "fifo_data", 10),
	Port_Property("out_vec_full_n", 1, hls_in, 2, "ap_fifo", "fifo_status", 10),
	Port_Property("out_vec_write", 1, hls_out, 2, "ap_fifo", "fifo_update", 10),
};
const char* HLS_Design_Meta::dut_name = "find";
