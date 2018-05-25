#include <systemc.h>

SC_MODULE ( counter12bits ) {
  sc_in< bool > 				clk;
  sc_in< bool >					rst;
  sc_in< bool >					enable;
  sc_in< bool >					count_up;
  sc_in< bool >					count_down;
  
  sc_out< sc_uint<12> >			counter;
  
  sc_uint<12>	count;
  
  void indo_count();
  
  SC_CTOR ( counter12bits) {
    SC_METHOD(indo_count);
    //reset_signal_is( rst, false );
    sensitive << rst.neg();
    sensitive << clk.pos();
  }
};