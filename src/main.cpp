
#include <SPI.h>
#include <arduino_secrets.h>
#include <MyStrom.h>
#include <WiFi101.h>
#include <WiFiUdp.h>

int keyIndex = 0;            // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

MyStrom myStrom;
WiFiUDP udp;
WiFiClient client;

void printWifiStatus() {
        // print the SSID of the network you're attached to:
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID());

        // print your WiFi shield's IP address:
        IPAddress ip = WiFi.localIP();
        Serial.print("IP Address: ");
        Serial.println(ip);

        // print the received signal strength:
        long rssi = WiFi.RSSI();
        Serial.print("signal strength (RSSI):");
        Serial.print(rssi);
        Serial.println( " dBm");
}

void setup() {
        //Initialize serial and wait for port to open:
        Serial.begin(115200);
        while (!Serial) {
        }
        if (WiFi.status() == WL_NO_SHIELD) {
                Serial.println(   "WiFi shield not present");
                while (true);
        }
        String fv = WiFi.firmwareVersion();
        Serial.print("Firmware Version: ");
        Serial.println( fv);
        // attempt to connect to Wifi network:
        while (status != WL_CONNECTED) {
                Serial.print("Attempting to connect to SSID: ");
                Serial.println(   ssid);
                // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
                status = WiFi.begin(ssid, pass);

                // wait 10 seconds for connection:
                while (WiFi.status()!=WL_CONNECTED) {
                        delay(10);
                }
        }
        Serial.println(   "Connected to wifi");
        printWifiStatus();
        myStrom.setup(&udp,&client);
}
unsigned long t=0;

void loop() {

        myStrom.loop();
        if (millis()-t>10000) {
                t=millis()-1;
                if(myStrom.elementExist()) {
                        myStrom.printAllElement();
                        MyStromSwitch myStromSwitch(&client, myStrom.getElement());
                        myStromSwitch.getGeneralInformation().getVersion();
                        myStromSwitch.getGeneralInformation().getMac();

                        myStromSwitch.getGeneralInformation().getType();

                        myStromSwitch.getGeneralInformation().getSsid();

                        myStromSwitch.getGeneralInformation().getIp();

                        myStromSwitch.getGeneralInformation().getMask();

                        myStromSwitch.getGeneralInformation().getDns();

                        myStromSwitch.getGeneralInformation().getStatic();

                        myStromSwitch.getGeneralInformation().getConnected();
                        myStromSwitch.getConnectToWifi().set(ssid,pass);
                        //      myStromSwitch.turnOn();
                        //      myStromSwitch.turnOff();
                        //         myStromSwitch.toggle();
                        myStromSwitch.getReport().getPower();
                        myStromSwitch.getReport().getRelay();
                        myStromSwitch.getReport().getTemperature();
                        myStromSwitch.getTemp().getMeasured();
                        myStromSwitch.getTemp().getCompensation();

                        /*           myStromSwitch.getScanWifi().getName(0) );
                                   myStromSwitch.getScanWifi().getName(myStromSwitch.getScanWifi().getName(0)));
                                   myStromSwitch.getScanWifi().getSignal(myStromSwitch.getScanWifi().getName(0)));
                                   myStromSwitch.getScanWifi().getEncryptionOn(myStromSwitch.getScanWifi().getName(0)));
                                   myStromSwitch.getScanWifi().getEncryption(myStromSwitch.getScanWifi().getName(0)));
                         */
                        //   myStromSwitch.getPowerCycle(2);
                        myStromSwitch.getPowerCycleWebrequest().getAddress();
                        myStromSwitch.getPowerCycleWebrequest().getTryAt();
                        myStromSwitch.getPowerCycleWebrequest().getAttempts();
                        myStromSwitch.getPowerCycleWebrequest().getInhibitTime();
                        myStromSwitch.getPowerCycleWebrequest().getPingTimeout();
                        myStromSwitch.getPowerCycleWebrequest().getRelayOffTime();
                        myStromSwitch.getPowerCycleWebrequest().getEnable();

                      //  myStromSwitch.getPowerCycleWebrequest().cyclefoff();
                                 myStromSwitch.getPowerCycleWebrequest().set("www.bluewin.ch", true);
                      //  myStromSwitch.getPowerCycledAdvanced().set(off,0);

                }
        }
}
