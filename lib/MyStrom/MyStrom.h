#ifndef MYSTROM
#define MYSTROM
#include <Client.h>
#include <Udp.h>
#include <Arduino.h>

class MyStrom {
protected:
IPAddress ip;
Client * client;
Client * www(String str);
String info(String typ);
byte infoByte(String typ);


UDP *udp;
int id;
String item[2][20];

public:
String getIP(int id);
String getMac(int id);
void setItem(int id);
void setup(UDP *udpIn,Client * client);
void loop();
String getVersion();
String getMac();
byte getType();



};

#endif
