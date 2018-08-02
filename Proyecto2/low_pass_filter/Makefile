CXX=g++

SYSTEMC_PATH=/usr/local/systemc-2.3.1
SYSTEMC_AMS_PATH=/usr/local/systemc-ams-2.1

MAIN=filter.cpp
TB=filter_tb.cpp
COMP=filter.o
COMP_TB=filter_tb.o
EXE=filter_tb.exe

INC=-I${SYSTEMC_PATH}/include -I${SYSTEMC_AMS_PATH}/include
LINK=ar -rcs libmodels.a
LIBDIR=-L${SYSTEMC_PATH}/lib-linux64 -L$(SYSTEMC_AMS_PATH)/lib-linux64
LIBS=-L. -o ${EXE} -lmodels -lsystemc-ams -lsystemc

all:
	${CXX} -c ${MAIN} ${INC}
	${LINK} ${COMP}
	${CXX} -c ${TB} ${INC}
	${CXX} ${COMP_TB} ${LIBDIR} ${LIBS}
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/systemc-ams-2.1/lib-linux64
	LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/systemc-2.3.1/lib-linux64/
	export LD_LIBRARY_PATH
	./${EXE}
	/usr/local/gaw/bin/gaw filter.dat