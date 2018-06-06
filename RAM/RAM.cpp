#include <systemc.h>
#include "RAM.h"

void RAM::Ram_escritura(void){
	if(chipselect.read() && write_enable.read()){
		mem[direccion.read()]= data_write.read();
	}

}

void RAM::Ram_lectura(void){
	if(chipselect.read() && !write_enable.read() && read.enable.read()){
		Output.write(mem[direccion.read()]);
	}
}