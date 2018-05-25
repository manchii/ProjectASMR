#include <systemc.h>

SC_MODULE(Contador){
    sc_in <bool> clk;
    sc_in <bool> Down;
    sc_in <bool> Reset;
    sc_in <bool> Enable;   
    sc_out < sc_uint<12> > Salida;
    
//-------------Local Variable---------------------------
    sc_unit<12>  count;
//------------Funcion-----------------------------------    
    void count_func();
    
//------------------Constructor---------------------
    SC_CTOR(Contador){
        SC_METHOD(count_func);
            reset_signal_is(Reset, false);
            sensitive << Reset.neg();
            sensitive << clk.pos();
    }
    
    
};
