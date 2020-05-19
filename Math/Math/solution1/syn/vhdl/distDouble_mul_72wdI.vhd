-- ==============================================================
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.2 (64-bit)
-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity distDouble_mul_72wdI_MulnS_9 is
port (
    clk: in std_logic;
    ce: in std_logic;
    a: in std_logic_vector(72 - 1 downto 0);
    b: in std_logic_vector(13 - 1 downto 0);
    p: out std_logic_vector(83 - 1 downto 0));
end entity;

architecture behav of distDouble_mul_72wdI_MulnS_9 is
    signal tmp_product : std_logic_vector(83 - 1 downto 0);
    signal a_i : std_logic_vector(72 - 1 downto 0);
    signal b_i : std_logic_vector(13 - 1 downto 0);
    signal p_tmp : std_logic_vector(83 - 1 downto 0);

begin
    a_i <= a;
    b_i <= b;
    p <= p_tmp;

    tmp_product <= std_logic_vector(resize(unsigned(std_logic_vector(signed('0' & a_i) * signed(b_i))), 83));

    process(clk)
    begin
        if (clk'event and clk = '1') then
            if (ce = '1') then
                p_tmp <= tmp_product;
            end if;
        end if;
    end process;
end architecture;
Library IEEE;
use IEEE.std_logic_1164.all;

entity distDouble_mul_72wdI is
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER);
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        ce : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR(din0_WIDTH - 1 DOWNTO 0);
        din1 : IN STD_LOGIC_VECTOR(din1_WIDTH - 1 DOWNTO 0);
        dout : OUT STD_LOGIC_VECTOR(dout_WIDTH - 1 DOWNTO 0));
end entity;

architecture arch of distDouble_mul_72wdI is
    component distDouble_mul_72wdI_MulnS_9 is
        port (
            clk : IN STD_LOGIC;
            ce : IN STD_LOGIC;
            a : IN STD_LOGIC_VECTOR;
            b : IN STD_LOGIC_VECTOR;
            p : OUT STD_LOGIC_VECTOR);
    end component;



begin
    distDouble_mul_72wdI_MulnS_9_U :  component distDouble_mul_72wdI_MulnS_9
    port map (
        clk => clk,
        ce => ce,
        a => din0,
        b => din1,
        p => dout);

end architecture;


