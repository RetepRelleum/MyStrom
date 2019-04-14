#ifndef POWERCYCLEWEBREQUEST
#define POWERCYCLEWEBREQUEST

#include "Strom.h"

class PowerCycleWebrequest : protected Strom {
public:
PowerCycleWebrequest(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
};
void cyclefoff(){
  set(" ",false);
}
void set(String address="",bool enabled=0,int tryAt=1,int attempts=2,int inhibitTime=5,int pingTimeout=1,int relayOffTime=5){
        addFirst("address",address);
        addNext("tryAt",tryAt);
        addNext("attempts",attempts);
        addNext("inhibitTime", inhibitTime);
        addNext("pingTimeout", pingTimeout);
        addNext("relayOffTime", relayOffTime);
        addNext("enable", enabled);
        addEnd();
        post("/api/v1/monitor",getJsonString());
}
String getAddress(){
        return getString("/api/v1/monitor","address");
}
int getTryAt(){
        return getInt("/api/v1/monitor","tryAt");
}
int getAttempts(){
        return getInt("/api/v1/monitor","attempts");
}
int getInhibitTime(){
        return getInt("/api/v1/monitor","inhibitTime");
}
int getPingTimeout(){
        return getInt("/api/v1/monitor","pingTimeout");
}
int getRelayOffTime(){
        return getInt("/api/v1/monitor","relayOffTime");
}
bool getEnable(){
        return getBool("/api/v1/monitor","enabled");
}
};
#endif
