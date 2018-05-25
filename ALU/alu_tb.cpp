#include "systemc.h"
#include "alu.cpp"

int sc_main(int argc, char* argv[]){
	sc_signal<bool> clk;
	sc_signal<sc_uint<16> > A;
	sc_signal<sc_uint<16> > B;
	sc_signal<sc_uint<4> > op;
	sc_signal<bool> overflow;
	sc_signal<bool> carry;
	sc_signal<sc_uint<16> > result;

	//Connect the DUT
	alu imp("ALU");
	imp.clk(clk);
	imp.A(A);
	imp.B(B);
	imp.op(op);
	imp.overflow(overflow);
	imp.carry(carry);
	imp.result(result);

	//Comienza la simulacion
	sc_start(1, SC_NS);

	//Abrir VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("alu");
	sc_trace(wf,clk,"clk");
	sc_trace(wf,A,"A");
	sc_trace(wf,B,"B");
	sc_trace(wf,op,"op");
	sc_trace(wf,overflow,"overflow");
	sc_trace(wf,carry,"carry");
	sc_trace(wf,result,"result");

	int i = 0;

	//Inicializo variables
	A=0;
	B=0;
	op=0;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}

	A=1000;
	B=3;
	op=2;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}

	A=48596;
	B=3;
	op=7;
	for (i=0;i<2;i++) {
	    clk = 0; 
	    sc_start(1, SC_NS);
	    clk = 1; 
	    sc_start(1, SC_NS);
	}

	sc_close_vcd_trace_file(wf);
  	return 0;// Terminate simulation
}