#include "systemc.h"

template <int n1 = 32, int n2 = 32, int k = 2>
SC_MODULE(shifter)
{
    sc_in<sc_lv<n1>> x;
    sc_out<sc_lv<n2>> y;

    SC_CTOR(shifter)
    {
        SC_METHOD(shift);
        sensitive << x;
    }

    void shift()
    {
        y.write(x.read() << k);
    }
};