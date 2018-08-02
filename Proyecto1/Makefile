SYSTEMC_HOME=/usr/local/systemc-2.3.1/
all:
	g++ -I. -IContador -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim_counter Contador/Contador_test.cpp Contador/Contador.cpp -lsystemc
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim_alu ALU/alu_tb.cpp ALU/alu.cpp -lsystemc
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim_fsm FSM/FSM_tb.cpp FSM/FSM.cpp -lsystemc
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim_fp FP_ADD/FP_ADD_tb.cpp FP_ADD/FP_ADD.cpp -lsystemc
	g++ -I. -Itb -IRAM -I$(SYSTEMC_HOME)/include -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim_ram RAM/test_bench_RAM.cpp RAM/RAM.cpp RAM/tb.cpp -lsystemc
clean:
	rm sim_*
	rm *.vcd
