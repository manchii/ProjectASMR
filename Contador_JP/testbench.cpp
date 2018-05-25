#include <systemc.h>
#include "counter.h"
#include "tb.h"

SC_MODULE ( SYSTEM ) {
  tb 							*tb0;
  counter12bits 				*c0;
  
  sc_signal< bool >				rst_sig;
  sc_signal< bool > 			enable_sig;
  sc_signal< bool > 			count_up_sig;
  sc_signal< bool > 			count_down_sig;
  sc_signal< sc_uint<12> > 		counter_sig;
  
    
  sc_clock						clk_sig;
  
  SC_CTOR( SYSTEM )
  	: clk_sig ("clk_sig", 10, SC_NS) 
  {
      tb0 = new tb("tb0");
      tb0 -> clk( clk_sig );
      tb0 -> rst( rst_sig );
      tb0 -> enable( enable_sig);
      tb0 -> count_up( count_up_sig );
      tb0 -> count_down( count_down_sig );
      tb0 -> counter( counter_sig );
      
      
      c0 = new counter12bits("c0");
      c0 -> clk( clk_sig );
      c0 -> rst( rst_sig );
      c0 -> enable( enable_sig);
      c0 -> count_up( count_up_sig );
      c0 -> count_down( count_down_sig );
      c0 -> counter( counter_sig );
     
      
  }
  
  ~SYSTEM() {
    delete tb0;
    delete c0;
  }
};




int sc_main( int argc, char* argv[] ) 
{
  SYSTEM *top = NULL;
  top = new SYSTEM("top");
  sc_start();
  
  return 0;
}
  