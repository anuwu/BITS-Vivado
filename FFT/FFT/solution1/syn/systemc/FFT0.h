// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _FFT0_HH_
#define _FFT0_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "FFT_mul_mul_10s_1bkb.h"
#include "FFT_mul_mul_16s_9cud.h"
#include "FFT_mac_mulsub_9sdEe.h"
#include "FFT_mac_muladd_10eOg.h"
#include "FFT0_W_M_real_V.h"
#include "FFT0_W_M_imag_V.h"

namespace ap_rtl {

struct FFT0 : public sc_module {
    // Port declarations 24
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_in< sc_lv<6> > FFT_stage;
    sc_in< sc_lv<6> > pass_check;
    sc_in< sc_lv<4> > index_shift;
    sc_in< sc_lv<4> > pass_shift;
    sc_out< sc_lv<5> > data_IN_M_real_V_address0;
    sc_out< sc_logic > data_IN_M_real_V_ce0;
    sc_in< sc_lv<16> > data_IN_M_real_V_q0;
    sc_out< sc_lv<5> > data_IN_M_imag_V_address0;
    sc_out< sc_logic > data_IN_M_imag_V_ce0;
    sc_in< sc_lv<16> > data_IN_M_imag_V_q0;
    sc_out< sc_lv<5> > data_OUT_M_real_V_address0;
    sc_out< sc_logic > data_OUT_M_real_V_ce0;
    sc_out< sc_logic > data_OUT_M_real_V_we0;
    sc_out< sc_lv<16> > data_OUT_M_real_V_d0;
    sc_out< sc_lv<5> > data_OUT_M_imag_V_address0;
    sc_out< sc_logic > data_OUT_M_imag_V_ce0;
    sc_out< sc_logic > data_OUT_M_imag_V_we0;
    sc_out< sc_lv<16> > data_OUT_M_imag_V_d0;


    // Module declarations
    FFT0(sc_module_name name);
    SC_HAS_PROCESS(FFT0);

    ~FFT0();

    sc_trace_file* mVcdFile;

