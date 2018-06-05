#include "systemc.h"

SC_MODULE (alu){
	sc_in_clk  clk;
	sc_in<sc_int<16> > A;
	sc_in<sc_int<16> > B;
	sc_in<sc_int<4> > op;
	sc_out<bool> overflow;
	sc_out<bool> carry;
	sc_out<sc_int<16> > result;

	sc_int<16> dataA, dataB;
	sc_int<32> res; 

	bool overflow_detec(sc_int<32> val){
		if(val>=65536 || val <= -32768){
			return true;
		}
		else{
			return false;
		}
	}

	void operate(){
		overflow = false;
		carry = false;
		dataA = A.read();
		dataB = B.read();

		switch(op.read()){
			case 0:
				res = dataA + dataB;
				overflow = overflow_detec(res);
				break;

			case 1:
				res = dataA + dataB;
				overflow = overflow_detec(res);
				break;

			case 2:
				res = dataA * dataB;
				overflow = overflow_detec(res);
				break;

			case 3:
				res = dataA / dataB;
				overflow = overflow_detec(res);
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
		cout<<"@" << sc_time_stamp() <<" :: Resultado " <<result.read()<<endl;


	}

	SC_CTOR(alu) {
	    cout<<"Executing new"<<endl;
	    SC_METHOD(operate);
	    sensitive << clk.pos();
	  } // End of Constructor
};
