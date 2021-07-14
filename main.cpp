#include "systemc.h"

#include "instruction_memory.h"
#include "adder.h"

int sc_main(int argc, char* argv[]){

    // instruction_memory test (NOT WORKING!!!) # TODO

    /* 
    sc_signal<sc_lv<32>> read_addres, instruction, last_instr_address;

    instruction_memory *im = new instruction_memory("im");
    (*im)(read_addres, instruction, last_instr_address);

    read_addres = 0;
    instruction = 0;
    last_instr_address = 0;

    sc_start(1, SC_NS);

    for(auto &data : im->data_mem)
    {
        cout << data << endl;
    }
    */
    

   // adder test (working)

   /* 
    sc_signal<sc_lv<32>> x, y, z;

    adder *a = new adder("adder1");
    (*a)(x, y, z);

    x = 1;
    y = 1;
    z = 0;

    sc_start(1, SC_NS);

    cout << a->z;
    */

   //alu_coontrol test
   

    return 0;
}