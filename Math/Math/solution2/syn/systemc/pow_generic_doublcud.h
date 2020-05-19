// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __pow_generic_doublcud_H__
#define __pow_generic_doublcud_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct pow_generic_doublcud_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 109;
  static const unsigned AddressRange = 64;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(pow_generic_doublcud_ram) {
        ram[0] = "0b1111111101111100000111101111110100011001001011101110001101001111110011101110101001010001100111100010101010000";
        ram[1] = "0b1111111101111100000111101111110100011001001011101110001101001111110011101110101001010001100111100010101010000";
        ram[2] = "0b1111111101111100000111101111110100011001001011101110001101001111110011101110101001010001100111100010101010000";
        ram[3] = "0b0000011110011100110011011100001000001100110100010000010110000111110110101000100010001100100010001001011011001";
        ram[4] = "0b0000011110011100110011011100001000001100110100010000010110000111110110101000100010001100100010001001011011001";
        ram[5] = "0b0001000000000001101101111011001010110111011010001110100111011000011100101110011111101101100100110010110110111";
        ram[6] = "0b0001000000000001101101111011001010110111011010001110100111011000011100101110011111101101100100110010110110111";
        ram[7] = "0b0001100010101111011111010101101001110010011110000110101111111101111011000100100011110101100010101111011110101";
        ram[8] = "0b0001100010101111011111010101101001110010011110000110101111111101111011000100100011110101100010101111011110101";
        ram[9] = "0b0001100010101111011111010101101001110010011110000110101111111101111011000100100011110101100010101111011110101";
        ram[10] = "0b0010000110101011001111000000000101101000111101111101101100001100001101100000000011010101100101110001000001000";
        ram[11] = "0b0010000110101011001111000000000101101000111101111101101100001100001101100000000011010101100101110001000001000";
        ram[12] = "0b0010101011111010100111111101001111000001101010100100011101000110110101000001000000101011100101110010111010010";
        ram[13] = "0b0010101011111010100111111101001111000001101010100100011101000110110101000001000000101011100101110010111010010";
        ram[14] = "0b0010101011111010100111111101001111000001101010100100011101000110110101000001000000101011100101110010111010010";
        ram[15] = "0b0011010010100011111110010111011000101110111000101010101000101110001001101011111101000000111010011011101010100";
        ram[16] = "0b0011010010100011111110010111011000101110111000101010101000101110001001101011111101000000111010011011101010100";
        ram[17] = "0b0011010010100011111110010111011000101110111000101010101000101110001001101011111101000000111010011011101010100";
        ram[18] = "0b0011111010101110010101111101011010000000100101011101011001001011000000010110110110001001011010100010111110010";
        ram[19] = "0b0011111010101110010101111101011010000000100101011101011001001011000000010110110110001001011010100010111110010";
        ram[20] = "0b0011111010101110010101111101011010000000100101011101011001001011000000010110110110001001011010100010111110010";
        ram[21] = "0b0011111010101110010101111101011010000000100101011101011001001011000000010110110110001001011010100010111110010";
        ram[22] = "0b0100100100100001101001110100000111101100100111010010110100110000101111101001100000101011011110010010110100110";
        ram[23] = "0b0100100100100001101001110100000111101100100111010010110100110000101111101001100000101011011110010010110100110";
        ram[24] = "0b0100100100100001101001110100000111101100100111010010110100110000101111101001100000101011011110010010110100110";
        ram[25] = "0b0100100100100001101001110100000111101100100111010010110100110000101111101001100000101011011110010010110100110";
        ram[26] = "0b0101010000000110110101110001100111111011101111100100001010001000000011111001110010110101010010101101111010111";
        ram[27] = "0b0101010000000110110101110001100111111011101111100100001010001000000011111001110010110101010010101101111010111";
        ram[28] = "0b0101010000000110110101110001100111111011101111100100001010001000000011111001110010110101010010101101111010111";
        ram[29] = "0b0101010000000110110101110001100111111011101111100100001010001000000011111001110010110101010010101101111010111";
        ram[30] = "0b0101111101101000000001111110110001111001100000110101001100000111011010101110000100100110011010010011110010101";
        ram[31] = "0b0101111101101000000001111110110001111001100000110101001100000111011010101110000100100110011010010011110010101";
        ram[32] = "0b1011001111011000100101000001000110010100101110100010000011011111000110111100010111100111100010100000101000011";
        ram[33] = "0b1011001111011000100101000001000110010100101110100010000011011111000110111100010111100111100010100000101000011";
        ram[34] = "0b1011100111011110101011000100111001101010100101101010101101000001010110111100101011111011110110100000111011111";
        ram[35] = "0b1011100111011110101011000100111001101010100101101010101101000001010110111100101011111011110110100000111011111";
        ram[36] = "0b1100000000001001111011100010001001011100101100101000111000110101001001000101110101111001001011110000000011100";
        ram[37] = "0b1100000000001001111011100010001001011100101100101000111000110101001001000101110101111001001011110000000011100";
        ram[38] = "0b1100000000001001111011100010001001011100101100101000111000110101001001000101110101111001001011110000000011100";
        ram[39] = "0b1100011001011100001011110110110111100011111110101001111111110111100000110011101000010011101110000010101100010";
        ram[40] = "0b1100011001011100001011110110110111100011111110101001111111110111100000110011101000010011101110000010101100010";
        ram[41] = "0b1100011001011100001011110110110111100011111110101001111111110111100000110011101000010011101110000010101100010";
        ram[42] = "0b1100110011010111011010011100001100110000100000010111101001100011010011001000100101100111001011001011100101011";
        ram[43] = "0b1100110011010111011010011100001100110000100000010111101001100011010011001000100101100111001011001011100101011";
        ram[44] = "0b1101001101111101101111100001101111001010000001110011101110111110111001110010011000111101100011111110100000111";
        ram[45] = "0b1101001101111101101111100001101111001010000001110011101110111110111001110010011000111101100011111110100000111";
        ram[46] = "0b1101001101111101101111100001101111001010000001110011101110111110111001110010011000111101100011111110100000111";
        ram[47] = "0b1101101001010001011110010000110011011001010001001001110010110111110000110011000101101111100110100011110010010";
        ram[48] = "0b1101101001010001011110010000110011011001010001001001110010110111110000110011000101101111100110100011110010010";
        ram[49] = "0b1101101001010001011110010000110011011001010001001001110010110111110000110011000101101111100110100011110010010";
        ram[50] = "0b1110000101010101000101111000111011101110001110111111110101100101111001000110001001010001101111000010101111101";
        ram[51] = "0b1110000101010101000101111000111011101110001110111111110101100101111001000110001001010001101111000010101111101";
        ram[52] = "0b1110000101010101000101111000111011101110001110111111110101100101111001000110001001010001101111000010101111101";
        ram[53] = "0b1110000101010101000101111000111011101110001110111111110101100101111001000110001001010001101111000010101111101";
        ram[54] = "0b1110100010001011010011000111001000110011110000111001011110110011111010100101000010010111101100010001000011010";
        ram[55] = "0b1110100010001011010011000111001000110011110000111001011110110011111010100101000010010111101100010001000011010";
        ram[56] = "0b1110100010001011010011000111001000110011110000111001011110110011111010100101000010010111101100010001000011010";
        ram[57] = "0b1110111111110111000001101001110100010000011111011001000000011111000100001000010110011000111001101011010011101";
        ram[58] = "0b1110111111110111000001101001110100010000011111011001000000011111000100001000010110011000111001101011010011101";
        ram[59] = "0b1110111111110111000001101001110100010000011111011001000000011111000100001000010110011000111001101011010011101";
        ram[60] = "0b1110111111110111000001101001110100010000011111011001000000011111000100001000010110011000111001101011010011101";
        ram[61] = "0b1111011110011011011110000011100101111011001000100010001100111100100100001010101101001100101011000011101101100";
        ram[62] = "0b1111011110011011011110000011100101111011001000100010001100111100100100001010101101001100101011000011101101100";
        ram[63] = "0b1111011110011011011110000011100101111011001000100010001100111100100100001010101101001100101011000011101101100";


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


SC_MODULE(pow_generic_doublcud) {


static const unsigned DataWidth = 109;
static const unsigned AddressRange = 64;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


pow_generic_doublcud_ram* meminst;


SC_CTOR(pow_generic_doublcud) {
meminst = new pow_generic_doublcud_ram("pow_generic_doublcud_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~pow_generic_doublcud() {
    delete meminst;
}


};//endmodule
#endif
