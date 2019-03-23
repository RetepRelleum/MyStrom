
#include <SPI.h>
#include <MyStrom.h>
#include <arduino_secrets.h>
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
        Serial.println(" dBm");
}

void setup() {
        //Initialize serial and wait for port to open:
        Serial.begin(115200);
        while (!Serial) {
        }
        if (WiFi.status() == WL_NO_SHIELD) {
                Serial.println("WiFi shield not present");
                while (true);
        }
        String fv = WiFi.firmwareVersion();
        Serial.print("Firmware Version: ");
        Serial.println(fv);
        // attempt to connect to Wifi network:
        while (status != WL_CONNECTED) {
                Serial.print("Attempting to connect to SSID: ");
                Serial.println(ssid);
                // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
                status = WiFi.begin(ssid, pass);

                // wait 10 seconds for connection:
                while (WiFi.status()!=WL_CONNECTED) {
                        delay(10);
                }
        }
        Serial.println("Connected to wifi");
        printWifiStatus();
        myStrom.setup(&udp,&client);
}
unsigned long t=0;
void loop() {
        myStrom.loop();
        if (millis()-t>10000) {
                t=millis()-1;
                if(myStrom.getIP(0).length()>0) {
                        Serial.println(  myStrom.getIP(0));
                        Serial.println(  myStrom.getMac(0));
                        myStrom.setItem(0);
                        Serial.println( myStrom.getType());
                        Serial.println( myStrom.getVersion());
                              Serial.println( myStrom.getMac());
                }

        }

}
