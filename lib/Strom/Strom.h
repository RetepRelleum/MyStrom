#ifndef STROM
#define STROM

#include <Client.h>
#include "MyStromElement.h"
#include "Json.h"

class GeneralInformation;
class Strom :protected Json {
protected:
Client * client;
MyStromElement *myStromElement;
Client * www(String str);
String getString(String path,String key);
String getString(String path,String key1,String key2);
byte getByte(String path,String key);
bool getBool(String path,String key);
bool getBool(String path,String key1,String key2);
float getFloat(String path,String key);
float getFloat(String path,String key1,String key2);
String getList(String path,int index);
public:
Strom(Client * clientIn,  MyStromElement *myStromElementIn);
GeneralInformation getGeneralInformation();
};

#endif
