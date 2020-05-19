// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2019.2
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "distFix.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic distFix::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic distFix::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<16> distFix::ap_ST_fsm_state1 = "1";
const sc_lv<16> distFix::ap_ST_fsm_state2 = "10";
const sc_lv<16> distFix::ap_ST_fsm_state3 = "100";
const sc_lv<16> distFix::ap_ST_fsm_state4 = "1000";
const sc_lv<16> distFix::ap_ST_fsm_state5 = "10000";
const sc_lv<16> distFix::ap_ST_fsm_state6 = "100000";
const sc_lv<16> distFix::ap_ST_fsm_state7 = "1000000";
const sc_lv<16> distFix::ap_ST_fsm_state8 = "10000000";
const sc_lv<16> distFix::ap_ST_fsm_state9 = "100000000";
const sc_lv<16> distFix::ap_ST_fsm_state10 = "1000000000";
const sc_lv<16> distFix::ap_ST_fsm_state11 = "10000000000";
const sc_lv<16> distFix::ap_ST_fsm_state12 = "100000000000";
const sc_lv<16> distFix::ap_ST_fsm_state13 = "1000000000000";
const sc_lv<16> distFix::ap_ST_fsm_state14 = "10000000000000";
const sc_lv<16> distFix::ap_ST_fsm_state15 = "100000000000000";
const sc_lv<16> distFix::ap_ST_fsm_state16 = "1000000000000000";
const sc_lv<32> distFix::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> distFix::ap_const_lv32_1 = "1";
const sc_lv<32> distFix::ap_const_lv32_2 = "10";
const sc_lv<32> distFix::ap_const_lv32_B = "1011";
const sc_lv<32> distFix::ap_const_lv32_1A = "11010";
const sc_lv<32> distFix::ap_const_lv32_F = "1111";
const bool distFix::ap_const_boolean_1 = true;

