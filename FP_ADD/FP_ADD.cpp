#include "systemc.h"

SC_MODULE(Fp_add){
	sc_in< sc_int<32> > A;
	sc_in< sc_int<32> > B;
	sc_out< sc_int<32> > out;

    void update_out(){
		float a,b,out_aux;
		int aux;

		aux=A.read();
		cout<<aux<<endl;
		a=*(float *)&(aux);
		aux=B.read();
		cout<<aux<<endl;
		b=*(float *)&(aux);
		out_aux=a+b;
		cout<<"Module: "<<a<<" "<<b<<" "<<out<<endl;
		out.write(*(int *)&out_aux);
	}

	SC_CTOR(Fp_add){
		SC_METHOD(update_out);
		sensitive << A;
		sensitive << B;
	}

};
