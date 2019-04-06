#ifndef TEMP
#define TEMP

#include "Strom.h"

class Temp : protected Strom {
public:
  Temp(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };
  float getMeasured(){
    return getFloat("/temp","measured");
  }
  float getCompensation(){
      return getFloat("/temp","compensation");
  }
  float getCompensated (){
    return getFloat("/temp","compensated");
  }
};
#endif
