#include "tb.h"
#define Ancho_dato	32
#define Direccion_ancho 4
#define numero_registros (1<<Direccion_ancho)

void tb::source() {
	//Abre el archivo VCD con nombre RAM
	sc_trace_file *wf = sc_create_vcd_trace_file("RAM");
	//Señales que se veran
	sc_trace(wf, clk, "clk");
	sc_trace(wf, Output, "Output");
	sc_trace(wf, chipselect, "chipselect");
	sc_trace(wf, write_enable, "write_enable");
	sc_trace(wf, read_enable, "read_enable");
	sc_trace(wf, data_write, "data_write");
	sc_trace(wf,  direccion, " direccion");

	//Valores iniciales
	chipselect.write(0);
	write_enable.write(0);
	read_enable.write(0);
	data_write.write(0);
	direccion.write(0);
	wait(2);

	//Escritura Registros
	chipselect.write(1);
	write_enable.write(1);
	for( int i =0; i<16; i++){
		direccion.write(i);
		data_write.write(i);
		wait();
	}

	//Lectura Regsitros
	write_enable.write(0);
	read_enable.write(1);
	for( int i =0; i<16 ; i++){
		direccion.write(i);
		wait();
	}	
}

void tb::sink() {
	sc_uint<32> Salidas;
	for( int i = 0; i<100; i++) {
  		Salidas = Output.read();
   		wait();
    	cout << i << " :\t" << Salidas.to_uint() << endl;
	}
	sc_stop();
}
