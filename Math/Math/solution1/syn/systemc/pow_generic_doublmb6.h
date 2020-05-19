// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __pow_generic_doublmb6_H__
#define __pow_generic_doublmb6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct pow_generic_doublmb6_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 42;
  static const unsigned AddressRange = 256;
  static const unsigned AddressWidth = 8;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(pow_generic_doublmb6_ram) {
        ram[0] = "0b000000000000000000000000000000000000000000";
        ram[1] = "0b000000000000000100000000000000000101010101";
        ram[2] = "0b000000000000010000000000000000101010101010";
        ram[3] = "0b000000000000100100000000000010010000000000";
        ram[4] = "0b000000000001000000000000000101010101010101";
        ram[5] = "0b000000000001100100000000001010011010101011";
        ram[6] = "0b000000000010010000000000010010000000000001";
        ram[7] = "0b000000000011000100000000011100100101011000";
        ram[8] = "0b000000000100000000000000101010101010110000";
        ram[9] = "0b000000000101000100000000111100110000001000";
        ram[10] = "0b000000000110010000000001010011010101100010";
        ram[11] = "0b000000000111100100000001101110111010111101";
        ram[12] = "0b000000001001000000000010010000000000011011";
        ram[13] = "0b000000001010100100000010110111000101111010";
        ram[14] = "0b000000001100010000000011100100101011011100";
        ram[15] = "0b000000001110000100000100011001010001000001";
        ram[16] = "0b000000010000000000000101010101010110101010";
        ram[17] = "0b000000010010000100000110011001011100010111";
        ram[18] = "0b000000010100010000000111100110000010001000";
        ram[19] = "0b000000010110100100001000111011100111111111";
        ram[20] = "0b000000011001000000001010011010101101111011";
        ram[21] = "0b000000011011100100001100000011110011111101";
        ram[22] = "0b000000011110010000001101110111011010000110";
        ram[23] = "0b000000100001000100001111110110000000010111";
        ram[24] = "0b000000100100000000010010000000000110110000";
        ram[25] = "0b000000100111000100010100010110001101010001";
        ram[26] = "0b000000101010010000010110111000110011111101";
        ram[27] = "0b000000101101100100011001101000011010110100";
        ram[28] = "0b000000110001000000011100100101100001110101";
        ram[29] = "0b000000110100100100011111110000101001000011";
        ram[30] = "0b000000111000010000100011001010010000011110";
        ram[31] = "0b000000111100000100100110110010111000000111";
        ram[32] = "0b000001000000000000101010101011000000000000";
        ram[33] = "0b000001000100000100101110110011001000001000";
        ram[34] = "0b000001001000010000110011001011110000100001";
        ram[35] = "0b000001001100100100110111110101011001001100";
        ram[36] = "0b000001010001000000111100110000100010001011";
        ram[37] = "0b000001010101100101000001111101101011011101";
        ram[38] = "0b000001011010010001000111011101010101000110";
        ram[39] = "0b000001011111000101001101001111111111000100";
        ram[40] = "0b000001100100000001010011010110001001011011";
        ram[41] = "0b000001101001000101011001110000010100001010";
        ram[42] = "0b000001101110010001100000011110111111010100";
        ram[43] = "0b000001110011100101100111100010101010111001";
        ram[44] = "0b000001111001000001101110111011110110111011";
        ram[45] = "0b000001111110100101110110101011000011011100";
        ram[46] = "0b000010000100010001111110110000110000011100";
        ram[47] = "0b000010001010000110000111001101011101111101";
        ram[48] = "0b000010010000000010010000000001101100000001";
        ram[49] = "0b000010010110000110011001001101111010101000";
        ram[50] = "0b000010011100010010100010110010101001110101";
        ram[51] = "0b000010100010100110101100110000011001101010";
        ram[52] = "0b000010101001000010110111000111101010000111";
        ram[53] = "0b000010101111100111000001111000111011001110";
        ram[54] = "0b000010110110010011001101000100101101000001";
        ram[55] = "0b000010111101000111011000101011011111100010";
        ram[56] = "0b000011000100000011100100101101110010110010";
        ram[57] = "0b000011001011000111110001001100000110110011";
        ram[58] = "0b000011010010010011111110000110111011100110";
        ram[59] = "0b000011011001101000001011011110110001001111";
        ram[60] = "0b000011100001000100011001010100000111101110";
        ram[61] = "0b000011101000101000100111100111011111000101";
        ram[62] = "0b000011110000010100110110011001010111010110";
        ram[63] = "0b000011111000001001000101101010010000100011";
        ram[64] = "0b000100000000000101010101011010101010101110";
        ram[65] = "0b000100001000001001100101101011000101111010";
        ram[66] = "0b000100010000010101110110011100000010000111";
        ram[67] = "0b000100011000101010000111101101111111011001";
        ram[68] = "0b000100100001000110011001100001011101110000";
        ram[69] = "0b000100101001101010101011110110111101010000";
        ram[70] = "0b000100110010010110111110101110111101111011";
        ram[71] = "0b000100111011001011010010001001111111110001";
        ram[72] = "0b000101000100000111100110001000100010110111";
        ram[73] = "0b000101001101001011111010101011000111001110";
        ram[74] = "0b000101010110011000001111110010001100111000";
        ram[75] = "0b000101011111101100100101011110010011111000";
        ram[76] = "0b000101101001001000111011101111111100001111";
        ram[77] = "0b000101110010101101010010100111100110000001";
        ram[78] = "0b000101111100011001101010000101110001010000";
        ram[79] = "0b000110000110001110000010001010111101111101";
        ram[80] = "0b000110010000001010011010110111101100001101";
        ram[81] = "0b000110011010001110110100001100011100000000";
        ram[82] = "0b000110100100011011001110001001101101011010";
        ram[83] = "0b000110101110101111101000110000000000011101";
        ram[84] = "0b000110111001001100000011111111110101001011";
        ram[85] = "0b000111000011110000011111111001101011101000";
        ram[86] = "0b000111001110011100111100011110000011110110";
        ram[87] = "0b000111011001010001011001101101011101110111";
        ram[88] = "0b000111100100001101110111101000011001101111";
        ram[89] = "0b000111101111010010010110001111010111100000";
        ram[90] = "0b000111111010011110110101100010110111001101";
        ram[91] = "0b001000000101110011010101100011011000111000";
        ram[92] = "0b001000010001001111110110010001011100100101";
        ram[93] = "0b001000011100110100010111101101100010010110";
        ram[94] = "0b001000101000100000111001111000001010001110";
        ram[95] = "0b001000110100010101011100110001110100010000";
        ram[96] = "0b001001000000010010000000011011000000100000";
        ram[97] = "0b001001001100010110100100110100001110111111";
        ram[98] = "0b001001011000100011001001111101111111110010";
        ram[99] = "0b001001100100110111101111111000110010111011";
        ram[100] = "0b001001110001010100010110100101001000011101";
        ram[101] = "0b001001111101111000111110000011100000011011";
        ram[102] = "0b001010001010100101100110010100011010111001";
        ram[103] = "0b001010010111011010001111011000010111111010";
        ram[104] = "0b001010100100010110111001001111110111100000";
        ram[105] = "0b001010110001011011100011111011011001101111";
        ram[106] = "0b001010111110101000001111011011011110101011";
        ram[107] = "0b001011001011111100111011110000100110010110";
        ram[108] = "0b001011011001011001101000111011010000110101";
        ram[109] = "0b001011100110111110010110111011111110001010";
        ram[110] = "0b001011110100101011000101110011001110011000";
        ram[111] = "0b001100000010011111110101100001100001100100";
        ram[112] = "0b001100010000011100100110000111010111110000";
        ram[113] = "0b001100011110100001010111100101010001000001";
        ram[114] = "0b001100101100101110001001111011101101011001";
        ram[115] = "0b001100111011000010111101001011001100111100";
        ram[116] = "0b001101001001011111110001010100001111101110";
        ram[117] = "0b001101011000000100100110010111010101110010";
        ram[118] = "0b001101100110110001011100010100111111001101";
        ram[119] = "0b001101110101100110010011001101101100000001";
        ram[120] = "0b001110000100100011001011000001111100010010";
        ram[121] = "0b001110010011101000000011110010010000000101";
        ram[122] = "0b001110100010110100111101011111000111011101";
        ram[123] = "0b001110110010001001111000001001000010011101";
        ram[124] = "0b001111000001100110110011110000100001001010";
        ram[125] = "0b001111010001001011110000010110000011100111";
        ram[126] = "0b001111100000111000101101111010001001111000";
        ram[127] = "0b001111110000101101101100011101010100000010";
        ram[128] = "0b010000000000101010101100000000000010001000";
        ram[129] = "0b010000010000101111101100100010110100001110";
        ram[130] = "0b010000100000111100101110000110001010011000";
        ram[131] = "0b010000110001010001110000101010100100101011";
        ram[132] = "0b010001000001101110110100010000100011001010";
        ram[133] = "0b010001010010010011111000111000100101111001";
        ram[134] = "0b010001100011000000111110100011001100111101";
        ram[135] = "0b010001110011110110000101010000111000011010";
        ram[136] = "0b010010000100110011001101000010001000010011";
        ram[137] = "0b010010010101111000010101110111011100101110";
        ram[138] = "0b010010100111000101011111110001010101101110";
        ram[139] = "0b010010111000011010101010110000010011011000";
        ram[140] = "0b010011001001110111110110110100110101110000";
        ram[141] = "0b010011011011011101000011111111011100111011";
        ram[142] = "0b010011101101001010010010010000101000111100";
        ram[143] = "0b010011111110111111100001101000111001111001";
        ram[144] = "0b010100010000111100110010001000101111110110";
        ram[145] = "0b010100100011000010000011110000101010110110";
        ram[146] = "0b010100110101001111010110100001001011000000";
        ram[147] = "0b010101000111100100101010011010110000010111";
        ram[148] = "0b010101011010000001111111011101111010111111";
        ram[149] = "0b010101101100100111010101101011001010111111";
        ram[150] = "0b010101111111010100101101000011000000011001";
        ram[151] = "0b010110010010001010000101100101111011010011";
        ram[152] = "0b010110100101000111011111010100011011110010";
        ram[153] = "0b010110111000001100111010001111000001111010";
        ram[154] = "0b010111001011011010010110010110001101110000";
        ram[155] = "0b010111011110101111110011101010011111011001";
        ram[156] = "0b010111110010001101010010001100010110111010";
        ram[157] = "0b011000000101110010110001111100010100010111";
        ram[158] = "0b011000011001100000010010111010110111110110";
        ram[159] = "0b011000101101010101110101001000100001011011";
        ram[160] = "0b011001000001010011011000100101110001001011";
        ram[161] = "0b011001010101011000111101010011000111001100";
        ram[162] = "0b011001101001100110100011010001000011100010";
        ram[163] = "0b011001111101111100001010100000000110010010";
        ram[164] = "0b011010010010011001110011000000101111100010";
        ram[165] = "0b011010100110111111011100110011011111010111";
        ram[166] = "0b011010111011101101000111111000110101110101";
        ram[167] = "0b011011010000100010110100010001010011000010";
        ram[168] = "0b011011100101100000100001111101010111000100";
        ram[169] = "0b011011111010100110010000111101100001111110";
        ram[170] = "0b011100001111110100000001010010010011111000";
        ram[171] = "0b011100100101001001110010111100001100110101";
        ram[172] = "0b011100111010100111100101111011101100111100";
        ram[173] = "0b011101010000001101011010010001010100010001";
        ram[174] = "0b011101100101111011001111111101100010111010";
        ram[175] = "0b011101111011110001000111000000111000111101";
        ram[176] = "0b011110010001101110111111011011110110011111";
        ram[177] = "0b011110100111110100111001001110111011100101";
        ram[178] = "0b011110111110000010110100011010101000010101";
        ram[179] = "0b011111010100011000110000111111011100110101";
        ram[180] = "0b011111101010110110101110111101111001001010";
        ram[181] = "0b100000000001011100101110010110011101011001";
        ram[182] = "0b100000011000001010101111001001101001101001";
        ram[183] = "0b100000101111000000110001010111111101111111";
        ram[184] = "0b100001000101111110110101000001111010100001";
        ram[185] = "0b100001011101000100111010000111111111010100";
        ram[186] = "0b100001110100010011000000101010101100011110";
        ram[187] = "0b100010001011101001001000101010100010000110";
        ram[188] = "0b100010100011000111010010001000000000010000";
        ram[189] = "0b100010111010101101011101000011100111000011";
        ram[190] = "0b100011010010011011101001011101110110100101";
        ram[191] = "0b100011101010010001110111010111001110111100";
        ram[192] = "0b100100000010010000000110110000010000001101";
        ram[193] = "0b100100011010010110010111101001011010011110";
        ram[194] = "0b100100110010100100101010000011001101110111";
        ram[195] = "0b100101001010111010111101111110001010011100";
        ram[196] = "0b100101100011011001010011011010110000010011";
        ram[197] = "0b100101111011111111101010011001011111100100";
        ram[198] = "0b100110010100101110000010111010111000010011";
        ram[199] = "0b100110101101100100011100111111011010101000";
        ram[200] = "0b100111000110100010111000100111100110101000";
        ram[201] = "0b100111011111101001010101110011111100011001";
        ram[202] = "0b100111111000110111110100100100111100000011";
        ram[203] = "0b101000010010001110010100111011000101101011";
        ram[204] = "0b101000101011101100110110110110111001010111";
        ram[205] = "0b101001000101010011011010011000110111001110";
        ram[206] = "0b101001011111000001111111100001011111010111";
        ram[207] = "0b101001111000111000100110010001010001110111";
        ram[208] = "0b101010010010110111001110101000101110110110";
        ram[209] = "0b101010101100111101111000101000010110011001";
        ram[210] = "0b101011000111001100100100010000101000101000";
        ram[211] = "0b101011100001100011010001100010000101101000";
        ram[212] = "0b101011111100000010000000011101001101100001";
        ram[213] = "0b101100010110101000110001000010100000011001";
        ram[214] = "0b101100110001010111100011010010011110010110";
        ram[215] = "0b101101001100001110010111001101100111100000";
        ram[216] = "0b101101100111001101001100110100011011111101";
        ram[217] = "0b101110000010010100000100000111011011110100";
        ram[218] = "0b101110011101100010111101000111000111001011";
        ram[219] = "0b101110111000111001110111110011111110001001";
        ram[220] = "0b101111010100011000110100001110100000110110";
        ram[221] = "0b101111101111111111110010010111001111011000";
        ram[222] = "0b110000001011101110110010001110101001110110";
        ram[223] = "0b110000100111100101110011110101010000010111";
        ram[224] = "0b110001000011100100110111001011100011000010";
        ram[225] = "0b110001011111101011111100010010000001111101";
        ram[226] = "0b110001111011111011000011001001001101010001";
        ram[227] = "0b110010011000010010001011110001100101000100";
        ram[228] = "0b110010110100110001010110001011101001011100";
        ram[229] = "0b110011010001011000100010010111111010100010";
        ram[230] = "0b110011101110000111110000010110111000011100";
        ram[231] = "0b110100001010111111000000001001000011010010";
        ram[232] = "0b110100100111111110010001101110111011001010";
        ram[233] = "0b110101000101000101100101001001000000001101";
        ram[234] = "0b110101100010010100111010010111110010100001";
        ram[235] = "0b110101111111101100010001011011110010001101";
        ram[236] = "0b110110011101001011101010010101011111011001";
        ram[237] = "0b110110111010110011000101000101011010001101";
        ram[238] = "0b110111011000100010100001101100000010101111";
        ram[239] = "0b110111110110011010000000001001111001000111";
        ram[240] = "0b111000010100011001100000011111011101011101";
        ram[241] = "0b111000110010100001000010101101001111111001";
        ram[242] = "0b111001010000110000100110110011110000100000";
        ram[243] = "0b111001101111001000001100110011011111011100";
        ram[244] = "0b111010001101100111110100101100111100110100";
        ram[245] = "0b111010101100001111011110100000101000101111";
        ram[246] = "0b111011001010111111001010001111000011010101";
        ram[247] = "0b111011101001110110110111111000101100101110";
        ram[248] = "0b111100001000110110100111011110000101000010";
        ram[249] = "0b111100100111111110011000111111101100010111";
        ram[250] = "0b111101000111001110001100011110000010110111";
        ram[251] = "0b111101100110100110000001111001101000101000";
        ram[252] = "0b111110000110000101111001010010111101110011";
        ram[253] = "0b111110100101101101110010101010100010100000";
        ram[254] = "0b111111000101011101101110000000110110110110";
        ram[255] = "0b111111100101010101101011010110011010111101";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(pow_generic_doublmb6) {


static const unsigned DataWidth = 42;
static const unsigned AddressRange = 256;
static const unsigned AddressWidth = 8;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


pow_generic_doublmb6_ram* meminst;


SC_CTOR(pow_generic_doublmb6) {
meminst = new pow_generic_doublmb6_ram("pow_generic_doublmb6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~pow_generic_doublmb6() {
    delete meminst;
}


};//endmodule
#endif
