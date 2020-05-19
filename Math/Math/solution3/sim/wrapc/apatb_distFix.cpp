// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

#define AP_INT_MAX_W 32678

#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


// [dump_struct_tree [build_nameSpaceTree] dumpedStructList] ---------->


// [dump_enumeration [get_enumeration_list]] ---------->


// wrapc file define: "x1_V"
#define AUTOTB_TVIN_x1_V  "../tv/cdatafile/c.distFix.autotvin_x1_V.dat"
// wrapc file define: "y1_V"
#define AUTOTB_TVIN_y1_V  "../tv/cdatafile/c.distFix.autotvin_y1_V.dat"
// wrapc file define: "x2_V"
#define AUTOTB_TVIN_x2_V  "../tv/cdatafile/c.distFix.autotvin_x2_V.dat"
// wrapc file define: "y2_V"
#define AUTOTB_TVIN_y2_V  "../tv/cdatafile/c.distFix.autotvin_y2_V.dat"
// wrapc file define: "ap_return"
#define AUTOTB_TVOUT_ap_return  "../tv/cdatafile/c.distFix.autotvout_ap_return.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "ap_return"
#define AUTOTB_TVOUT_PC_ap_return  "../tv/rtldatafile/rtl.distFix.autotvout_ap_return.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			x1_V_depth = 0;
			y1_V_depth = 0;
			x2_V_depth = 0;
			y2_V_depth = 0;
			ap_return_depth = 0;
			trans_num =0;
		}

		~INTER_TCL_FILE() {
			mFile.open(mName);
			if (!mFile.good()) {
				cout << "Failed to open file ref.tcl" << endl;
				exit (1);
			}
			string total_list = get_depth_list();
			mFile << "set depth_list {\n";
			mFile << total_list;
			mFile << "}\n";
			mFile << "set trans_num "<<trans_num<<endl;
			mFile.close();
		}

		string get_depth_list () {
			stringstream total_list;
			total_list << "{x1_V " << x1_V_depth << "}\n";
			total_list << "{y1_V " << y1_V_depth << "}\n";
			total_list << "{x2_V " << x2_V_depth << "}\n";
			total_list << "{y2_V " << y2_V_depth << "}\n";
			total_list << "{ap_return " << ap_return_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int x1_V_depth;
		int y1_V_depth;
		int x2_V_depth;
		int y2_V_depth;
		int ap_return_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> distFix (
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> x1,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> y1,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> x2,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> y2);

ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> AESL_WRAP_distFix (
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> x1,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> y1,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> x2,
ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> y2)
{
	refine_signal_handler();
	fstream wrapc_switch_file_token;
	wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
	int AESL_i;
	if (wrapc_switch_file_token.good())
	{
		CodeState = ENTER_WRAPC_PC;
		static unsigned AESL_transaction_pc = 0;
		string AESL_token;
		string AESL_num;
		static AESL_FILE_HANDLER aesl_fh;

		ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> AESL_return;

		// output port post check: "ap_return"
		aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // data

			sc_bv<16> ap_return_pc_buffer;
			int i = 0;

			while (AESL_token != "[[/transaction]]")
			{
				bool no_x = false;
				bool err = false;

				// search and replace 'X' with "0" from the 1st char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('X');
					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'ap_return', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				no_x = false;

				// search and replace 'x' with "0" from the 3rd char of token
				while (!no_x)
				{
					size_t x_found = AESL_token.find('x', 2);

					if (x_found != string::npos)
					{
						if (!err)
						{
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'ap_return', possible cause: There are uninitialized variables in the C design." << endl;
							err = true;
						}
						AESL_token.replace(x_found, 1, "0");
					}
					else
					{
						no_x = true;
					}
				}

				// push token into output port buffer
				if (AESL_token != "")
				{
					ap_return_pc_buffer = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_ap_return, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_ap_return))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: ap_return
				{
					// bitslice(15, 0)
					// {
						// celement: agg.result.V(15, 0)
						// {
							sc_lv<16> agg_result_V_lv0_0_0_0;
						// }
					// }

					// bitslice(15, 0)
					{
						// celement: agg.result.V(15, 0)
						{
							// carray: (0) => (0) @ (0)
							{
								if (&(AESL_return) != NULL) // check the null address if the c port is array or others
								{
									agg_result_V_lv0_0_0_0.range(15, 0) = sc_bv<16>(ap_return_pc_buffer.range(15, 0));
								}
							}
						}
					}

					// bitslice(15, 0)
					{
						// celement: agg.result.V(15, 0)
						{
							// carray: (0) => (0) @ (0)
							{
								// sub                    : 
								// ori_name               : AESL_return
								// sub_1st_elem           : 
								// ori_name_1st_elem      : AESL_return
								// output_left_conversion : (AESL_return).range()
								// output_type_conversion : (agg_result_V_lv0_0_0_0).to_string(SC_BIN).c_str()
								if (&(AESL_return) != NULL) // check the null address if the c port is array or others
								{
									(AESL_return).range() = (agg_result_V_lv0_0_0_0).to_string(SC_BIN).c_str();
								}
							}
						}
					}
				}
			}
		}

		AESL_transaction_pc++;

		return AESL_return;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "x1_V"
		char* tvin_x1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_x1_V);

		// "y1_V"
		char* tvin_y1_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_y1_V);

		// "x2_V"
		char* tvin_x2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_x2_V);

		// "y2_V"
		char* tvin_y2_V = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_y2_V);

		// "ap_return"
		char* tvout_ap_return = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_ap_return);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_x1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_x1_V, tvin_x1_V);

		sc_bv<16> x1_V_tvin_wrapc_buffer;

		// RTL Name: x1_V
		{
			// bitslice(15, 0)
			{
				// celement: x1.V(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : x1
						// sub_1st_elem          : 
						// ori_name_1st_elem     : x1
						// regulate_c_name       : x1_V
						// input_type_conversion : (x1).range().to_string(SC_BIN).c_str()
						if (&(x1) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> x1_V_tmp_mem;
							x1_V_tmp_mem = (x1).range().to_string(SC_BIN).c_str();
							x1_V_tvin_wrapc_buffer.range(15, 0) = x1_V_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_x1_V, "%s\n", (x1_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_x1_V, tvin_x1_V);
		}

		tcl_file.set_num(1, &tcl_file.x1_V_depth);
		sprintf(tvin_x1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_x1_V, tvin_x1_V);

		// [[transaction]]
		sprintf(tvin_y1_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_y1_V, tvin_y1_V);

		sc_bv<16> y1_V_tvin_wrapc_buffer;

		// RTL Name: y1_V
		{
			// bitslice(15, 0)
			{
				// celement: y1.V(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : y1
						// sub_1st_elem          : 
						// ori_name_1st_elem     : y1
						// regulate_c_name       : y1_V
						// input_type_conversion : (y1).range().to_string(SC_BIN).c_str()
						if (&(y1) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> y1_V_tmp_mem;
							y1_V_tmp_mem = (y1).range().to_string(SC_BIN).c_str();
							y1_V_tvin_wrapc_buffer.range(15, 0) = y1_V_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_y1_V, "%s\n", (y1_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_y1_V, tvin_y1_V);
		}

		tcl_file.set_num(1, &tcl_file.y1_V_depth);
		sprintf(tvin_y1_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_y1_V, tvin_y1_V);

		// [[transaction]]
		sprintf(tvin_x2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_x2_V, tvin_x2_V);

		sc_bv<16> x2_V_tvin_wrapc_buffer;

		// RTL Name: x2_V
		{
			// bitslice(15, 0)
			{
				// celement: x2.V(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : x2
						// sub_1st_elem          : 
						// ori_name_1st_elem     : x2
						// regulate_c_name       : x2_V
						// input_type_conversion : (x2).range().to_string(SC_BIN).c_str()
						if (&(x2) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> x2_V_tmp_mem;
							x2_V_tmp_mem = (x2).range().to_string(SC_BIN).c_str();
							x2_V_tvin_wrapc_buffer.range(15, 0) = x2_V_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_x2_V, "%s\n", (x2_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_x2_V, tvin_x2_V);
		}

		tcl_file.set_num(1, &tcl_file.x2_V_depth);
		sprintf(tvin_x2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_x2_V, tvin_x2_V);

		// [[transaction]]
		sprintf(tvin_y2_V, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_y2_V, tvin_y2_V);

		sc_bv<16> y2_V_tvin_wrapc_buffer;

		// RTL Name: y2_V
		{
			// bitslice(15, 0)
			{
				// celement: y2.V(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : y2
						// sub_1st_elem          : 
						// ori_name_1st_elem     : y2
						// regulate_c_name       : y2_V
						// input_type_conversion : (y2).range().to_string(SC_BIN).c_str()
						if (&(y2) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> y2_V_tmp_mem;
							y2_V_tmp_mem = (y2).range().to_string(SC_BIN).c_str();
							y2_V_tvin_wrapc_buffer.range(15, 0) = y2_V_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_y2_V, "%s\n", (y2_V_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_y2_V, tvin_y2_V);
		}

		tcl_file.set_num(1, &tcl_file.y2_V_depth);
		sprintf(tvin_y2_V, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_y2_V, tvin_y2_V);

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		ap_fixed<16, 5, (ap_q_mode) 5, (ap_o_mode)3, 0> AESL_return = distFix(x1, y1, x2, y2);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_ap_return, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);

		sc_bv<16> ap_return_tvout_wrapc_buffer;

		// RTL Name: ap_return
		{
			// bitslice(15, 0)
			{
				// celement: agg.result.V(15, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : AESL_return
						// sub_1st_elem          : 
						// ori_name_1st_elem     : AESL_return
						// regulate_c_name       : agg_result_V
						// input_type_conversion : (AESL_return).range().to_string(SC_BIN).c_str()
						if (&(AESL_return) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> agg_result_V_tmp_mem;
							agg_result_V_tmp_mem = (AESL_return).range().to_string(SC_BIN).c_str();
							ap_return_tvout_wrapc_buffer.range(15, 0) = agg_result_V_tmp_mem.range(15, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_ap_return, "%s\n", (ap_return_tvout_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);
		}

		tcl_file.set_num(1, &tcl_file.ap_return_depth);
		sprintf(tvout_ap_return, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_ap_return, tvout_ap_return);

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "x1_V"
		delete [] tvin_x1_V;
		// release memory allocation: "y1_V"
		delete [] tvin_y1_V;
		// release memory allocation: "x2_V"
		delete [] tvin_x2_V;
		// release memory allocation: "y2_V"
		delete [] tvin_y2_V;
		// release memory allocation: "ap_return"
		delete [] tvout_ap_return;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);

		return AESL_return;
	}
}

