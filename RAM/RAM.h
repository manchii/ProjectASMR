#include <systemc.h>
SC_MODULE(Contador){
    sc_in <bool> en_write;
    sc_in <bool> en_read;
    sc_in <uint<32>> data_write;
    sc_in <uint<4>> direccion;
    sc_out <uint<32>> Salida;
}
