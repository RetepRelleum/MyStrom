
#include "GeneralRequests.h"

#include "GeneralInformation.h"
Client * GeneralRequests::www(String str){
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

String GeneralRequests::getString(String path,String key){

        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getStringJ(client,key);
        }
        return val;
}
String GeneralRequests::getString(String path,String key1,String key2){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }
        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getStringJ(client,key2);
        }
        return val;
}

float GeneralRequests::getFloat(String path,String key1,String key2){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }
        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getFloatJ(client,key2);
        }
        return val.toFloat();
}

String GeneralRequests::getList(String path,int index){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getListJ(client,index);
        }
        return val;
}

byte GeneralRequests::getByte(String path,String key){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key);
        }
        return (byte)val.toInt();
}
bool GeneralRequests::getBool(String path,String key){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key);
        }
        return val.equalsIgnoreCase("true");
}
bool GeneralRequests::getBool(String path,String key1,String key2){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getJsonJ(client,key1);
        }
        val="";
        data="";
        while (client->connected() && val.length()==0) {
                val=getByteJ(client,key2);
        }
        return val.equalsIgnoreCase("true");
}
float GeneralRequests::getFloat(String path,String key){
        String val="";
        client=  www(path);
        while (client->connected() && val.length()==0) {
                val=getFloatJ(client,key);
        }
        return val.toFloat();
}
GeneralRequests::GeneralRequests(Client * clientIn,  MyStromElement *myStromElementIn)
{
        client=clientIn;
        myStromElement=myStromElementIn;
};

GeneralInformation GeneralRequests::getGeneralInformation(){
        GeneralInformation generalInformation(client,myStromElement);
        return generalInformation;
};
