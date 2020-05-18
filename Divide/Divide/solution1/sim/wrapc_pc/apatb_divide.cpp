// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================

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


// wrapc file define: "N"
#define AUTOTB_TVIN_N  "../tv/cdatafile/c.divide.autotvin_N.dat"
// wrapc file define: "D"
#define AUTOTB_TVIN_D  "../tv/cdatafile/c.divide.autotvin_D.dat"
// wrapc file define: "Q"
#define AUTOTB_TVOUT_Q  "../tv/cdatafile/c.divide.autotvout_Q.dat"
// wrapc file define: "R"
#define AUTOTB_TVOUT_R  "../tv/cdatafile/c.divide.autotvout_R.dat"

#define INTER_TCL  "../tv/cdatafile/ref.tcl"

// tvout file define: "Q"
#define AUTOTB_TVOUT_PC_Q  "../tv/rtldatafile/rtl.divide.autotvout_Q.dat"
// tvout file define: "R"
#define AUTOTB_TVOUT_PC_R  "../tv/rtldatafile/rtl.divide.autotvout_R.dat"

class INTER_TCL_FILE {
	public:
		INTER_TCL_FILE(const char* name) {
			mName = name;
			N_depth = 0;
			D_depth = 0;
			Q_depth = 0;
			R_depth = 0;
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
			total_list << "{N " << N_depth << "}\n";
			total_list << "{D " << D_depth << "}\n";
			total_list << "{Q " << Q_depth << "}\n";
			total_list << "{R " << R_depth << "}\n";
			return total_list.str();
		}

		void set_num (int num , int* class_num) {
			(*class_num) = (*class_num) > num ? (*class_num) : num;
		}
	public:
		int N_depth;
		int D_depth;
		int Q_depth;
		int R_depth;
		int trans_num;

	private:
		ofstream mFile;
		const char* mName;
};

extern void divide (
unsigned char N,
unsigned char D,
unsigned char* Q,
unsigned char* R);

