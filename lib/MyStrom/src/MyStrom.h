#ifndef MYSTROM
#define MYSTROM
#include "Client.h"
#include "Udp.h"
#include <Arduino.h>
#include "MyStromSwitch.h"
#include "MyStromElement.h"

enum elementType { SwitchCHv1=101,Bulb=102,ButtonP=103,Button=104,LEDstrip=105,SwitchCHv2=106,SwitchEU=107 };
class MyStrom {
protected:
Client * client;
UDP *udp;
int id;
MyStromElement *myStromElement;
void insertElement(MyStromElement *myStromElementIn);
public:
MyStromElement* getElement(){
        return myStromElement;
};
void setup(UDP *udpIn,Client * client);
void loop();
MyStromSwitch getMyStromSwitch(MyStromElement *myStromElementIn);
bool elementExist(){
        return ( myStromElement!=NULL);
}
void printAllElement();





};

#endif
