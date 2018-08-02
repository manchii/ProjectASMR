#include <systemc.h>
#include <Contador.h>

void Contador::count_func(void){   
    if(Reset.read()==0){
        count=0;
        Salida.write(count);
    }
    else if(Enable.read()==1){
        if(Down==1){
            count=count-1;
            Salida.write(count);
        }
         else{
            count=count+1;
            Salida.write(count);
         }
     }
     
}
