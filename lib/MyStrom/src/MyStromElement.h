#ifndef MYSTROMELEMENT
#define MYSTROMELEMENT
#include "IPAddress.h"
#include <Arduino.h>

class MyStromElement {
protected:
IPAddress ipAddress;
String macAddress;
int type;
MyStromElement *next=NULL;
public:
MyStromElement(IPAddress ipAddressIn,String macAddressIn,int typeIn){
        ipAddress=ipAddressIn;
        macAddress=macAddressIn;
        type=typeIn;
};
void insert(MyStromElement *myStromElement){
        if (myStromElement->getMacAddress().equals(macAddress)) {
                delete myStromElement;
        }else if (next==NULL) {
                next=myStromElement;
        }else{
                next->insert(myStromElement);
        }
}
int getType(){
        return type;
};
String getMacAddress(){
        return macAddress;
};
IPAddress getIpAddress(){
        return ipAddress;
};
void println(){
        Serial.print(getIpAddress());
        Serial.print(" ");
        Serial.print(getMacAddress());
        Serial.print(" ");
        Serial.println(getType());
};
MyStromElement* getNext(){
        return next;
}
};

#endif
