-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
-- Version: 2019.2
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity distFloat is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    x1 : IN STD_LOGIC_VECTOR (31 downto 0);
    y1 : IN STD_LOGIC_VECTOR (31 downto 0);
    x2 : IN STD_LOGIC_VECTOR (31 downto 0);
    y2 : IN STD_LOGIC_VECTOR (31 downto 0);
    ap_return : OUT STD_LOGIC_VECTOR (63 downto 0) );
end;


architecture behav of distFloat is 
    attribute CORE_GENERATION_INFO : STRING;
    attribute CORE_GENERATION_INFO of behav : architecture is
    "distFloat,hls_ip_2019_2,{HLS_INPUT_TYPE=cxx,HLS_INPUT_FLOAT=1,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xc7vx485t-ffg1157-1,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=8.750000,HLS_SYN_LAT=69,HLS_SYN_TPT=none,HLS_SYN_MEM=96,HLS_SYN_DSP=147,HLS_SYN_FF=26346,HLS_SYN_LUT=17949,HLS_VERSION=2019_2}";
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000001000000000";
    constant ap_ST_fsm_state11 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000010000000000";
    constant ap_ST_fsm_state12 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000100000000000";
    constant ap_ST_fsm_state13 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000001000000000000";
    constant ap_ST_fsm_state14 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000010000000000000";
    constant ap_ST_fsm_state15 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000100000000000000";
    constant ap_ST_fsm_state16 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000001000000000000000";
    constant ap_ST_fsm_state17 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000010000000000000000";
    constant ap_ST_fsm_state18 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000100000000000000000";
    constant ap_ST_fsm_state19 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000001000000000000000000";
    constant ap_ST_fsm_state20 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000010000000000000000000";
    constant ap_ST_fsm_state21 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000100000000000000000000";
    constant ap_ST_fsm_state22 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000001000000000000000000000";
    constant ap_ST_fsm_state23 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000010000000000000000000000";
    constant ap_ST_fsm_state24 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000100000000000000000000000";
    constant ap_ST_fsm_state25 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000001000000000000000000000000";
    constant ap_ST_fsm_state26 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000010000000000000000000000000";
    constant ap_ST_fsm_state27 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000100000000000000000000000000";
    constant ap_ST_fsm_state28 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000001000000000000000000000000000";
    constant ap_ST_fsm_state29 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000010000000000000000000000000000";
    constant ap_ST_fsm_state30 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000100000000000000000000000000000";
    constant ap_ST_fsm_state31 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000001000000000000000000000000000000";
    constant ap_ST_fsm_state32 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000010000000000000000000000000000000";
    constant ap_ST_fsm_state33 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000100000000000000000000000000000000";
    constant ap_ST_fsm_state34 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000001000000000000000000000000000000000";
    constant ap_ST_fsm_state35 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000010000000000000000000000000000000000";
    constant ap_ST_fsm_state36 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000100000000000000000000000000000000000";
    constant ap_ST_fsm_state37 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000001000000000000000000000000000000000000";
    constant ap_ST_fsm_state38 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000010000000000000000000000000000000000000";
    constant ap_ST_fsm_state39 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000100000000000000000000000000000000000000";
    constant ap_ST_fsm_state40 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000001000000000000000000000000000000000000000";
    constant ap_ST_fsm_state41 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000010000000000000000000000000000000000000000";
    constant ap_ST_fsm_state42 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000100000000000000000000000000000000000000000";
    constant ap_ST_fsm_state43 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000001000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state44 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000010000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state45 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000100000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state46 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000001000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state47 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000010000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state48 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000100000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state49 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000001000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state50 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000010000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state51 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000100000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state52 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000001000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state53 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000010000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state54 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000100000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state55 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000001000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state56 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000010000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state57 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000100000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state58 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000001000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state59 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000010000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state60 : STD_LOGIC_VECTOR (69 downto 0) := "0000000000100000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state61 : STD_LOGIC_VECTOR (69 downto 0) := "0000000001000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state62 : STD_LOGIC_VECTOR (69 downto 0) := "0000000010000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state63 : STD_LOGIC_VECTOR (69 downto 0) := "0000000100000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state64 : STD_LOGIC_VECTOR (69 downto 0) := "0000001000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state65 : STD_LOGIC_VECTOR (69 downto 0) := "0000010000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state66 : STD_LOGIC_VECTOR (69 downto 0) := "0000100000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state67 : STD_LOGIC_VECTOR (69 downto 0) := "0001000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state68 : STD_LOGIC_VECTOR (69 downto 0) := "0010000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state69 : STD_LOGIC_VECTOR (69 downto 0) := "0100000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_ST_fsm_state70 : STD_LOGIC_VECTOR (69 downto 0) := "1000000000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_2B : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000101011";
    constant ap_const_lv32_30 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000110000";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_2C : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000101100";
    constant ap_const_lv32_31 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000110001";
    constant ap_const_lv32_45 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000001000101";
    constant ap_const_lv64_0 : STD_LOGIC_VECTOR (63 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (69 downto 0) := "0000000000000000000000000000000000000000000000000000000000000000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal grp_fu_128_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_reg_175 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal grp_fu_134_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_s_reg_180 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_140_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal x_assign_reg_185 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal grp_fu_143_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal x_assign_1_reg_190 : STD_LOGIC_VECTOR (63 downto 0);
    signal grp_pow_generic_double_s_fu_70_ap_return : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_i_reg_195 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state44 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state44 : signal is "none";
    signal grp_pow_generic_double_s_fu_99_ap_return : STD_LOGIC_VECTOR (63 downto 0);
    signal tmp_i1_reg_200 : STD_LOGIC_VECTOR (63 downto 0);
    signal grp_fu_146_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal x_assign_2_reg_205 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state49 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state49 : signal is "none";
    signal grp_pow_generic_double_s_fu_70_ap_start : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_70_ap_done : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_70_ap_idle : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_70_ap_ready : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_99_ap_start : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_99_ap_done : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_99_ap_idle : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_99_ap_ready : STD_LOGIC;
    signal grp_pow_generic_double_s_fu_70_ap_start_reg : STD_LOGIC := '0';
    signal ap_NS_fsm : STD_LOGIC_VECTOR (69 downto 0);
    signal ap_NS_fsm_state7 : STD_LOGIC;
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal grp_pow_generic_double_s_fu_99_ap_start_reg : STD_LOGIC := '0';
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal ap_CS_fsm_state45 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state45 : signal is "none";
    signal ap_CS_fsm_state50 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state50 : signal is "none";
    signal grp_fu_150_p2 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state70 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state70 : signal is "none";

    component pow_generic_double_s IS
    port (
        ap_clk : IN STD_LOGIC;
        ap_rst : IN STD_LOGIC;
        ap_start : IN STD_LOGIC;
        ap_done : OUT STD_LOGIC;
        ap_idle : OUT STD_LOGIC;
        ap_ready : OUT STD_LOGIC;
        base_r : IN STD_LOGIC_VECTOR (63 downto 0);
        ap_return : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;


    component distFloat_fsub_32yd2 IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component distFloat_fpext_3zec IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;


    component distFloat_dadd_64Aem IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (63 downto 0);
        din1 : IN STD_LOGIC_VECTOR (63 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;


    component distFloat_dsqrt_6Bew IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (63 downto 0);
        din1 : IN STD_LOGIC_VECTOR (63 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (63 downto 0) );
    end component;



begin
    grp_pow_generic_double_s_fu_70 : component pow_generic_double_s
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_pow_generic_double_s_fu_70_ap_start,
        ap_done => grp_pow_generic_double_s_fu_70_ap_done,
        ap_idle => grp_pow_generic_double_s_fu_70_ap_idle,
        ap_ready => grp_pow_generic_double_s_fu_70_ap_ready,
        base_r => x_assign_reg_185,
        ap_return => grp_pow_generic_double_s_fu_70_ap_return);

    grp_pow_generic_double_s_fu_99 : component pow_generic_double_s
    port map (
        ap_clk => ap_clk,
        ap_rst => ap_rst,
        ap_start => grp_pow_generic_double_s_fu_99_ap_start,
        ap_done => grp_pow_generic_double_s_fu_99_ap_done,
        ap_idle => grp_pow_generic_double_s_fu_99_ap_idle,
        ap_ready => grp_pow_generic_double_s_fu_99_ap_ready,
        base_r => x_assign_1_reg_190,
        ap_return => grp_pow_generic_double_s_fu_99_ap_return);

    distFloat_fsub_32yd2_U36 : component distFloat_fsub_32yd2
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => x2,
        din1 => x1,
        ce => ap_const_logic_1,
        dout => grp_fu_128_p2);

    distFloat_fsub_32yd2_U37 : component distFloat_fsub_32yd2
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => y2,
        din1 => y1,
        ce => ap_const_logic_1,
        dout => grp_fu_134_p2);

    distFloat_fpext_3zec_U38 : component distFloat_fpext_3zec
    generic map (
        ID => 1,
        NUM_STAGE => 2,
        din0_WIDTH => 32,
        dout_WIDTH => 64)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => tmp_reg_175,
        ce => ap_const_logic_1,
        dout => grp_fu_140_p1);

    distFloat_fpext_3zec_U39 : component distFloat_fpext_3zec
    generic map (
        ID => 1,
        NUM_STAGE => 2,
        din0_WIDTH => 32,
        dout_WIDTH => 64)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => tmp_s_reg_180,
        ce => ap_const_logic_1,
        dout => grp_fu_143_p1);

    distFloat_dadd_64Aem_U40 : component distFloat_dadd_64Aem
    generic map (
        ID => 1,
        NUM_STAGE => 5,
        din0_WIDTH => 64,
        din1_WIDTH => 64,
        dout_WIDTH => 64)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => tmp_i_reg_195,
        din1 => tmp_i1_reg_200,
        ce => ap_const_logic_1,
        dout => grp_fu_146_p2);

    distFloat_dsqrt_6Bew_U41 : component distFloat_dsqrt_6Bew
    generic map (
        ID => 1,
        NUM_STAGE => 21,
        din0_WIDTH => 64,
        din1_WIDTH => 64,
        dout_WIDTH => 64)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => ap_const_lv64_0,
        din1 => x_assign_2_reg_205,
        ce => ap_const_logic_1,
        dout => grp_fu_150_p2);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    grp_pow_generic_double_s_fu_70_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_pow_generic_double_s_fu_70_ap_start_reg <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_NS_fsm_state7) and (ap_const_logic_1 = ap_CS_fsm_state6))) then 
                    grp_pow_generic_double_s_fu_70_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_pow_generic_double_s_fu_70_ap_ready = ap_const_logic_1)) then 
                    grp_pow_generic_double_s_fu_70_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;


    grp_pow_generic_double_s_fu_99_ap_start_reg_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                grp_pow_generic_double_s_fu_99_ap_start_reg <= ap_const_logic_0;
            else
                if (((ap_const_logic_1 = ap_NS_fsm_state7) and (ap_const_logic_1 = ap_CS_fsm_state6))) then 
                    grp_pow_generic_double_s_fu_99_ap_start_reg <= ap_const_logic_1;
                elsif ((grp_pow_generic_double_s_fu_99_ap_ready = ap_const_logic_1)) then 
                    grp_pow_generic_double_s_fu_99_ap_start_reg <= ap_const_logic_0;
                end if; 
            end if;
        end if;
    end process;

    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state44)) then
                tmp_i1_reg_200 <= grp_pow_generic_double_s_fu_99_ap_return;
                tmp_i_reg_195 <= grp_pow_generic_double_s_fu_70_ap_return;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                tmp_reg_175 <= grp_fu_128_p2;
                tmp_s_reg_180 <= grp_fu_134_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then
                x_assign_1_reg_190 <= grp_fu_143_p1;
                x_assign_reg_185 <= grp_fu_140_p1;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state49)) then
                x_assign_2_reg_205 <= grp_fu_146_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                ap_NS_fsm <= ap_ST_fsm_state3;
            when ap_ST_fsm_state3 => 
                ap_NS_fsm <= ap_ST_fsm_state4;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state10;
            when ap_ST_fsm_state10 => 
                ap_NS_fsm <= ap_ST_fsm_state11;
            when ap_ST_fsm_state11 => 
                ap_NS_fsm <= ap_ST_fsm_state12;
            when ap_ST_fsm_state12 => 
                ap_NS_fsm <= ap_ST_fsm_state13;
            when ap_ST_fsm_state13 => 
                ap_NS_fsm <= ap_ST_fsm_state14;
            when ap_ST_fsm_state14 => 
                ap_NS_fsm <= ap_ST_fsm_state15;
            when ap_ST_fsm_state15 => 
                ap_NS_fsm <= ap_ST_fsm_state16;
            when ap_ST_fsm_state16 => 
                ap_NS_fsm <= ap_ST_fsm_state17;
            when ap_ST_fsm_state17 => 
                ap_NS_fsm <= ap_ST_fsm_state18;
            when ap_ST_fsm_state18 => 
                ap_NS_fsm <= ap_ST_fsm_state19;
            when ap_ST_fsm_state19 => 
                ap_NS_fsm <= ap_ST_fsm_state20;
            when ap_ST_fsm_state20 => 
                ap_NS_fsm <= ap_ST_fsm_state21;
            when ap_ST_fsm_state21 => 
                ap_NS_fsm <= ap_ST_fsm_state22;
            when ap_ST_fsm_state22 => 
                ap_NS_fsm <= ap_ST_fsm_state23;
            when ap_ST_fsm_state23 => 
                ap_NS_fsm <= ap_ST_fsm_state24;
            when ap_ST_fsm_state24 => 
                ap_NS_fsm <= ap_ST_fsm_state25;
            when ap_ST_fsm_state25 => 
                ap_NS_fsm <= ap_ST_fsm_state26;
            when ap_ST_fsm_state26 => 
                ap_NS_fsm <= ap_ST_fsm_state27;
            when ap_ST_fsm_state27 => 
                ap_NS_fsm <= ap_ST_fsm_state28;
            when ap_ST_fsm_state28 => 
                ap_NS_fsm <= ap_ST_fsm_state29;
            when ap_ST_fsm_state29 => 
                ap_NS_fsm <= ap_ST_fsm_state30;
            when ap_ST_fsm_state30 => 
                ap_NS_fsm <= ap_ST_fsm_state31;
            when ap_ST_fsm_state31 => 
                ap_NS_fsm <= ap_ST_fsm_state32;
            when ap_ST_fsm_state32 => 
                ap_NS_fsm <= ap_ST_fsm_state33;
            when ap_ST_fsm_state33 => 
                ap_NS_fsm <= ap_ST_fsm_state34;
            when ap_ST_fsm_state34 => 
                ap_NS_fsm <= ap_ST_fsm_state35;
            when ap_ST_fsm_state35 => 
                ap_NS_fsm <= ap_ST_fsm_state36;
            when ap_ST_fsm_state36 => 
                ap_NS_fsm <= ap_ST_fsm_state37;
            when ap_ST_fsm_state37 => 
                ap_NS_fsm <= ap_ST_fsm_state38;
            when ap_ST_fsm_state38 => 
                ap_NS_fsm <= ap_ST_fsm_state39;
            when ap_ST_fsm_state39 => 
                ap_NS_fsm <= ap_ST_fsm_state40;
            when ap_ST_fsm_state40 => 
                ap_NS_fsm <= ap_ST_fsm_state41;
            when ap_ST_fsm_state41 => 
                ap_NS_fsm <= ap_ST_fsm_state42;
            when ap_ST_fsm_state42 => 
                ap_NS_fsm <= ap_ST_fsm_state43;
            when ap_ST_fsm_state43 => 
                ap_NS_fsm <= ap_ST_fsm_state44;
            when ap_ST_fsm_state44 => 
                ap_NS_fsm <= ap_ST_fsm_state45;
            when ap_ST_fsm_state45 => 
                ap_NS_fsm <= ap_ST_fsm_state46;
            when ap_ST_fsm_state46 => 
                ap_NS_fsm <= ap_ST_fsm_state47;
            when ap_ST_fsm_state47 => 
                ap_NS_fsm <= ap_ST_fsm_state48;
            when ap_ST_fsm_state48 => 
                ap_NS_fsm <= ap_ST_fsm_state49;
            when ap_ST_fsm_state49 => 
                ap_NS_fsm <= ap_ST_fsm_state50;
            when ap_ST_fsm_state50 => 
                ap_NS_fsm <= ap_ST_fsm_state51;
            when ap_ST_fsm_state51 => 
                ap_NS_fsm <= ap_ST_fsm_state52;
            when ap_ST_fsm_state52 => 
                ap_NS_fsm <= ap_ST_fsm_state53;
            when ap_ST_fsm_state53 => 
                ap_NS_fsm <= ap_ST_fsm_state54;
            when ap_ST_fsm_state54 => 
                ap_NS_fsm <= ap_ST_fsm_state55;
            when ap_ST_fsm_state55 => 
                ap_NS_fsm <= ap_ST_fsm_state56;
            when ap_ST_fsm_state56 => 
                ap_NS_fsm <= ap_ST_fsm_state57;
            when ap_ST_fsm_state57 => 
                ap_NS_fsm <= ap_ST_fsm_state58;
            when ap_ST_fsm_state58 => 
                ap_NS_fsm <= ap_ST_fsm_state59;
            when ap_ST_fsm_state59 => 
                ap_NS_fsm <= ap_ST_fsm_state60;
            when ap_ST_fsm_state60 => 
                ap_NS_fsm <= ap_ST_fsm_state61;
            when ap_ST_fsm_state61 => 
                ap_NS_fsm <= ap_ST_fsm_state62;
            when ap_ST_fsm_state62 => 
                ap_NS_fsm <= ap_ST_fsm_state63;
            when ap_ST_fsm_state63 => 
                ap_NS_fsm <= ap_ST_fsm_state64;
            when ap_ST_fsm_state64 => 
                ap_NS_fsm <= ap_ST_fsm_state65;
            when ap_ST_fsm_state65 => 
                ap_NS_fsm <= ap_ST_fsm_state66;
            when ap_ST_fsm_state66 => 
                ap_NS_fsm <= ap_ST_fsm_state67;
            when ap_ST_fsm_state67 => 
                ap_NS_fsm <= ap_ST_fsm_state68;
            when ap_ST_fsm_state68 => 
                ap_NS_fsm <= ap_ST_fsm_state69;
            when ap_ST_fsm_state69 => 
                ap_NS_fsm <= ap_ST_fsm_state70;
            when ap_ST_fsm_state70 => 
                ap_NS_fsm <= ap_ST_fsm_state1;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end case;
    end process;
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state44 <= ap_CS_fsm(43);
    ap_CS_fsm_state45 <= ap_CS_fsm(44);
    ap_CS_fsm_state49 <= ap_CS_fsm(48);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state50 <= ap_CS_fsm(49);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);
    ap_CS_fsm_state70 <= ap_CS_fsm(69);
    ap_NS_fsm_state7 <= ap_NS_fsm(6);

    ap_done_assign_proc : process(ap_CS_fsm_state70)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state70)) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state70)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state70)) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    ap_return <= grp_fu_150_p2;
    grp_pow_generic_double_s_fu_70_ap_start <= grp_pow_generic_double_s_fu_70_ap_start_reg;
    grp_pow_generic_double_s_fu_99_ap_start <= grp_pow_generic_double_s_fu_99_ap_start_reg;
end behav;
