#include "systemc.h"
#include "systemc-ams.h"

SC_MODULE(filter){
	sca_eln::sca_terminal in, out;

	sca_eln::sca_node_ref gnd;

	sca_eln::sca_r *r1;
	sca_eln::sca_c *c1;

	SC_CTOR(filter){

		r1 = new sca_eln::sca_r("r1",16e2);
		r1->p(in);
		r1->n(out);

		c1= new sca_eln::sca_c("c1", 1e-9);
		c1->p(out);
		c1->n(gnd);
	}

};
