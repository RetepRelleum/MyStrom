#include "GeneralRequests.h"




GeneralInformation GeneralRequests::getGeneralInformation(){
        GeneralInformation generalInformation(client,myStromElement);
        return generalInformation;
};
