#include "systemc.h"

SC_MODULE(control)
{
    //ports
    sc_in<sc_lv<6>> opcode;
    sc_out<sc_logic> reg_dest,jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
    sc_out<sc_lv<2>> alu_op;

    SC_CTOR(control)
    {
        SC_METHOD(doControl);
        sensitive << opcode;
    }

    void doControl()
    {

        if(opcode.read() == "000000")       //R-types
        {
            reg_dest.write(SC_LOGIC_1);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("10");
        }
        else if(opcode.read() == "001000")  //addi
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("00");
        }
        else if(opcode.read() == "000100")  //beq
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_1);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("01");
        }
        else if(opcode.read() == "000101")  //bne
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_1);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("11");
        }
        else if(opcode.read() == "000010")  //jump
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_1);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
        }
        else if(opcode.read() == "100011")  //lw
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_1);
            mem_to_reg.write(SC_LOGIC_1);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_1);
            alu_op.write("00");
        }
        else if(opcode.read() == "101011")  //sw
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_1);
            alu_src.write(SC_LOGIC_1);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
        }
        else                                //else
        {
            reg_dest.write(SC_LOGIC_0);
            jump.write(SC_LOGIC_0);
            branch.write(SC_LOGIC_0);
            mem_read.write(SC_LOGIC_0);
            mem_to_reg.write(SC_LOGIC_0);
            mem_write.write(SC_LOGIC_0);
            alu_src.write(SC_LOGIC_0);
            reg_write.write(SC_LOGIC_0);
            alu_op.write("00");
        }
    }
};