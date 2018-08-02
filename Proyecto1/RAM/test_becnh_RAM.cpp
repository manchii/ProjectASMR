#include <systemc.h>
#include "RAM.h"
#include "tb.h"

#define Ancho_dato	32
#define Direccion_ancho 4
#define numero_registros (1<<Direccion_ancho)


SC_MODULE( SYSTEM){
	tb	*tb0;
	RAM *RAM0;


	sc_signal< sc_uint<Direccion_ancho> > ;
	sc_signal< bool > chipselect;
	sc_signal< bool > write_enable;
	sc_signal< bool > read_enable;
	sc_signal< sc_uint<Ancho_dato> > data_write;
	sc_signal< sc_uint<Ancho_dato> > Output;


	sc_clock clk_sig;


	SC_CTOR(SYSTEM)
		: clk_sig("clk_sig", 10, SC_NS){
			tb0 = new tb("tb0");
			tb0 -> clk(clk_sig);
			tb0 -> Output(Output);
			tb0 -> chipselect(chipselect);
			tb0 -> write_enable(write_enable);
			tb0 -> read_enable(read_enable);
			tb0 -> data_write(data_write);
			 

			RAM0 = new RAM("RAM0");
			RAM0 -> clk(clk_sig);
			RAM0 -> Output(Output);
			RAM0 -> chipselect(chipselect);
			RAM0 -> write_enable(write_enable);
			RAM0 -> read_enable(read_enable);
			RAM0 -> data_write(data_write);
			 

		}
	~SYSTEM(){
		delete tb0;
		delete RAM0;
	} 
};

int sc_main( int argc, char* argv[] ) 
{
  SYSTEM *top = NULL;
  top = new SYSTEM("top");
  sc_start();
  
  return 0;
}
  
