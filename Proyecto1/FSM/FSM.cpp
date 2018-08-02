#include "systemc.h"


	enum flag {a,b};
	enum state_t {A,B,C,D,E};


SC_MODULE(Fsm_ex){
	sc_in_clk clk;
	sc_in< sc_int<32> > f_cond;
	sc_in<bool> rst;

	sc_out< sc_int<32> > state_out;

	sc_signal <sc_int<32> > state;
	

    void update_fsm(){

		if(rst.read()==true){
			state=A;
		}else{
			switch(state.read()){
				case A:
					if(f_cond.read()==a){
						state=B;
					}else{
						state=C;
					}
					break;
				case B:
					if(f_cond.read()==a){
						state=B;
					}else{
						state=D;
					}
					break;
				case C:
					if(f_cond.read()==a){
						state=B;
					}else{
						state=C;
					}

					break;
				case D:
					if(f_cond.read()==a){
						state=B;
					}else{
						state=E;
					}

					break;
				case E:
					if(f_cond.read()==a){
						state=B;
					}else{
						state=B;
					}

					break;
				default:
					state=A;
					break;	
			}
			
		}
		state_out.write(state);
		cout<<state<<endl;
	}

	SC_CTOR(Fsm_ex){
		SC_METHOD(update_fsm);
		sensitive << rst.pos();
		sensitive << clk.pos();
	}

};
