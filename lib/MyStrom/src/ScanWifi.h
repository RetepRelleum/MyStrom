#ifndef SCANWIFI
#define SCANWIFI


#include "GeneralRequests.h"

class ScanWifi : public GeneralRequests {
public:
ScanWifi(Client * clientIn,  MyStromElement *myStromElementIn) : GeneralRequests(clientIn,myStromElementIn){
};
String getName(int index){
        return getList("/networks",index);
}
String getName(String name){
        return getString("/networks",name,"name");
}
float getSignal(String name){
        return getFloat("/networks",name,"signal");
}
bool getEncryptionOn(String name){
        return getBool("/networks",name,"encryption-on");
}
String getEncryption(String name){
    return getString("/networks",name,"encryption");
}
};
#endif
