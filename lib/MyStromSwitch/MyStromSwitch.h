#ifndef MYSTROMSWITCH
#define MYSTROMSWITCH
#include "MyStromElement.h"
#include "Strom.h"
#include "Report.h"
#include "Temp.h"
#include "ScanWifi.h"
class MyStromSwitch : public Strom {
public:
MyStromSwitch(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
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

};

#endif
