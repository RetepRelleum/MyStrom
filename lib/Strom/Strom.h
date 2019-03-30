#ifndef STROM
#define STROM

#include <Client.h>
#include "MyStromElement.h"
#include "Json.h"

class GeneralInformation;
class Strom :private Json {
protected:
Client * client;
MyStromElement *myStromElement;
Client * www(String str);
String getString(String path,String key);
byte getByte(String path,String key);
bool getBool(String path,String key);
float getFloat(String path,String key);
String getList(String path,int index);
public:
Strom(Client * clientIn,  MyStromElement *myStromElementIn);
GeneralInformation getGeneralInformation();
};

#endif