distFix::distFix(sc_module_name name) : sc_module(name), mVcdFile(0) {
    grp_sqrt_fixed_35_13_s_fu_50 = new sqrt_fixed_35_13_s("grp_sqrt_fixed_35_13_s_fu_50");
    grp_sqrt_fixed_35_13_s_fu_50->ap_clk(ap_clk);
    grp_sqrt_fixed_35_13_s_fu_50->ap_rst(ap_rst);
    grp_sqrt_fixed_35_13_s_fu_50->x_V(ret_V_2_reg_119);
    grp_sqrt_fixed_35_13_s_fu_50->ap_return(grp_sqrt_fixed_35_13_s_fu_50_ap_return);
    distFix_mul_mul_1bkb_U2 = new distFix_mul_mul_1bkb<1,1,17,17,34>("distFix_mul_mul_1bkb_U2");
    distFix_mul_mul_1bkb_U2->din0(r_V_4_fu_101_p0);
    distFix_mul_mul_1bkb_U2->din1(r_V_4_fu_101_p1);
    distFix_mul_mul_1bkb_U2->dout(r_V_4_fu_101_p2);
    distFix_mac_muladcud_U3 = new distFix_mac_muladcud<1,1,17,17,34,34>("distFix_mac_muladcud_U3");
    distFix_mac_muladcud_U3->din0(grp_fu_107_p0);
    distFix_mac_muladcud_U3->din1(grp_fu_107_p1);
    distFix_mac_muladcud_U3->din2(r_V_4_reg_114);
    distFix_mac_muladcud_U3->dout(grp_fu_107_p3);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state16);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_ap_return);
    sensitive << ( grp_sqrt_fixed_35_13_s_fu_50_ap_return );
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_grp_fu_107_p0);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( r_V_2_fu_87_p1 );

    SC_METHOD(thread_grp_fu_107_p1);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( r_V_2_fu_87_p1 );

    SC_METHOD(thread_lhs_V_1_fu_73_p1);
    sensitive << ( y2_V );

    SC_METHOD(thread_lhs_V_fu_55_p1);
    sensitive << ( x2_V );

    SC_METHOD(thread_r_V_2_fu_87_p1);
    sensitive << ( ret_V_1_fu_81_p2 );

    SC_METHOD(thread_r_V_4_fu_101_p0);
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( r_V_fu_69_p1 );

    SC_METHOD(thread_r_V_4_fu_101_p1);
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( r_V_fu_69_p1 );

    SC_METHOD(thread_r_V_fu_69_p1);
    sensitive << ( ret_V_fu_63_p2 );

    SC_METHOD(thread_ret_V_1_fu_81_p2);
    sensitive << ( lhs_V_1_fu_73_p1 );
    sensitive << ( rhs_V_1_fu_77_p1 );

    SC_METHOD(thread_ret_V_fu_63_p2);
    sensitive << ( lhs_V_fu_55_p1 );
    sensitive << ( rhs_V_fu_59_p1 );

    SC_METHOD(thread_rhs_V_1_fu_77_p1);
    sensitive << ( y1_V );

    SC_METHOD(thread_rhs_V_fu_59_p1);
    sensitive << ( x1_V );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );

    SC_THREAD(thread_hdltv_gen);
    sensitive << ( ap_clk.pos() );

    ap_CS_fsm = "0000000000000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "distFix_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, x1_V, "(port)x1_V");
    sc_trace(mVcdFile, y1_V, "(port)y1_V");
    sc_trace(mVcdFile, x2_V, "(port)x2_V");
    sc_trace(mVcdFile, y2_V, "(port)y2_V");
    sc_trace(mVcdFile, ap_return, "(port)ap_return");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, r_V_4_fu_101_p2, "r_V_4_fu_101_p2");
    sc_trace(mVcdFile, r_V_4_reg_114, "r_V_4_reg_114");
    sc_trace(mVcdFile, grp_fu_107_p3, "grp_fu_107_p3");
    sc_trace(mVcdFile, ret_V_2_reg_119, "ret_V_2_reg_119");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, grp_sqrt_fixed_35_13_s_fu_50_ap_return, "grp_sqrt_fixed_35_13_s_fu_50_ap_return");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, lhs_V_fu_55_p1, "lhs_V_fu_55_p1");
    sc_trace(mVcdFile, rhs_V_fu_59_p1, "rhs_V_fu_59_p1");
    sc_trace(mVcdFile, ret_V_fu_63_p2, "ret_V_fu_63_p2");
    sc_trace(mVcdFile, lhs_V_1_fu_73_p1, "lhs_V_1_fu_73_p1");
    sc_trace(mVcdFile, rhs_V_1_fu_77_p1, "rhs_V_1_fu_77_p1");
    sc_trace(mVcdFile, ret_V_1_fu_81_p2, "ret_V_1_fu_81_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state16, "ap_CS_fsm_state16");
    sc_trace(mVcdFile, r_V_4_fu_101_p0, "r_V_4_fu_101_p0");
    sc_trace(mVcdFile, r_V_fu_69_p1, "r_V_fu_69_p1");
    sc_trace(mVcdFile, r_V_4_fu_101_p1, "r_V_4_fu_101_p1");
    sc_trace(mVcdFile, grp_fu_107_p0, "grp_fu_107_p0");
    sc_trace(mVcdFile, r_V_2_fu_87_p1, "r_V_2_fu_87_p1");
    sc_trace(mVcdFile, grp_fu_107_p1, "grp_fu_107_p1");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
    mHdltvinHandle.open("distFix.hdltvin.dat");
    mHdltvoutHandle.open("distFix.hdltvout.dat");
}

distFix::~distFix() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    mHdltvinHandle << "] " << endl;
    mHdltvoutHandle << "] " << endl;
    mHdltvinHandle.close();
    mHdltvoutHandle.close();
    delete grp_sqrt_fixed_35_13_s_fu_50;
    delete distFix_mul_mul_1bkb_U2;
    delete distFix_mac_muladcud_U3;
}

void distFix::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        r_V_4_reg_114 = r_V_4_fu_101_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        ret_V_2_reg_119 = grp_fu_107_p3.read();
    }
}

void distFix::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void distFix::thread_ap_CS_fsm_state16() {
    ap_CS_fsm_state16 = ap_CS_fsm.read()[15];
}

void distFix::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void distFix::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void distFix::thread_ap_done() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void distFix::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void distFix::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void distFix::thread_ap_return() {
    ap_return = grp_sqrt_fixed_35_13_s_fu_50_ap_return.read().range(26, 11);
}

void distFix::thread_grp_fu_107_p0() {
    grp_fu_107_p0 =  (sc_lv<17>) (r_V_2_fu_87_p1.read());
}

void distFix::thread_grp_fu_107_p1() {
    grp_fu_107_p1 =  (sc_lv<17>) (r_V_2_fu_87_p1.read());
}

