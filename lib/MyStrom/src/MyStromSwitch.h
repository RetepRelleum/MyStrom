#ifndef MYSTROMSWITCH
#define MYSTROMSWITCH
#include "GeneralRequests.h"
#include "MyStromElement.h"
#include "Report.h"
#include "Temp.h"
#include "ScanWifi.h"
#include "PowerCycleWebrequest.h"

class MyStromSwitch : public GeneralRequests {
public:
MyStromSwitch(Client * clientIn,  MyStromElement *myStromElementIn) : GeneralRequests(clientIn,myStromElementIn){
};
void turnOn(){
  www("/relay?state=1");
}
void turnOff(){
  www("/relay?state=0");
}
bool  toggle (){
    return getBool("/toggle","relay");
}
Report getReport(){
  Report report(client,myStromElement);
  return report;
}

Temp getTemp(){
  Temp temp(client,myStromElement);
  return temp;
}
ScanWifi getScanWifi(){
  ScanWifi scanWifi(client,myStromElement);
  return scanWifi;
}
void getPowerCycle (int time){
      String s="/power_cycle?time=";
      s=s+String(time);
    www(s);
}
PowerCycleWebrequest getPowerCycleWebrequest(){
  PowerCycleWebrequest powerCycleWebrequest(client,myStromElement);
  return powerCycleWebrequest;
}
};

#endif
