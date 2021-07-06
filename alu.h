#include "systemc.h"

SC_MODULE(alu)
{
    //ports
    sc_in<sc_lv<32>> in_1, in_2;
    sc_in<sc_lv<4>> alu_control_fuct;
    sc_out<sc_logic> zero;
    sc_out<sc_lv<32>> alu_result;

    //signals
    sc_lv<4> and_op = "0000";
    sc_lv<4> or_op = "0001";
    sc_lv<4> add = "0010";
    sc_lv<4> subtract_not_equal = "0011";
    sc_lv<4> subtract = "0110";
    sc_lv<4> set_on_less_than = "0111";

    SC_CTOR(alu)
    {
        SC_METHOD(doAlu);
        sensitive << in_1 << in_2 << alu_control_fuct;
    }

    void doAlu()
    {
        //alu_result
        if(alu_control_fuct.read() == add)
            alu_result.write(in_1.read().to_int() + in_2.read().to_int());
        else if(alu_control_fuct.read() == subtract || alu_control_fuct.read() == subtract_not_equal)
            alu_result.write(in_1.read().to_int() - in_2.read().to_int());
        else if(alu_control_fuct.read() == and_op)
            alu_result.write(in_1.read() & in_2.read());
        else if(alu_control_fuct.read() == or_op)
            alu_result.write(in_1.read() | in_2.read());
        else if(alu_control_fuct.read() == set_on_less_than && in_1.read().to_int() < in_2.read().to_int())
            alu_result.write("00000000000000000000000000000001");
        else if(alu_control_fuct.read() == set_on_less_than)
            alu_result.write("00000000000000000000000000000000");

        //zero
        if(in_1.read() != in_2.read() && alu_control_fuct.read() == subtract_not_equal)
            zero.write(SC_LOGIC_1);
        else if(in_1.read() == in_2.read() && alu_control_fuct.read() == subtract_not_equal)
            zero.write(SC_LOGIC_0);
        else if(in_1.read() == in_2.read())
            zero.write(SC_LOGIC_1);
        else
            zero.write(SC_LOGIC_0);
        
    }
};