void distFix::thread_lhs_V_1_fu_73_p1() {
    lhs_V_1_fu_73_p1 = esl_sext<17,16>(y2_V.read());
}

void distFix::thread_lhs_V_fu_55_p1() {
    lhs_V_fu_55_p1 = esl_sext<17,16>(x2_V.read());
}

void distFix::thread_r_V_2_fu_87_p1() {
    r_V_2_fu_87_p1 = esl_sext<34,17>(ret_V_1_fu_81_p2.read());
}

void distFix::thread_r_V_4_fu_101_p0() {
    r_V_4_fu_101_p0 =  (sc_lv<17>) (r_V_fu_69_p1.read());
}

void distFix::thread_r_V_4_fu_101_p1() {
    r_V_4_fu_101_p1 =  (sc_lv<17>) (r_V_fu_69_p1.read());
}

void distFix::thread_r_V_fu_69_p1() {
    r_V_fu_69_p1 = esl_sext<34,17>(ret_V_fu_63_p2.read());
}

void distFix::thread_ret_V_1_fu_81_p2() {
    ret_V_1_fu_81_p2 = (!lhs_V_1_fu_73_p1.read().is_01() || !rhs_V_1_fu_77_p1.read().is_01())? sc_lv<17>(): (sc_bigint<17>(lhs_V_1_fu_73_p1.read()) - sc_bigint<17>(rhs_V_1_fu_77_p1.read()));
}

void distFix::thread_ret_V_fu_63_p2() {
    ret_V_fu_63_p2 = (!lhs_V_fu_55_p1.read().is_01() || !rhs_V_fu_59_p1.read().is_01())? sc_lv<17>(): (sc_bigint<17>(lhs_V_fu_55_p1.read()) - sc_bigint<17>(rhs_V_fu_59_p1.read()));
}

void distFix::thread_rhs_V_1_fu_77_p1() {
    rhs_V_1_fu_77_p1 = esl_sext<17,16>(y1_V.read());
}

void distFix::thread_rhs_V_fu_59_p1() {
    rhs_V_fu_59_p1 = esl_sext<17,16>(x1_V.read());
}

void distFix::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            ap_NS_fsm = ap_ST_fsm_state3;
            break;
        case 4 : 
            ap_NS_fsm = ap_ST_fsm_state4;
            break;
        case 8 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        case 16 : 
            ap_NS_fsm = ap_ST_fsm_state6;
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_state9;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state10;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state11;
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_fsm_state12;
            break;
        case 2048 : 
            ap_NS_fsm = ap_ST_fsm_state13;
            break;
        case 4096 : 
            ap_NS_fsm = ap_ST_fsm_state14;
            break;
        case 8192 : 
            ap_NS_fsm = ap_ST_fsm_state15;
            break;
        case 16384 : 
            ap_NS_fsm = ap_ST_fsm_state16;
            break;
        case 32768 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm = "XXXXXXXXXXXXXXXX";
            break;
    }
}

void distFix::thread_hdltv_gen() {
    const char* dump_tv = std::getenv("AP_WRITE_TV");
    if (!(dump_tv && string(dump_tv) == "on")) return;

    wait();

    mHdltvinHandle << "[ " << endl;
    mHdltvoutHandle << "[ " << endl;
    int ap_cycleNo = 0;
    while (1) {
        wait();
        const char* mComma = ap_cycleNo == 0 ? " " : ", " ;
        mHdltvinHandle << mComma << "{"  <<  " \"ap_rst\" :  \"" << ap_rst.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"ap_start\" :  \"" << ap_start.read() << "\" ";
        mHdltvoutHandle << mComma << "{"  <<  " \"ap_done\" :  \"" << ap_done.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_idle\" :  \"" << ap_idle.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_ready\" :  \"" << ap_ready.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"x1_V\" :  \"" << x1_V.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"y1_V\" :  \"" << y1_V.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"x2_V\" :  \"" << x2_V.read() << "\" ";
        mHdltvinHandle << " , " <<  " \"y2_V\" :  \"" << y2_V.read() << "\" ";
        mHdltvoutHandle << " , " <<  " \"ap_return\" :  \"" << ap_return.read() << "\" ";
        mHdltvinHandle << "}" << std::endl;
        mHdltvoutHandle << "}" << std::endl;
        ap_cycleNo++;
    }
}

}

