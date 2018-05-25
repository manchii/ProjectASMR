SYSTEMC_HOME=/usr/local/systemc-2.3.1/
all:
	g++ -I. -I$(SYSTEMC_HOME)/include -L. -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath=$(SYSTEMC_HOME)/lib-linux64 -o sim Contador_test.cpp Contador.cpp -lsystemc
