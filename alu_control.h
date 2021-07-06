#include "systemc.h"

SC_MODULE(alu_control)
{
    //ports
    sc_in<sc_lv<6>> funct;
    sc_in<sc_lv<2>> alu_op;
    sc_out<sc_lv<4>> alu_control_fuct;

    //signals
    sc_lv<4> and_op = "0000";
    sc_lv<4> or_op = "0001";
    sc_lv<4> add = "0010";
    sc_lv<4> subtract_not_equal = "0011";
    sc_lv<4> subtract = "0110";
    sc_lv<4> set_on_less_than = "0111";

    SC_CTOR(alu_control)
    {
        SC_METHOD(control);
        sensitive << funct << alu_op;
    }

    void control()
    {
        if(alu_op.read() == "00" || (alu_op.read() == "10" && funct.read() == "100000"))
            alu_control_fuct.write(add);
        else if(alu_op.read() == "01" || (alu_op.read() == "10" && funct.read() == "100010"))
            alu_control_fuct.write(subtract);
        else if(alu_op.read() == "11")
            alu_control_fuct.write(subtract_not_equal);
        else if(alu_op.read() == "10" and funct.read() == "100100")
            alu_control_fuct.write(and_op);
        else if(alu_op.read() == "10" && funct.read() == "100101")
            alu_control_fuct.write(or_op);
        else if(alu_op.read() == "10" && funct.read() == "101010")
            alu_control_fuct.write(set_on_less_than);
        else
            alu_control_fuct.write("0000");
    }
};