#ifndef JSON
#define JSON
#include <Arduino.h>
class Json {
protected:
String data;
public:
String getString(Stream *stream,String id);
String getByte(Stream *stream,String id);
};

#endif
