#include <systemc.h>

SC_MODULE(Contador){
    sc_in <bool> clk;
    sc_in <bool> Down;
    sc_in <bool> Reset;
    sc_in <bool> Enable;   
    sc_out < sc_uint<12> > Salida;
    
//-------------Local Variable---------------------------
    sc_unit<12>  count;
    
    void count_func(){
    
        if(reset.read()==0){
            count=0;
            Salida.write(count);
        }
        else if(Enable.read()==1){
            if(Down==1){
                count=count-1;
                Salida.write(count);
            }
            else{
                count=count+1;
                Salida.write(count);
            }
        }
     
    }
    
    //------------------Constructor---------------------
    SC_CTOR(Contador){
        SC_METHOD(count_func);
            sensitive << reset.neg();
            sensitive << clock.pos();
    }
    
    
};
