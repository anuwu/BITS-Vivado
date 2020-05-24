// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="divide,hls_ip_2019_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7vx485t-ffg1157-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=6.258700,HLS_SYN_LAT=9,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=33,HLS_SYN_LUT=194,HLS_VERSION=2019_2}" *)

module divide (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        N,
        D,
        Q,
        Q_ap_vld,
        R,
        R_ap_vld
);

parameter    ap_ST_fsm_state1 = 3'd1;
parameter    ap_ST_fsm_state2 = 3'd2;
parameter    ap_ST_fsm_state3 = 3'd4;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
input  [7:0] N;
input  [7:0] D;
output  [7:0] Q;
output   Q_ap_vld;
output  [7:0] R;
output   R_ap_vld;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg[7:0] Q;
reg Q_ap_vld;
reg[7:0] R;
reg R_ap_vld;

(* fsm_encoding = "none" *) reg   [2:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [0:0] icmp_ln3_fu_86_p2;
reg   [0:0] icmp_ln3_reg_203;
wire   [0:0] icmp_ln16_fu_151_p2;
reg   [0:0] icmp_ln16_reg_225;
wire    ap_CS_fsm_state2;
wire   [0:0] tmp_fu_106_p3;
wire   [7:0] sub_ln18_fu_159_p2;
reg   [7:0] sub_ln18_reg_229;
wire   [3:0] i_fu_186_p2;
wire    ap_CS_fsm_state3;
reg  signed [3:0] i_0_reg_74;
reg   [7:0] R_load_fu_38;
wire   [7:0] or_ln_fu_142_p3;
reg   [7:0] Q_load_fu_42;
wire   [7:0] or_ln19_fu_164_p2;
wire  signed [7:0] sext_ln8_fu_102_p1;
wire   [7:0] shl_ln12_fu_117_p2;
wire   [7:0] and_ln12_fu_123_p2;
wire   [7:0] iBitN_fu_128_p2;
wire   [6:0] trunc_ln14_1_fu_138_p1;
wire   [0:0] trunc_ln14_fu_134_p1;
reg   [2:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 3'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        Q_load_fu_42 <= or_ln19_fu_164_p2;
    end else if (((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        Q_load_fu_42 <= 8'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd1) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        R_load_fu_38 <= or_ln_fu_142_p3;
    end else if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        R_load_fu_38 <= sub_ln18_fu_159_p2;
    end else if (((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        R_load_fu_38 <= 8'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        i_0_reg_74 <= i_fu_186_p2;
    end else if (((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        i_0_reg_74 <= 4'd7;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        icmp_ln16_reg_225 <= icmp_ln16_fu_151_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        icmp_ln3_reg_203 <= icmp_ln3_fu_86_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        sub_ln18_reg_229 <= sub_ln18_fu_159_p2;
    end
end

always @ (*) begin
    if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        Q = or_ln19_fu_164_p2;
    end else if (((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        Q = 8'd0;
    end else begin
        Q = 'bx;
    end
end

always @ (*) begin
    if ((((tmp_fu_106_p3 == 1'd0) & (icmp_ln16_fu_151_p2 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2)) | ((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1)))) begin
        Q_ap_vld = 1'b1;
    end else begin
        Q_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln16_reg_225 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        R = sub_ln18_reg_229;
    end else if (((tmp_fu_106_p3 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        R = or_ln_fu_142_p3;
    end else if (((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1))) begin
        R = 8'd0;
    end else begin
        R = 'bx;
    end
end

always @ (*) begin
    if ((((icmp_ln16_reg_225 == 1'd0) & (1'b1 == ap_CS_fsm_state3)) | ((tmp_fu_106_p3 == 1'd0) & (icmp_ln3_reg_203 == 1'd0) & (1'b1 == ap_CS_fsm_state2)) | ((ap_start == 1'b1) & (icmp_ln3_fu_86_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state1)))) begin
        R_ap_vld = 1'b1;
    end else begin
        R_ap_vld = 1'b0;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) & ((tmp_fu_106_p3 == 1'd1) | (icmp_ln3_reg_203 == 1'd1)))) begin
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
    if (((1'b1 == ap_CS_fsm_state2) & ((tmp_fu_106_p3 == 1'd1) | (icmp_ln3_reg_203 == 1'd1)))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
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
            if (((1'b1 == ap_CS_fsm_state2) & ((tmp_fu_106_p3 == 1'd1) | (icmp_ln3_reg_203 == 1'd1)))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign and_ln12_fu_123_p2 = (shl_ln12_fu_117_p2 & N);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign iBitN_fu_128_p2 = and_ln12_fu_123_p2 >> sext_ln8_fu_102_p1;

assign i_fu_186_p2 = ($signed(i_0_reg_74) + $signed(4'd15));

assign icmp_ln16_fu_151_p2 = ((or_ln_fu_142_p3 < D) ? 1'b1 : 1'b0);

assign icmp_ln3_fu_86_p2 = ((D == 8'd0) ? 1'b1 : 1'b0);

assign or_ln19_fu_164_p2 = (shl_ln12_fu_117_p2 | Q_load_fu_42);

assign or_ln_fu_142_p3 = {{trunc_ln14_1_fu_138_p1}, {trunc_ln14_fu_134_p1}};

assign sext_ln8_fu_102_p1 = i_0_reg_74;

assign shl_ln12_fu_117_p2 = 8'd1 << sext_ln8_fu_102_p1;

assign sub_ln18_fu_159_p2 = (or_ln_fu_142_p3 - D);

assign tmp_fu_106_p3 = i_0_reg_74[32'd3];

assign trunc_ln14_1_fu_138_p1 = R_load_fu_38[6:0];

assign trunc_ln14_fu_134_p1 = iBitN_fu_128_p2[0:0];

endmodule //divide