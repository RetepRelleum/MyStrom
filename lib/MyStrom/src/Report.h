#ifndef REPORT
#define REPORT

#include "GeneralRequests.h"

class Report : public GeneralRequests {
public:
  Report(Client * clientIn,  MyStromElement *myStromElementIn) : GeneralRequests(clientIn,myStromElementIn){
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
