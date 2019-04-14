#ifndef POWERCYCLEADVANCD
#define POWERCYCLEADVANCD

#include "Strom.h"
enum mode {on,off,toggle};
class PowerCycledAdvanced : protected Strom {
public:
PowerCycledAdvanced(Client * clientIn,  MyStromElement *myStromElementIn) : Strom(clientIn,myStromElementIn){
};

void set(mode mode=on,int time=5){
        String mod="";
        switch (mode) {
        case on: mod="on"; break;
        case off: mod="off"; break;
        case toggle: mod="toggle"; break;
        }
        post("timer?mode="+mod+"&time="+String(time),"");
}

};

#endif
