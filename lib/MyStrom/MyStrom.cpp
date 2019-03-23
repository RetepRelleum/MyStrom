#include <MyStrom.h>
#include <Json.h>

void MyStrom::setup(UDP *udpIn, Client *clientIn){
        udp=udpIn;
        client =clientIn;
        udp->begin(7979);
        for (size_t i = 0; i < 20; i++) {
                for (size_t ii = 0; i < 2; i++) {
                        item[ii][i]="";
                }
        }
}


Client * MyStrom::www(String str){
        String c="close";
        if (client->connect(ip, 80)) {
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

String MyStrom::info(String typ){
        Json json;
        String val="";
        client=  www("api/v1/info");
        while (client->connected() && val.length()==0) {
                val=json.getString(client,typ);
        }
        return val;
}

byte MyStrom::infoByte(String typ){
        Json json;
        String val="";
        client=  www("api/v1/info");
        while (client->connected() && val.length()==0) {
                val=json.getByte(client,typ);
        }
        return (byte)val.toInt();
}

String MyStrom::getVersion(){
        return info("version");
}

String MyStrom::getMac(){
        return info("mac");
}
byte MyStrom::getType(){
        return infoByte("type");
}

void MyStrom::loop(){
        String ret="";
        int packetSize = udp->parsePacket();
        if(packetSize) {
                IPAddress remoteIp = udp->remoteIP();
                String ip;
                String mac;
                byte macb[8];
                ip=""+String(remoteIp[0])+"."+String(remoteIp[1])+"."+String(remoteIp[2])+"."+String(remoteIp[3]);
                udp->read(macb,8);
                for (size_t i = 0; i < 8; i++) {
                        mac.concat(String(macb[i],HEX));
                }
                for (size_t i = 0; i < 20; i++) {
                        if (item[0][i].length()==0) {
                                item[0][i]=mac;
                                item[1][i]=ip;
                                break;
                        }
                        if (item[0][i].equals(mac)) {
                                return;
                        }
                }
                Serial.print("My Strom gefunden : ");
                Serial.print(ip);
                Serial.print(" ");
                Serial.println(mac);
        }
}

String MyStrom::getIP(int id){
        if (item[0][id].length()==0) {
                return "";
        }else{
                return item[1][id];
        }
}

String MyStrom::getMac(int id){
        if (item[0][id].length()==0) {
                return "";
        }else{
                return item[0][id];
        }
}

void MyStrom::setItem(int id){
        if (item[0][id].length()!=0) {
                ip.fromString(item[1][id]);
        }
}
