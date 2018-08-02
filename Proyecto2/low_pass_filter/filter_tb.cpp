#include "systemc.h"
#include "systemc-ams.h"
#include "filter.cpp"


int sc_main (int argc, char* argv[]){
	sca_eln::sca_node in;
	sca_eln::sca_node out;


	sca_eln::sca_node_ref gnd;

	sca_eln::sca_vsource src("src",0.0, 0.0, 3.3, 1e8);
	src.set_timestep(1e-4, sc_core::SC_US);

	src.p(in);
	src.n(gnd);

	filter DUT_FILTER("filter_obj");
	DUT_FILTER.in(in);
	DUT_FILTER.out(out);

	//Comienza la simulacion
	sca_util::sca_trace_file *eln= sca_util::sca_create_tabular_trace_file("filter.dat");
	sca_trace(eln, in, "Input_Analog");
	sca_trace(eln, out, "Output_Analog");

	//eln->disable();
	sc_start(1e-2, sc_core::SC_MS);
	//eln->enable();

	//sca_ac_start(1e3,1e9,1000,sca_ac_analysis::SCA_LOG);
	//ac_analysis->set_mode(sca_sampling(1.0,SC_US));
	
	//sca_util::sca_close_tabular_trace_file(ac_analysis);
	sca_util::sca_close_tabular_trace_file(eln);

	return 0;
}