#include "systemc.h"

SC_MODULE(pc)
{
    //ports
    sc_in_clk ck;
    sc_in<sc_lv<32>> address_to_load;
    sc_out<sc_lv<32>> current_address;

    //signals
    sc_lv<32> address = "00000000000000000000000000000000";

    SC_CTOR(pc)
    {
        SC_METHOD(counter);
        sensitive << ck;
    }

    void counter()
    {
        current_address.write(address);

        if(ck.read == SC_LOGIC_0)
            address = address_to_load.read();
    }
};