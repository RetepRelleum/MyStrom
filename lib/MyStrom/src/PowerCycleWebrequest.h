#ifndef POWERCYCLEWEBREQUEST
#define POWERCYCLEWEBREQUEST

#include "Strom.h"

class PowerCycleWebrequest : protected Strom {
public:
  PowerCycleWebrequest(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };
  String getAddress(){
    return getString("/api/v1/monitor","address");
  }
};
#endif
