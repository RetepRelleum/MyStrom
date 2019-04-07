#ifndef STROM
#define STROM

#include <Client.h>
#include "MyStromElement.h"
#include "Json.h"


class Strom :protected Json {
protected:

Client * client;
MyStromElement *myStromElement;
Strom(Client * clientIn,  MyStromElement *myStromElementIn);
Client * get(String str);
void post(String path,String  data);
int getInt(String path,String key);
String getString(String path,String key);
String getString(String path,String key1,String key2);
byte getByte(String path,String key);
bool getBool(String path,String key);
bool getBool(String path,String key1,String key2);
float getFloat(String path,String key);
float getFloat(String path,String key1,String key2);
String getList(String path,int index);

};
#endif
