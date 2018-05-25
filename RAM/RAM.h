#include <systemc.h>
SC_MODULE(RAM){
    sc_in <bool> en_write;
    sc_in <bool> en_read;
    sc_in <uint<32>> data_write;
    sc_in <uint<4>> direccion;
    sc_out <uint<32>> Salida;
    
    void ram_func();
    
     SC_CTOR(RAM){
        SC_METHOD(ram_func);
            sensitive << en_write;
            sensitive << en_read;
            sensitive << direccion;
            sensitive << data_write;
    }
    
    
};
    
    
