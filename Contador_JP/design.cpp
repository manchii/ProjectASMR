#include "counter.h"

void counter12bits::indo_count(void) {
  
  //Reset
  //counter.write( 0 );
  //wait();
  if (rst.read() == 0) {
  	counter.write( 0 );
    count = 0;
  }
  
  else if (enable.read() == 1 && count_up.read() == 1 && count_down.read() == 0)   {
    count = count + 1;
    counter.write( count );
  }
  else if (enable.read() == 1 && count_down.read() == 1 && count_up.read() == 0)   {
    count = count - 1;
    counter.write( count );
  }
}

