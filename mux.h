#include "systemc.h"

template <int n = 1>
SC_MODULE(mux)
{
    sc_in<sc_lv<n>> x, y;
    sc_in<sc_logic> s;
    sc_out<sc_lv<n>> z;

    SC_CTOR(mux)
    {
        SC_METHOD(mux);
        sensitive << x << y << s;
    }

    void mux()
    {
        if(s.read() == "0")
            z.write(x.read());
        else
            z.write(y.read());
    }
};