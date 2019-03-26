#ifndef STROM
#define STROM

#include <Client.h>
#include "MyStromElement.h"

class GeneralInformation;
class Strom {
protected:
Client * client;
MyStromElement *myStromElement;
Client * www(String str);
String getString(String path,String key);
byte getByte(String path,String key);
bool getBool(String path,String key);
public:
Strom(Client * clientIn,  MyStromElement *myStromElementIn);
GeneralInformation getGeneralInformation();
};

#endif
