
#include <Json.h>




String Json::getString(Stream *stream,String id){
       String ret;
        while (stream->available()) {
                data.concat( char(stream->read()));
                if (data.length()>id.length()) {
                        data=data.substring(1);
                }
                if(data.equalsIgnoreCase(id)) {
                        data="";
                        while(stream->available()) {
                                char a=   char(stream->read());
                                data.concat(a);
                                if(data.endsWith("\",")) {
                                        ret=data.substring(3,data.length()-2);
                                        data="";
                                        return ret;
                                }
                        }
                }
        }
        return "";
}



String Json::getByte(Stream *stream,String id){
     String ret;
     id=id+"\":";
        while (stream->available()) {
                data.concat( char(stream->read()));
                if (data.length()>id.length()) {
                        data=data.substring(1);
                }
                if(data.equalsIgnoreCase(id)) {
                        data="";
                        while(stream->available()) {
                                char a=   char(stream->read());
                                data.concat(a);
                                if(data.endsWith(",")) {
                                  ret=data.substring(0,data.length()-1);
                                  data="";
                                  Serial.print(ret);
                                        return ret;
                                }
                        }
                }
        }
        return "";
}
