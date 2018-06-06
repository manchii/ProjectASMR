#include <systemc.h>

SC_MODULE(tb){
	sc_in <bool> clk;
	sc_in <sc_uint<Ancho_dato>> Output;
	sc_out <bool> chipselect;
	sc_out <bool>	write_enable;
    sc_out <bool>	read_enable;
    sc_out <sc_uint<Ancho_dato>> data_write;
    sc_out <sc_uint<32>> direccion;


	void source();
	void sink();

	SC_CTOR(tb) {
		SC_CTHREAD( source, clk.pos() );
		SC_CTHREAD( sink, clk.pos() );

	}
};