#ifndef TEMP
#define TEMP

#include "GeneralRequests.h"

class Temp : public GeneralRequests {
public:
  Temp(Client * clientIn,  MyStromElement *myStromElementIn) : GeneralRequests(clientIn,myStromElementIn){
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
