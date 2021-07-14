#include "systemc.h"

SC_MODULE(data_memory)
{
    //ports
    sc_in<sc_lv<32>> address, write_data;
    sc_in<sc_logic> MemWrite, MemRead;
    sc_in_clk ck;
    sc_out<sc_lv<32>> read_data;

    //memory array
    sc_lv<32> data_mem[32] =   
                {0x00000000,    // initialize data memory
                0x00000000,     // mem 1
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,     // mem 10
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,     // mem 20
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,
                0x00000000,     // mem 30
                0x00000000};
                                
    SC_CTOR(data_memory)
    {
        SC_METHOD(read);
        sensitive << address << MemRead;

        SC_METHOD(write);
        sensitive << address << write_data << ck.neg();
    }

    void read()
    {
        if(MemRead.read() == SC_LOGIC_1)
            read_data.write(data_mem[address.read().range(6, 2).to_uint()]);
        else
            read_data.write(0x00000000);
    
    }

    void write(){
        if(MemWrite.read() == SC_LOGIC_1)
            data_mem[address.read().range(6, 2).to_uint()] = write_data.read();
    }   
};