#include <systemc.h>
#include "Contador.h"
#include "Contador.cpp"

int sc_main (int argc, char* argv[]) {
    sc_signal<bool>   clk;
    sc_signal<bool>   Reset;
    sc_signal<bool>   Enable;
    sc_signal<bool>   Down;
    sc_signal<sc_uint<4> > Salida;
    
    
//DUT
    Contador counter("COUNTER");
        counter.clk(clk);
        counter.Down(Down);
        counter.Reset(Reset);
        counter.Enable(Enable);
        counter.Salida(Salida);
     
    
    sc_start(1);
    //Open VCD FILE
    sc_trace_file *wf = sc_create_vcd_trace_file("counter");
    //Pone los traces para el VCD File
  
    sc_trace(wf, clk, "clk");
    sc_trace(wf, Reset, "Reset");
    sc_trace(wf, Enable, "Enable");
    sc_trace(wf, Salida, "Salida");
    
    //Valores Iniciales
    Reset=1; 
    Enable=0; 
    Down=0;
    
    
    
    //Crea el reloj
    for (i=0; i<5; i++){
        clk=0;
        sc_start(1);
        clk=1;
        sc_start(1);
    }
    
    Reset=0
    
    for (i=0; i<10; i++){
        clk=0;
        sc_start(1);
        clk=1;
        sc_start(1);
    }       
    Reset=1
    for (i=0; i<5; i++){
        clk=0;
        sc_start(1);
        clk=1;
        sc_start(1);
    }
    Enable=1
    for (i=0; i<5; i++){
        clk=0;
        sc_start(1);
        clk=1;
        sc_start(1);
    }
    Down=1
    for (i=0; i<10; i++){
        clk=0;
        sc_start(1);
        clk=1;
        sc_start(1);
    } 
    return 0;
}
