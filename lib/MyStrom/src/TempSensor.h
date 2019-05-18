#ifndef TEMPSENSOR
#define TEMPSENSOR




class TempSensor {
public:
        float getTemp(){
                float u=4095-analogRead(A1);
                float t=2.21695173665753E-12*pow(u,4)-1.4898948032228E-8*pow(u,3)+3.35530285881761E-5*pow(u,2)-0.004907011483436*u-15.8643403470491;
                Serial.print("temp :");
                Serial.println(t);
                return t;
        }
};


#endif
