#include <systemc.h>
#include "RAM.h"
#define Ancho_dato	32
#define Direccion_ancho 4
#define numero_registros (1<<Direccion_ancho)

void RAM::Ram_escritura(void){
	if(chipselect.read() && write_enable.read()){
		mem[direccion.read()]= data_write.read();
	}

}

void RAM::Ram_lectura(void){
	if(chipselect.read() && !write_enable.read() && read_enable.read()){
		Output.write(mem[direccion.read()]);
	}
}
