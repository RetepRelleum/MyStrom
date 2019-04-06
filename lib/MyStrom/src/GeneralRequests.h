#ifndef GENERALREQESTS
#define GENERALREQESTS


#include "MyStromElement.h"
#include "Strom.h"
#include "GeneralInformation.h"


class GeneralRequests :protected Strom {
public:
GeneralRequests(Client * clientIn,  MyStromElement *myStromElementIn): Strom(clientIn,myStromElementIn){};
GeneralInformation getGeneralInformation();
};

#endif
