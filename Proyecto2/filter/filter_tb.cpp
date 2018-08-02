#include "systemc.h"
#include "systemc-ams.h"
#include "filter.cpp"


int sc_main (int argc, char* argv[]){
	sca_eln::sca_node in;
	sca_eln::sca_node out;


	sca_eln::sca_node_ref gnd;

	sca_eln::sca_vsource src("src",0.0, 0.0, 3.3, 1e9);
	src.set_timestep(1e-6, sc_core::SC_US);

	src.p(in);
	src.n(gnd);

	filter DUT_FILTER("filter_obj");
	DUT_FILTER.in(in);
	DUT_FILTER.out(out);

	//Comienza la simulacion
	sca_util::sca_trace_file *eln= sca_util::sca_create_vcd_trace_file("filter.vcd");
	sca_trace(eln, in, "Input_Analog");
	sca_trace(eln, out, "Output_Analog");

	sc_start(150, sc_core::SC_MS);

	sca_util::sca_close_vcd_trace_file(eln);


	return 0;


}