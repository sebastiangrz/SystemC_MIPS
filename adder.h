#include "systemc.h"

SC_MODULE(adder)
{
    //ports
    sc_in<sc_lv<32>> x, y;
    sc_out<sc_lv<32>> z;

    SC_CTOR(adder)
    {
        SC_METHOD(add);
        sensitive << x << y;
    }

    void add()
    {
        z.write(x.read().to_int() + y.read().to_int());
    }
};