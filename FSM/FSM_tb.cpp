#include "systemc.h"
#include "FSM.cpp"


int sc_main(int argc, char* argv[]){

	sc_signal<bool> clk;

	sc_signal< sc_int<32> > f_cond;
	sc_signal<bool> rst;

	sc_signal< sc_int<32> > state_out;

	//Connect the DUT
	Fsm_ex imp("fsm");
	imp.clk(clk);
	imp.f_cond(f_cond);
	imp.rst(rst);
	imp.state_out(state_out);

	//Comienza la simulacion
	sc_start(1, SC_NS);

	//Abrir VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("fsm");
	sc_trace(wf,clk,"clk");
	sc_trace(wf,f_cond,"f_cond");
	sc_trace(wf,rst,"rst");
	sc_trace(wf,state_out,"state_out");

	int i = 0;

	//Inicializo variables
	rst=0;
	f_cond=0;
	for (i=0;i<1;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}

	rst=1;
	for (i=0;i<1;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}
	rst=0;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}
	f_cond=1;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}
	f_cond=0;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}
	sc_close_vcd_trace_file(wf);
  	return 0;// Terminate simulation
}
