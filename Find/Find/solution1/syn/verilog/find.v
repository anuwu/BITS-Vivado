// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="find,hls_ip_2019_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7vx485t-ffg1157-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.985000,HLS_SYN_LAT=11,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=6,HLS_SYN_LUT=77,HLS_VERSION=2019_2}" *)

module find (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        val_r,
        in_vec_dout,
        in_vec_empty_n,
        in_vec_read,
        out_vec_din,
        out_vec_full_n,
        out_vec_write
);

parameter    ap_ST_fsm_state1 = 2'd1;
parameter    ap_ST_fsm_state2 = 2'd2;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [7:0] val_r;
input  [7:0] in_vec_dout;
input   in_vec_empty_n;
output   in_vec_read;
output  [7:0] out_vec_din;
input   out_vec_full_n;
output   out_vec_write;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg in_vec_read;
reg out_vec_write;

(* fsm_encoding = "none" *) reg   [1:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg    in_vec_blk_n;
wire    ap_CS_fsm_state2;
wire   [0:0] icmp_ln6_fu_66_p2;
reg    out_vec_blk_n;
wire   [3:0] idx_fu_72_p2;
reg    ap_block_state2;
reg   [3:0] idx_0_reg_55;
wire   [0:0] icmp_ln8_fu_78_p2;
reg   [1:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 2'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        idx_0_reg_55 <= idx_fu_72_p2;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        idx_0_reg_55 <= 4'd0;
    end
end

always @ (*) begin
    if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        in_vec_blk_n = in_vec_empty_n;
    end else begin
        in_vec_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        in_vec_read = 1'b1;
    end else begin
        in_vec_read = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        out_vec_blk_n = out_vec_full_n;
    end else begin
        out_vec_blk_n = 1'b1;
    end
end

always @ (*) begin
    if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        out_vec_write = 1'b1;
    end else begin
        out_vec_write = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else if ((~(((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0))) & (icmp_ln6_fu_66_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

always @ (*) begin
    ap_block_state2 = (((icmp_ln6_fu_66_p2 == 1'd0) & (out_vec_full_n == 1'b0)) | ((icmp_ln6_fu_66_p2 == 1'd0) & (in_vec_empty_n == 1'b0)));
end

assign icmp_ln6_fu_66_p2 = ((idx_0_reg_55 == 4'd10) ? 1'b1 : 1'b0);

assign icmp_ln8_fu_78_p2 = ((in_vec_dout == val_r) ? 1'b1 : 1'b0);

assign idx_fu_72_p2 = (idx_0_reg_55 + 4'd1);

assign out_vec_din = icmp_ln8_fu_78_p2;

endmodule //find