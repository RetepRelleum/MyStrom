#ifndef SCANWIFI
#define SCANWIFI


#include "Strom.h"

class ScanWifi : protected Strom {
public:
ScanWifi(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
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
