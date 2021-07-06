#include "systemc.h"

SC_MODULE(sign_extend)
{
    sc_in<sc_lv<16>> x;
    sc_out<sc_lv<32>> y;

    SC_CTOR(sign_extend)
    {
        SC_METHOD(extender);
        sensitive << x;
    }

    void extender()
    {
        sc_lv<32> tmp;
        if (x.read()[15] == "1")
            tmp.range(31, 16) = "1111111111111111";
        else
            tmp.range(31, 16) = "0000000000000000";
        tmp.range(15, 0) = x.read();
        y.write(tmp);
    }
};