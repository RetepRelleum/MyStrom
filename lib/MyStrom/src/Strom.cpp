
#include "Strom.h"
#include "Debug.h"


void Strom::post(String str,String dat){
  debug_print(str);
  debug_print("  ");
  debug_println(dat);
        if (client->connect(myStromElement->getIpAddress(), 80)) {
                client->println("POST "+str+" HTTP/1.1");
                client->println("Content-Type: application/x-www-form-urlencoded");
                client->println("Content-length: " +String( dat.length()+2));
                client->println("Connection: close");
                client->println();
                client->println();
                client->println(dat);
                client->stop();
        }
}
Client * Strom::get(String str){
        String c="close";
        if (client->connect(myStromElement->getIpAddress(), 80)) {
                client->println("GET "+str+" HTTP/1.1");
                client->println(c);
                client->println();
        }
        String data="";
        while (client->connected()) {
                if (client->available()) {
                        data=data+(char)client->read();
                        if (data.length()>c.length()) {
                                data=data.substring(1);
                        }
                        if (data.equalsIgnoreCase(c)) {
                                return client;
                        }
                }
        }
        return client;
}

String Strom::getString(String path,String key){
        String val="";
        client=  get(path);
        debug_print(path+" "+key);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getStringJ(client,key);
        }
        debug_println(val);
        return val;
}
String Strom::getString(String path,String key1,String key2){
        String val="";
        client=  get(path);
        debug_print(path+" "+key1+" "+key2);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }
        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getStringJ(client,key2);
        }
        debug_println(val);
        return val;
}

float Strom::getFloat(String path,String key1,String key2){
        String val="";
        client=  get(path);
        debug_print(path+" "+key1+" "+key2);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }
        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getFloatJ(client,key2);
        }
        debug_println(val);
        return val.toFloat();
}

String Strom::getList(String path,int index){
        String val="";
        client=  get(path);
        debug_print(path+" "+index);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getListJ(client,index);
        }
        debug_println(val);
        return val;
}

byte Strom::getByte(String path,String key){
        String val="";
        client=  get(path);
        debug_print(path+" "+key);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key);
        }

        debug_println(val);
        return (byte)val.toInt();
}

int Strom::getInt(String path,String key){
        String val="";
        client=  get(path);
        debug_print(path+" "+key);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key);
        }
        debug_println(val);
        return (byte)val.toInt();
}

bool Strom::getBool(String path,String key){
        String val="";
        client=  get(path);
        debug_print(path+" "+key);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key);
        }
        debug_println(val);
        return val.equalsIgnoreCase("true");
}
bool Strom::getBool(String path,String key1,String key2){
        String val="";
        client=  get(path);
        debug_print(path+" "+key1+" "+key2);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }

        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key2);
        }
        debug_println(val);
        return val.equalsIgnoreCase("true");
}
float Strom::getFloat(String path,String key){
        String val="";
        client=  get(path);
        debug_print(path+" "+key);
        debug_print("\t: ");
        while (client->connected() && val.length()==0) {
                val=getFloatJ(client,key);
        }
        debug_println(val);
        return val.toFloat();
}
Strom::Strom(Client * clientIn,  MyStromElement *myStromElementIn)
{
        client=clientIn;
        myStromElement=myStromElementIn;
};
