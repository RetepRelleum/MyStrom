#include "GeneralRequests.h"




GeneralInformation GeneralRequests::getGeneralInformation(){
        GeneralInformation generalInformation(client,myStromElement);
        return generalInformation;
};


ConnectToWifi GeneralRequests::getConnectToWifi(){
        ConnectToWifi connectToWifi(client,myStromElement);
        return connectToWifi;
};
