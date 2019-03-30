#ifndef SCANWIFI
#define SCANWIFI

#include "Strom.h"

class ScanWifi : public Strom {
public:
  ScanWifi(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };
  String getName(int index){
    return getList("/networks",index);
  }
};
#endif
