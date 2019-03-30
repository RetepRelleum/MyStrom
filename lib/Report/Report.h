#ifndef REPORT
#define REPORT

#include "Strom.h"

class Report : public Strom {
public:
  Report(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };
  float getPower(){
    return getFloat("/report","power");
  }
  bool getRelay(){
      return getBool("/report","relay");
  }
  float getTemperature (){
    return getFloat("/report","temperature");
  }
};
#endif
