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


// wrapc file define: "data_IN"
#define AUTOTB_TVIN_data_IN  "../tv/cdatafile/c.FFT.autotvin_data_IN.dat"
// wrapc file define: "data_OUT"
#define AUTOTB_TVOUT_data_OUT  "../tv/cdatafile/c.FFT.autotvout_data_OUT.dat"
#define AUTOTB_TVIN_data_OUT  "../tv/cdatafile/c.FFT.autotvin_data_OUT.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "data_OUT"
#define AUTOTB_TVOUT_PC_data_OUT  "../tv/rtldatafile/rtl.FFT.autotvout_data_OUT.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			data_IN_depth = 0;
			data_OUT_depth = 0;
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
			total_list << "{data_IN " << data_IN_depth << "}\n";
			total_list << "{data_OUT " << data_OUT_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int data_IN_depth;
		int data_OUT_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void FFT (
std::complex<ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> > data_IN[32],
std::complex<ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> > data_OUT[32]);

void AESL_WRAP_FFT (
std::complex<ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> > data_IN[32],
std::complex<ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> > data_OUT[32])
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


		// output port post check: "data_OUT"
		aesl_fh.read(AUTOTB_TVOUT_PC_data_OUT, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_data_OUT, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_data_OUT, AESL_token); // data

			sc_bv<32> *data_OUT_pc_buffer = new sc_bv<32>[32];
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'data_OUT', possible cause: There are uninitialized variables in the C design." << endl;
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'data_OUT', possible cause: There are uninitialized variables in the C design." << endl;
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
					data_OUT_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_data_OUT, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_data_OUT))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: data_OUT
				{
					// bitslice(15, 0)
					// {
						// celement: data_OUT._M_real.V(15, 0)
						// {
							sc_lv<16>* data_OUT__M_real_V_lv0_0_31_1 = new sc_lv<16>[32];
						// }
					// }
					// bitslice(31, 16)
					// {
						// celement: data_OUT._M_imag.V(15, 0)
						// {
							sc_lv<16>* data_OUT__M_imag_V_lv0_0_31_1 = new sc_lv<16>[32];
						// }
					// }

					// bitslice(15, 0)
					{
						int hls_map_index = 0;
						// celement: data_OUT._M_real.V(15, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
								{
									data_OUT__M_real_V_lv0_0_31_1[hls_map_index].range(15, 0) = sc_bv<16>(data_OUT_pc_buffer[hls_map_index].range(15, 0));
									hls_map_index++;
								}
							}
						}
					}
					// bitslice(31, 16)
					{
						int hls_map_index = 0;
						// celement: data_OUT._M_imag.V(15, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
								{
									data_OUT__M_imag_V_lv0_0_31_1[hls_map_index].range(15, 0) = sc_bv<16>(data_OUT_pc_buffer[hls_map_index].range(31, 16));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(15, 0)
					{
						int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_real_data_OUT__M_real_V;
						// celement: data_OUT._M_real.V(15, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : data_OUT[i_0].real()
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : data_OUT[0]
								// output_left_conversion : (wrap_real_data_OUT__M_real_V).range()
								// output_type_conversion : (data_OUT__M_real_V_lv0_0_31_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
								{
									wrap_real_data_OUT__M_real_V = data_OUT[i_0].real();
									(wrap_real_data_OUT__M_real_V).range() = (data_OUT__M_real_V_lv0_0_31_1[hls_map_index]).to_string(SC_BIN).c_str();
									data_OUT[i_0].real(wrap_real_data_OUT__M_real_V);
									hls_map_index++;
								}
							}
						}
					}
					// bitslice(31, 16)
					{
						int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_imag_data_OUT__M_imag_V;
						// celement: data_OUT._M_imag.V(15, 0)
						{
							// carray: (0) => (31) @ (1)
							for (int i_0 = 0; i_0 <= 31; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : data_OUT[i_0].imag()
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : data_OUT[0]
								// output_left_conversion : (wrap_imag_data_OUT__M_imag_V).range()
								// output_type_conversion : (data_OUT__M_imag_V_lv0_0_31_1[hls_map_index]).to_string(SC_BIN).c_str()
								if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
								{
									wrap_imag_data_OUT__M_imag_V = data_OUT[i_0].imag();
									(wrap_imag_data_OUT__M_imag_V).range() = (data_OUT__M_imag_V_lv0_0_31_1[hls_map_index]).to_string(SC_BIN).c_str();
									data_OUT[i_0].imag(wrap_imag_data_OUT__M_imag_V);
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] data_OUT_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "data_IN"
		char* tvin_data_IN = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_data_IN);

		// "data_OUT"
		char* tvin_data_OUT = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_data_OUT);
		char* tvout_data_OUT = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_data_OUT);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_data_IN, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_data_IN, tvin_data_IN);

		sc_bv<32>* data_IN_tvin_wrapc_buffer = new sc_bv<32>[32];

		// RTL Name: data_IN
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_real_data_IN__M_real_V;
				// celement: data_IN._M_real.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_IN[i_0].real()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_IN[0]
						// regulate_c_name       : data_IN__M_real_V
						// input_type_conversion : (wrap_real_data_IN__M_real_V).range().to_string(SC_BIN).c_str()
						if (&(data_IN[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_IN__M_real_V_tmp_mem;
                                 	       wrap_real_data_IN__M_real_V = data_IN[i_0].real();
							data_IN__M_real_V_tmp_mem = (wrap_real_data_IN__M_real_V).range().to_string(SC_BIN).c_str();
							data_IN_tvin_wrapc_buffer[hls_map_index].range(15, 0) = data_IN__M_real_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
			// bitslice(31, 16)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_imag_data_IN__M_imag_V;
				// celement: data_IN._M_imag.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_IN[i_0].imag()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_IN[0]
						// regulate_c_name       : data_IN__M_imag_V
						// input_type_conversion : (wrap_imag_data_IN__M_imag_V).range().to_string(SC_BIN).c_str()
						if (&(data_IN[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_IN__M_imag_V_tmp_mem;
                                 	       wrap_imag_data_IN__M_imag_V = data_IN[i_0].imag();
							data_IN__M_imag_V_tmp_mem = (wrap_imag_data_IN__M_imag_V).range().to_string(SC_BIN).c_str();
							data_IN_tvin_wrapc_buffer[hls_map_index].range(31, 16) = data_IN__M_imag_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 32; i++)
		{
			sprintf(tvin_data_IN, "%s\n", (data_IN_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_data_IN, tvin_data_IN);
		}

		tcl_file.set_num(32, &tcl_file.data_IN_depth);
		sprintf(tvin_data_IN, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_data_IN, tvin_data_IN);

		// release memory allocation
		delete [] data_IN_tvin_wrapc_buffer;

		// [[transaction]]
		sprintf(tvin_data_OUT, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_data_OUT, tvin_data_OUT);

		sc_bv<32>* data_OUT_tvin_wrapc_buffer = new sc_bv<32>[32];

		// RTL Name: data_OUT
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_real_data_OUT__M_real_V;
				// celement: data_OUT._M_real.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_OUT[i_0].real()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_OUT[0]
						// regulate_c_name       : data_OUT__M_real_V
						// input_type_conversion : (wrap_real_data_OUT__M_real_V).range().to_string(SC_BIN).c_str()
						if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_OUT__M_real_V_tmp_mem;
                                 	       wrap_real_data_OUT__M_real_V = data_OUT[i_0].real();
							data_OUT__M_real_V_tmp_mem = (wrap_real_data_OUT__M_real_V).range().to_string(SC_BIN).c_str();
							data_OUT_tvin_wrapc_buffer[hls_map_index].range(15, 0) = data_OUT__M_real_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
			// bitslice(31, 16)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_imag_data_OUT__M_imag_V;
				// celement: data_OUT._M_imag.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_OUT[i_0].imag()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_OUT[0]
						// regulate_c_name       : data_OUT__M_imag_V
						// input_type_conversion : (wrap_imag_data_OUT__M_imag_V).range().to_string(SC_BIN).c_str()
						if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_OUT__M_imag_V_tmp_mem;
                                 	       wrap_imag_data_OUT__M_imag_V = data_OUT[i_0].imag();
							data_OUT__M_imag_V_tmp_mem = (wrap_imag_data_OUT__M_imag_V).range().to_string(SC_BIN).c_str();
							data_OUT_tvin_wrapc_buffer[hls_map_index].range(31, 16) = data_OUT__M_imag_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 32; i++)
		{
			sprintf(tvin_data_OUT, "%s\n", (data_OUT_tvin_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_data_OUT, tvin_data_OUT);
		}

		tcl_file.set_num(32, &tcl_file.data_OUT_depth);
		sprintf(tvin_data_OUT, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_data_OUT, tvin_data_OUT);

		// release memory allocation
		delete [] data_OUT_tvin_wrapc_buffer;

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		FFT(data_IN, data_OUT);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_data_OUT, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_data_OUT, tvout_data_OUT);

		sc_bv<32>* data_OUT_tvout_wrapc_buffer = new sc_bv<32>[32];

		// RTL Name: data_OUT
		{
			// bitslice(15, 0)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_real_data_OUT__M_real_V;
				// celement: data_OUT._M_real.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_OUT[i_0].real()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_OUT[0]
						// regulate_c_name       : data_OUT__M_real_V
						// input_type_conversion : (wrap_real_data_OUT__M_real_V).range().to_string(SC_BIN).c_str()
						if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_OUT__M_real_V_tmp_mem;
                                 	       wrap_real_data_OUT__M_real_V = data_OUT[i_0].real();
							data_OUT__M_real_V_tmp_mem = (wrap_real_data_OUT__M_real_V).range().to_string(SC_BIN).c_str();
							data_OUT_tvout_wrapc_buffer[hls_map_index].range(15, 0) = data_OUT__M_real_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
			// bitslice(31, 16)
			{
				int hls_map_index = 0;
    ap_fixed<16, 8, (ap_q_mode) 5, (ap_o_mode)3, 0> wrap_imag_data_OUT__M_imag_V;
				// celement: data_OUT._M_imag.V(15, 0)
				{
					// carray: (0) => (31) @ (1)
					for (int i_0 = 0; i_0 <= 31; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : data_OUT[i_0].imag()
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : data_OUT[0]
						// regulate_c_name       : data_OUT__M_imag_V
						// input_type_conversion : (wrap_imag_data_OUT__M_imag_V).range().to_string(SC_BIN).c_str()
						if (&(data_OUT[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<16> data_OUT__M_imag_V_tmp_mem;
                                 	       wrap_imag_data_OUT__M_imag_V = data_OUT[i_0].imag();
							data_OUT__M_imag_V_tmp_mem = (wrap_imag_data_OUT__M_imag_V).range().to_string(SC_BIN).c_str();
							data_OUT_tvout_wrapc_buffer[hls_map_index].range(31, 16) = data_OUT__M_imag_V_tmp_mem.range(15, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 32; i++)
		{
			sprintf(tvout_data_OUT, "%s\n", (data_OUT_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_data_OUT, tvout_data_OUT);
		}

		tcl_file.set_num(32, &tcl_file.data_OUT_depth);
		sprintf(tvout_data_OUT, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_data_OUT, tvout_data_OUT);

		// release memory allocation
		delete [] data_OUT_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "data_IN"
		delete [] tvin_data_IN;
		// release memory allocation: "data_OUT"
		delete [] tvout_data_OUT;
		delete [] tvin_data_OUT;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