    FFT0_W_M_real_V* W_M_real_V_U;
    FFT0_W_M_imag_V* W_M_imag_V_U;
    FFT_mul_mul_10s_1bkb<1,1,10,16,24>* FFT_mul_mul_10s_1bkb_U1;
    FFT_mul_mul_16s_9cud<1,1,16,9,24>* FFT_mul_mul_16s_9cud_U2;
    FFT_mac_mulsub_9sdEe<1,1,9,16,24,24>* FFT_mac_mulsub_9sdEe_U3;
    FFT_mac_muladd_10eOg<1,1,10,16,24,24>* FFT_mac_muladd_10eOg_U4;
    sc_signal< sc_lv<5> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<4> > W_M_real_V_address0;
    sc_signal< sc_logic > W_M_real_V_ce0;
    sc_signal< sc_lv<10> > W_M_real_V_q0;
    sc_signal< sc_lv<4> > W_M_imag_V_address0;
    sc_signal< sc_logic > W_M_imag_V_ce0;
    sc_signal< sc_lv<9> > W_M_imag_V_q0;
    sc_signal< sc_lv<32> > pass_shift_cast_fu_219_p1;
    sc_signal< sc_lv<32> > pass_shift_cast_reg_440;
    sc_signal< sc_lv<32> > index_shift_cast_fu_223_p1;
    sc_signal< sc_lv<32> > index_shift_cast_reg_445;
    sc_signal< sc_lv<32> > FFT_stage_cast1_fu_227_p1;
    sc_signal< sc_lv<32> > FFT_stage_cast1_reg_450;
    sc_signal< sc_lv<32> > zext_ln33_fu_241_p1;
    sc_signal< sc_lv<32> > zext_ln33_reg_455;
    sc_signal< sc_lv<32> > zext_ln35_fu_255_p1;
    sc_signal< sc_lv<32> > zext_ln35_reg_460;
    sc_signal< sc_lv<5> > i_fu_265_p2;
    sc_signal< sc_lv<5> > i_reg_468;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<32> > Ulimit_fu_281_p2;
    sc_signal< sc_lv<32> > Ulimit_reg_473;
    sc_signal< sc_lv<1> > icmp_ln26_fu_259_p2;
    sc_signal< sc_lv<64> > sext_ln30_1_fu_298_p1;
    sc_signal< sc_lv<64> > sext_ln30_1_reg_488;
    sc_signal< sc_lv<32> > select_ln33_fu_334_p3;
    sc_signal< sc_lv<32> > select_ln33_reg_504;
    sc_signal< sc_lv<32> > butterfly_pass_2_fu_342_p3;
    sc_signal< sc_lv<32> > butterfly_pass_2_reg_509;
    sc_signal< sc_lv<16> > data_IN_M_imag_V_lo_reg_514;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<24> > sext_ln1118_fu_350_p1;
    sc_signal< sc_lv<24> > sext_ln1118_reg_519;
    sc_signal< sc_lv<24> > sext_ln1118_2_fu_358_p1;
    sc_signal< sc_lv<24> > sext_ln1118_2_reg_524;
    sc_signal< sc_lv<24> > mul_ln700_fu_414_p2;
    sc_signal< sc_lv<24> > mul_ln700_reg_529;
    sc_signal< sc_lv<24> > mul_ln1192_fu_420_p2;
    sc_signal< sc_lv<24> > mul_ln1192_reg_534;
    sc_signal< sc_lv<64> > sext_ln31_fu_362_p1;
    sc_signal< sc_lv<64> > sext_ln31_reg_539;
    sc_signal< sc_lv<16> > add_ln703_fu_402_p2;
    sc_signal< sc_lv<16> > add_ln703_reg_555;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<16> > add_ln703_1_fu_408_p2;
    sc_signal< sc_lv<16> > add_ln703_1_reg_560;
    sc_signal< sc_lv<32> > butterfly_span_0_reg_186;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<32> > butterfly_pass_0_reg_197;
    sc_signal< sc_lv<5> > i_0_reg_208;
    sc_signal< sc_lv<64> > sext_ln30_fu_292_p1;
    sc_signal< sc_lv<16> > sub_ln703_fu_388_p2;
    sc_signal< sc_lv<16> > sub_ln703_1_fu_395_p2;
    sc_signal< sc_lv<5> > trunc_ln33_fu_231_p1;
    sc_signal< sc_lv<5> > add_ln33_fu_235_p2;
    sc_signal< sc_lv<5> > trunc_ln35_fu_245_p1;
    sc_signal< sc_lv<5> > add_ln35_fu_249_p2;
    sc_signal< sc_lv<32> > shl_ln28_fu_276_p2;
    sc_signal< sc_lv<32> > index_fu_271_p2;
    sc_signal< sc_lv<32> > Llimit_fu_287_p2;
    sc_signal< sc_lv<1> > icmp_ln35_fu_315_p2;
    sc_signal< sc_lv<32> > butterfly_pass_fu_320_p2;
    sc_signal< sc_lv<1> > icmp_ln33_fu_304_p2;
    sc_signal< sc_lv<32> > butterfly_span_fu_309_p2;
    sc_signal< sc_lv<32> > butterfly_pass_1_fu_326_p3;
    sc_signal< sc_lv<24> > grp_fu_426_p3;
    sc_signal< sc_lv<24> > grp_fu_433_p3;
    sc_signal< sc_lv<16> > p_r_V_fu_370_p4;
    sc_signal< sc_lv<16> > p_Val2_5_fu_379_p4;
    sc_signal< sc_lv<16> > mul_ln700_fu_414_p1;
    sc_signal< sc_lv<24> > sext_ln1118_1_fu_354_p1;
    sc_signal< sc_lv<16> > mul_ln1192_fu_420_p0;
    sc_signal< sc_lv<9> > grp_fu_426_p0;
    sc_signal< sc_lv<16> > grp_fu_426_p1;
    sc_signal< sc_lv<24> > sext_ln1118_3_fu_367_p1;
    sc_signal< sc_lv<10> > grp_fu_433_p0;
    sc_signal< sc_lv<16> > grp_fu_433_p1;
    sc_signal< sc_lv<5> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<5> ap_ST_fsm_state1;
    static const sc_lv<5> ap_ST_fsm_state2;
    static const sc_lv<5> ap_ST_fsm_state3;
    static const sc_lv<5> ap_ST_fsm_state4;
    static const sc_lv<5> ap_ST_fsm_state5;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<5> ap_const_lv5_1F;
    static const sc_lv<5> ap_const_lv5_10;
    static const sc_lv<5> ap_const_lv5_1;
    static const sc_lv<32> ap_const_lv32_8;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<1> ap_const_lv1_1;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_FFT_stage_cast1_fu_227_p1();
    void thread_Llimit_fu_287_p2();
    void thread_Ulimit_fu_281_p2();
    void thread_W_M_imag_V_address0();
    void thread_W_M_imag_V_ce0();
    void thread_W_M_real_V_address0();
    void thread_W_M_real_V_ce0();
    void thread_add_ln33_fu_235_p2();
    void thread_add_ln35_fu_249_p2();
    void thread_add_ln703_1_fu_408_p2();
    void thread_add_ln703_fu_402_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_butterfly_pass_1_fu_326_p3();
    void thread_butterfly_pass_2_fu_342_p3();
    void thread_butterfly_pass_fu_320_p2();
    void thread_butterfly_span_fu_309_p2();
    void thread_data_IN_M_imag_V_address0();
    void thread_data_IN_M_imag_V_ce0();
    void thread_data_IN_M_real_V_address0();
    void thread_data_IN_M_real_V_ce0();
    void thread_data_OUT_M_imag_V_address0();
    void thread_data_OUT_M_imag_V_ce0();
    void thread_data_OUT_M_imag_V_d0();
    void thread_data_OUT_M_imag_V_we0();
    void thread_data_OUT_M_real_V_address0();
    void thread_data_OUT_M_real_V_ce0();
    void thread_data_OUT_M_real_V_d0();
    void thread_data_OUT_M_real_V_we0();
    void thread_grp_fu_426_p0();
    void thread_grp_fu_426_p1();
    void thread_grp_fu_433_p0();
    void thread_grp_fu_433_p1();
    void thread_i_fu_265_p2();
    void thread_icmp_ln26_fu_259_p2();
    void thread_icmp_ln33_fu_304_p2();
    void thread_icmp_ln35_fu_315_p2();
    void thread_index_fu_271_p2();
    void thread_index_shift_cast_fu_223_p1();
    void thread_mul_ln1192_fu_420_p0();
    void thread_mul_ln700_fu_414_p1();
    void thread_p_Val2_5_fu_379_p4();
    void thread_p_r_V_fu_370_p4();
    void thread_pass_shift_cast_fu_219_p1();
    void thread_select_ln33_fu_334_p3();
    void thread_sext_ln1118_1_fu_354_p1();
    void thread_sext_ln1118_2_fu_358_p1();
    void thread_sext_ln1118_3_fu_367_p1();
    void thread_sext_ln1118_fu_350_p1();
    void thread_sext_ln30_1_fu_298_p1();
    void thread_sext_ln30_fu_292_p1();
    void thread_sext_ln31_fu_362_p1();
    void thread_shl_ln28_fu_276_p2();
    void thread_sub_ln703_1_fu_395_p2();
    void thread_sub_ln703_fu_388_p2();
    void thread_trunc_ln33_fu_231_p1();
    void thread_trunc_ln35_fu_245_p1();
    void thread_zext_ln33_fu_241_p1();
    void thread_zext_ln35_fu_255_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif