#ifndef MYSTROMSWITCH
#define MYSTROMSWITCH
#include "MyStromElement.h"
#include "Strom.h"
class MyStromSwitch : public Strom {
public:
MyStromSwitch(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
};
float getPower(){
  return getFloat("/report","power");
}
bool getRelay(){
    return getBool("/report","relay");
}
float getTemperature 
};

#endif
