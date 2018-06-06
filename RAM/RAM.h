#include <systemc.h>
#define Ancho_dato	32
#define Direccion_ancho 4
#define numero_registros 1 << Direccion_ancho

SC_MODULE(RAM){
    sc_in <sc_uint<Direccion_ancho>> direccion;
    sc_in <bool>	chipselect;
    sc_in <bool>	write_enable;
    sc_in <bool>	read_enable;
    sc_in <sc_uint<Ancho_dato>> data_write;
    sc_out <sc_uint<Ancho_dato>> Output;
    
    //Variable internas

    sc_uint <Ancho_dato> mem [numero_registros];

    void Ram_escritura();
    void Ram_lectura();
    
     SC_CTOR(RAM){
        SC_METHOD(Ram_escritura);
        	sensitive << chipselect << write_enable << data_write;
		SC_METHOD(Ram_lectura); 
			sensitive << direccion << chipselect << write_enable << read_enable;       
    }
    
    
};
    
    
