#include "systemc.h"
#include "FP_ADD.cpp"


int sc_main(int argc, char* argv[]){

	sc_signal< sc_int<32> > A;
	sc_signal< sc_int<32> > B;
	sc_signal< sc_int<32> > out;

	//Connect the DUT
	Fp_add imp("fp_add");
	imp.A(A);
	imp.B(B);
	imp.out(out);

	//Comienza la simulacion
	sc_start(1, SC_NS);

	//Abrir VCD file
	sc_trace_file *wf = sc_create_vcd_trace_file("fp");
	sc_trace(wf,A,"A");
	sc_trace(wf,B,"B");
	sc_trace(wf,out,"out");

	int i = 0;
	float aux=0;
	//Inicializo variables
	
	A=*(int *)&aux;
	B=*(int *)&aux;
	
    sc_start(1, SC_NS);
	aux=1;
	A=*(int *)&aux;
	B=0;
    sc_start(1, SC_NS);

	sc_close_vcd_trace_file(wf);
  	return 0;// Terminate simulation
}
