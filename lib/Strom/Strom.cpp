
#include "Strom.h"
#include "Json.h"
#include "GeneralInformation.h"
Client * Strom::www(String str){
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
        Json json;
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=json.getString(client,key);
        }
        return val;
}

byte Strom::getByte(String path,String key){
        Json json;
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=json.getByte(client,key);
        }

        return (byte)val.toInt();
}
bool Strom::getBool(String path,String key){
        Json json;
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=json.getByte(client,key);
        }

        return val.equalsIgnoreCase("true");
}
Strom::Strom(Client * clientIn,  MyStromElement *myStromElementIn)
{
        client=clientIn;
        myStromElement=myStromElementIn;
};

GeneralInformation Strom::getGeneralInformation(){
  GeneralInformation generalInformation(client,myStromElement);
  return generalInformation;
};
