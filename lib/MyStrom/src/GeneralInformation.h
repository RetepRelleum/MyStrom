#ifndef GENERALINFORMATION
#define GENERALINFORMATION

#include "Strom.h"

class GeneralInformation : protected Strom {
public:
  GeneralInformation(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };
  String getVersion(){
    return getString("/api/v1/info","version");
  }
  String getMac(){
    return getString("/api/v1/info","mac");
  }
  byte getType(){
    return getByte("/api/v1/info","type");
  }
  String getSsid(){
    return getString("/api/v1/info","ssid");
  }
  String getIp(){
    return getString("/api/v1/info","ip");
  }
  String getMask(){
    return getString("/api/v1/info","mask");
  }
  String getGateway(){
    return getString("/api/v1/info","gateway");
  }
  String getDns(){
    return getString("/api/v1/info","dns");
  }
  bool getStatic(){
    return getBool("/api/v1/info","static");
  }
  bool getConnected(){
    return getBool("/api/v1/info","connected");
  }


};

#endif
