#include <MyStrom.h>


void MyStrom::insertElement(MyStromElement *myStromElementIn){
        if (myStromElement==NULL) {
                myStromElement=myStromElementIn;
        }else{
                myStromElement->insert(myStromElementIn);
        }
}

void MyStrom::setup(UDP *udpIn, Client *clientIn){
        udp=udpIn;
        client =clientIn;
        udp->begin(7979);
}




MyStromSwitch MyStrom::getMyStromSwitch(MyStromElement *myStromElementIn){
        MyStromSwitch myStromSwitch(client,myStromElementIn);
        return myStromSwitch;

}




void MyStrom::loop(){
        String ret="";
        int packetSize = udp->parsePacket();
        if(packetSize) {
                IPAddress remoteIp = udp->remoteIP();
                String ip;
                String mac;
                byte macb[8];
                int type;
                ip=""+String(remoteIp[0])+"."+String(remoteIp[1])+"."+String(remoteIp[2])+"."+String(remoteIp[3]);
                udp->read(macb,8);
                for (size_t i = 0; i < 7; i++) {
                        mac.concat(String(macb[i],HEX));
                }
                type=macb[6];
                MyStromElement * myStromElementNew=new MyStromElement(remoteIp,mac,type);
                insertElement(myStromElementNew);

        }
}

void MyStrom::printAllElement(){
        MyStromElement *element;
        element=myStromElement;
        while(element!=NULL) {
                element->println();
                element=element->getNext();
        }
}
