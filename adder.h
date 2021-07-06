#include "systemc.h"

SC_MODULE(adder)
{
    sc_in<sc_int<32>> x, y;
    sc_out<sc_int<32>> z;

    SC_CTOR(adder)
    {
        SC_METHOD(add);
        sensitive << x << y;
    }

    void add()
    {

        z.write(x.read() + y.read());
    }
};