void AESL_WRAP_divide (
unsigned char N,
unsigned char D,
unsigned char* Q,
unsigned char* R)
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


		// output port post check: "Q"
		aesl_fh.read(AUTOTB_TVOUT_PC_Q, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_Q, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_Q, AESL_token); // data

			sc_bv<8> *Q_pc_buffer = new sc_bv<8>[1];
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'Q', possible cause: There are uninitialized variables in the C design." << endl;
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'Q', possible cause: There are uninitialized variables in the C design." << endl;
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
					Q_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_Q, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_Q))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: Q
				{
					// bitslice(7, 0)
					// {
						// celement: Q(7, 0)
						// {
							sc_lv<8>* Q_lv0_0_0_1 = new sc_lv<8>[1];
						// }
					// }

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: Q(7, 0)
						{
							// carray: (0) => (0) @ (1)
							for (int i_0 = 0; i_0 <= 0; i_0 += 1)
							{
								if (&(Q[0]) != NULL) // check the null address if the c port is array or others
								{
									Q_lv0_0_0_1[hls_map_index].range(7, 0) = sc_bv<8>(Q_pc_buffer[hls_map_index].range(7, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: Q(7, 0)
						{
							// carray: (0) => (0) @ (1)
							for (int i_0 = 0; i_0 <= 0; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : Q[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : Q[0]
								// output_left_conversion : Q[i_0]
								// output_type_conversion : (Q_lv0_0_0_1[hls_map_index]).to_uint64()
								if (&(Q[0]) != NULL) // check the null address if the c port is array or others
								{
									Q[i_0] = (Q_lv0_0_0_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] Q_pc_buffer;
		}

		// output port post check: "R"
		aesl_fh.read(AUTOTB_TVOUT_PC_R, AESL_token); // [[transaction]]
		if (AESL_token != "[[transaction]]")
		{
			exit(1);
		}
		aesl_fh.read(AUTOTB_TVOUT_PC_R, AESL_num); // transaction number

		if (atoi(AESL_num.c_str()) == AESL_transaction_pc)
		{
			aesl_fh.read(AUTOTB_TVOUT_PC_R, AESL_token); // data

			sc_bv<8> *R_pc_buffer = new sc_bv<8>[1];
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'R', possible cause: There are uninitialized variables in the C design." << endl;
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
							cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port 'R', possible cause: There are uninitialized variables in the C design." << endl;
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
					R_pc_buffer[i] = AESL_token.c_str();
					i++;
				}

				aesl_fh.read(AUTOTB_TVOUT_PC_R, AESL_token); // data or [[/transaction]]

				if (AESL_token == "[[[/runtime]]]" || aesl_fh.eof(AUTOTB_TVOUT_PC_R))
				{
					exit(1);
				}
			}

			// ***********************************
			if (i > 0)
			{
				// RTL Name: R
				{
					// bitslice(7, 0)
					// {
						// celement: R(7, 0)
						// {
							sc_lv<8>* R_lv0_0_0_1 = new sc_lv<8>[1];
						// }
					// }

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: R(7, 0)
						{
							// carray: (0) => (0) @ (1)
							for (int i_0 = 0; i_0 <= 0; i_0 += 1)
							{
								if (&(R[0]) != NULL) // check the null address if the c port is array or others
								{
									R_lv0_0_0_1[hls_map_index].range(7, 0) = sc_bv<8>(R_pc_buffer[hls_map_index].range(7, 0));
									hls_map_index++;
								}
							}
						}
					}

					// bitslice(7, 0)
					{
						int hls_map_index = 0;
						// celement: R(7, 0)
						{
							// carray: (0) => (0) @ (1)
							for (int i_0 = 0; i_0 <= 0; i_0 += 1)
							{
								// sub                    : i_0
								// ori_name               : R[i_0]
								// sub_1st_elem           : 0
								// ori_name_1st_elem      : R[0]
								// output_left_conversion : R[i_0]
								// output_type_conversion : (R_lv0_0_0_1[hls_map_index]).to_uint64()
								if (&(R[0]) != NULL) // check the null address if the c port is array or others
								{
									R[i_0] = (R_lv0_0_0_1[hls_map_index]).to_uint64();
									hls_map_index++;
								}
							}
						}
					}
				}
			}

			// release memory allocation
			delete [] R_pc_buffer;
		}

		AESL_transaction_pc++;
	}
	else
	{
		CodeState = ENTER_WRAPC;
		static unsigned AESL_transaction;

		static AESL_FILE_HANDLER aesl_fh;

		// "N"
		char* tvin_N = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_N);

		// "D"
		char* tvin_D = new char[50];
		aesl_fh.touch(AUTOTB_TVIN_D);

		// "Q"
		char* tvout_Q = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_Q);

		// "R"
		char* tvout_R = new char[50];
		aesl_fh.touch(AUTOTB_TVOUT_R);

		CodeState = DUMP_INPUTS;
		static INTER_TCL_FILE tcl_file(INTER_TCL);
		int leading_zero;

		// [[transaction]]
		sprintf(tvin_N, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_N, tvin_N);

		sc_bv<8> N_tvin_wrapc_buffer;

		// RTL Name: N
		{
			// bitslice(7, 0)
			{
				// celement: N(7, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : N
						// sub_1st_elem          : 
						// ori_name_1st_elem     : N
						// regulate_c_name       : N
						// input_type_conversion : N
						if (&(N) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> N_tmp_mem;
							N_tmp_mem = N;
							N_tvin_wrapc_buffer.range(7, 0) = N_tmp_mem.range(7, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_N, "%s\n", (N_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_N, tvin_N);
		}

		tcl_file.set_num(1, &tcl_file.N_depth);
		sprintf(tvin_N, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_N, tvin_N);

		// [[transaction]]
		sprintf(tvin_D, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVIN_D, tvin_D);

		sc_bv<8> D_tvin_wrapc_buffer;

		// RTL Name: D
		{
			// bitslice(7, 0)
			{
				// celement: D(7, 0)
				{
					// carray: (0) => (0) @ (0)
					{
						// sub                   : 
						// ori_name              : D
						// sub_1st_elem          : 
						// ori_name_1st_elem     : D
						// regulate_c_name       : D
						// input_type_conversion : D
						if (&(D) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> D_tmp_mem;
							D_tmp_mem = D;
							D_tvin_wrapc_buffer.range(7, 0) = D_tmp_mem.range(7, 0);
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvin_D, "%s\n", (D_tvin_wrapc_buffer).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVIN_D, tvin_D);
		}

		tcl_file.set_num(1, &tcl_file.D_depth);
		sprintf(tvin_D, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVIN_D, tvin_D);

// [call_c_dut] ---------->

		CodeState = CALL_C_DUT;
		divide(N, D, Q, R);

		CodeState = DUMP_OUTPUTS;

		// [[transaction]]
		sprintf(tvout_Q, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_Q, tvout_Q);

		sc_bv<8>* Q_tvout_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: Q
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: Q(7, 0)
				{
					// carray: (0) => (0) @ (1)
					for (int i_0 = 0; i_0 <= 0; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : Q[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : Q[0]
						// regulate_c_name       : Q
						// input_type_conversion : Q[i_0]
						if (&(Q[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> Q_tmp_mem;
							Q_tmp_mem = Q[i_0];
							Q_tvout_wrapc_buffer[hls_map_index].range(7, 0) = Q_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_Q, "%s\n", (Q_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_Q, tvout_Q);
		}

		tcl_file.set_num(1, &tcl_file.Q_depth);
		sprintf(tvout_Q, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_Q, tvout_Q);

		// release memory allocation
		delete [] Q_tvout_wrapc_buffer;

		// [[transaction]]
		sprintf(tvout_R, "[[transaction]] %d\n", AESL_transaction);
		aesl_fh.write(AUTOTB_TVOUT_R, tvout_R);

		sc_bv<8>* R_tvout_wrapc_buffer = new sc_bv<8>[1];

		// RTL Name: R
		{
			// bitslice(7, 0)
			{
				int hls_map_index = 0;
				// celement: R(7, 0)
				{
					// carray: (0) => (0) @ (1)
					for (int i_0 = 0; i_0 <= 0; i_0 += 1)
					{
						// sub                   : i_0
						// ori_name              : R[i_0]
						// sub_1st_elem          : 0
						// ori_name_1st_elem     : R[0]
						// regulate_c_name       : R
						// input_type_conversion : R[i_0]
						if (&(R[0]) != NULL) // check the null address if the c port is array or others
						{
							sc_lv<8> R_tmp_mem;
							R_tmp_mem = R[i_0];
							R_tvout_wrapc_buffer[hls_map_index].range(7, 0) = R_tmp_mem.range(7, 0);
                                 	       hls_map_index++;
						}
					}
				}
			}
		}

		// dump tv to file
		for (int i = 0; i < 1; i++)
		{
			sprintf(tvout_R, "%s\n", (R_tvout_wrapc_buffer[i]).to_string(SC_HEX).c_str());
			aesl_fh.write(AUTOTB_TVOUT_R, tvout_R);
		}

		tcl_file.set_num(1, &tcl_file.R_depth);
		sprintf(tvout_R, "[[/transaction]] \n");
		aesl_fh.write(AUTOTB_TVOUT_R, tvout_R);

		// release memory allocation
		delete [] R_tvout_wrapc_buffer;

		CodeState = DELETE_CHAR_BUFFERS;
		// release memory allocation: "N"
		delete [] tvin_N;
		// release memory allocation: "D"
		delete [] tvin_D;
		// release memory allocation: "Q"
		delete [] tvout_Q;
		// release memory allocation: "R"
		delete [] tvout_R;

		AESL_transaction++;

		tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
	}
}

