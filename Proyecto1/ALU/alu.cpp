#include "systemc.h"

SC_MODULE (alu){
	sc_in_clk  clk;
	sc_in<sc_int<16> > A;
	sc_in<sc_int<16> > B;
	sc_in<sc_uint<4> > op;
	sc_out<sc_int<1> > overflow;
	sc_out<sc_int<1> > carry;
	sc_out<sc_int<16> > result;

	sc_int<16> dataA, dataB;
	sc_int<32> res; 
	sc_int<1> bandera; 


	void operate(){
		bandera = 0;
		dataA = A.read();
		dataB = B.read();
		res = 0;
		switch(op.read()){
			case 0:
				res = dataA + dataB;
				if(res>=32767 || res <= -32767){
					bandera = 1;
				}
				else{
					bandera = 0;
				}
				break;

			case 1:
				res = dataA - dataB;
				if(res>=32767 || res <= -32767){
					bandera = 1;
				}
				else{
					bandera = 0;
				}
				break;

			case 2:
				res = dataA * dataB;
				if(res>=32767 || res <= -32767){
					bandera = 1;
				}
				else{
					bandera = 0;
				}
				break;

			case 3:
				res = dataA / dataB;
				if(res>=32767 || res <= -32767){
					bandera = 1;
				}
				else{
					bandera = 0;
				}
				break;

			case 4:
				res = dataA & dataB;
				break;

			case 5:
				res = dataA | dataB;
				break;

			case 6:
				res = dataA ^ dataB;
				break;

			case 7:
				res = dataA >> dataB;
				break;

			case 8:
				res = dataA << dataB;
				break;

			case 9:
				res = ~dataA;
				break;

		}
		result.write(res);
		overflow.write(bandera);
		carry.write(bandera);
		cout<<"@" << sc_time_stamp() <<" :: OP " <<op.read()<<endl;
		cout<<"@" << sc_time_stamp() <<" :: Resultado " <<result.read()<<endl;


	}

	SC_CTOR(alu) {
	    cout<<"Executing new"<<endl;
	    SC_METHOD(operate);
	    sensitive << clk.pos();
	  } // End of Constructor
};
