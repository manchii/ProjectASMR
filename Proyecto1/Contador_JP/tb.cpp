#include "tb.h"

void tb::source() {
  
  // Open VCD file
  sc_trace_file *wf = sc_create_vcd_trace_file("counter");
  // Dump the desired signals
  sc_trace(wf, clk, "clk");
  sc_trace(wf, rst, "rst");
  sc_trace(wf, enable, "enable");
  sc_trace(wf, count_up, "count_up");
  sc_trace(wf, count_down, "count_down");
  sc_trace(wf, counter, "counter");
  
  // Reset sequence
  count_up.write( 0 );
  count_down.write( 0 );
  enable.write( 0 );
  rst.write( 0 );
  wait(2);
  rst.write( 1 );
  wait();
  
  enable.write( 1);
  
  for( int i = 0; i< 10; i++) {
  	count_up.write(1);
    wait();
  }
  
  // Reset to count doiwn
  
  rst.write(0);
  wait();
  count_up.write(0);
  rst.write(1);
  
  for( int j = 0; j<10; j++) {
  	count_down.write(1);
    wait();
  }
  
  // End of sequence
  count_down.write(0);
  
  sc_close_vcd_trace_file(wf);
}

void tb::sink() {
  
  sc_uint<12>	counter_out;
  
  for( int i = 0; i<100; i++) {
  	counter_out = counter.read();
    wait();
    
    //Display read value
    cout << i << " :\t" << counter_out.to_uint() << endl;
  }
  
  sc_stop();
}