#ifndef JSON
#define JSON
#include <Arduino.h>
class Json {
protected:
String data;
public:
String getStringJ(Stream *stream,String id);
String getByteJ(Stream *stream,String id);
String getFloatJ(Stream *stream,String id);
};

#endif
