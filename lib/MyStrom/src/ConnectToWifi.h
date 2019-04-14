#ifndef CONNECTTOWIFI
#define CONNECTTOWIFI

#include "Strom.h"

class ConnectToWifi : protected Strom {
public:
  ConnectToWifi(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
  };

  void set(String ssid="",String passwd=""){
          addFirst("ssid",ssid);
          addNext("passwd",passwd);
          addEnd();
          post("/api/v1/connect",getJsonString());
  }

};

#endif
