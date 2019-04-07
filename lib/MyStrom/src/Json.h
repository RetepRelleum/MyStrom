#ifndef JSON
#define JSON
#include <Arduino.h>
class Json {
protected:
String data;
String getStringJ(Stream *stream,String id);
String getByteJ(Stream *stream,String id);
String getFloatJ(Stream *stream,String id);
String getListJ(Stream *stream,int index);
String getJsonJ(Stream *stream,String id);
void addFirst(String id,String value){
        data="{\""+id+"\":\""+value+"\"";
};
void addNext(String id,int value){
        data+=",\""+id+"\":"+String(value);
}
void addNext(String id,bool value){
        data+=",\""+id+"\":"+(value?"true":"false");
}
void addEnd(){
        data+="}";
        Serial.println(data);
}
String getJsonString(){
        return data;
}
};

#endif
