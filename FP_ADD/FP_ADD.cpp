#include "systemc.h"

SC_MODULE(Fp_add){
	sc_in< sc_int<32> > A;
	sc_in< sc_int<32> > B;
	sc_out< sc_int<32> > out;

    void update_out(){
		float a,b,out_aux;
		int aux1,aux2;

		aux1=A.read();
		a=*(float *)&(aux1);
		cout<<a<<endl;
		aux2=B.read();
		b=*(float *)&(aux2);
		cout<<b<<endl;
		out_aux=a+b;
		
		out.write(*(int *)&out_aux);
		cout<<"Module: "<<a<<" "<<b<<" "<<out_aux<<endl;
	}

	SC_CTOR(Fp_add){
		SC_METHOD(update_out);
		sensitive << A;
		sensitive << B;
	}

};
