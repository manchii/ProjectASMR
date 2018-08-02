#include <systemc.h>

SC_MODULE(tb)
{
  sc_in< bool >					clk;
  sc_out< bool >				rst;
  sc_out< bool >				enable;
  sc_out< bool >				count_up;
  sc_out< bool >				count_down;
  
  sc_in< sc_uint<12> >			counter;
  
  void source();
  void sink();
  
  SC_CTOR(tb) {
    
    SC_CTHREAD( source, clk.pos() );
	SC_CTHREAD( sink, clk.pos() );
  }
};