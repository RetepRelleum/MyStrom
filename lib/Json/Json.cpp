
#include <Json.h>

String Json::getStringJ(Stream *stream,String id){
        String ret;
        id="\""+id+"\":";
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
                                if(data.endsWith(",")|| data.endsWith("}")) {
                                        ret=data.substring(1,data.length()-2);
                                        data="";
                                        return ret;
                                }
                        }
                }
        }
        return "";
}



String Json::getByteJ(Stream *stream,String id){
        String ret;
        id="\""+id+"\":";
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
                                if(data.endsWith(",")|| data.endsWith("}")) {
                                        ret=data.substring(0,data.length()-1);
                                        data="";
                                        return ret;
                                }
                        }
                }
        }
        return "";
}
String Json::getFloatJ(Stream *stream,String id){
        String ret;
        id="\""+id+"\":";
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
                                if(data.endsWith(",")|| data.endsWith("}")) {
                                        ret=data.substring(0,data.length()-1);
                                        data="";
                                        return ret;
                                }
                        }
                }
        }
        return "";
}
String Json::getListJ(Stream *stream,int index){
        String ret;
        id="\""+id+"\":";
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
                                if(data.endsWith(",")|| data.endsWith("}")) {
                                        ret=data.substring(0,data.length()-1);
                                        data="";
                                        return ret;
                                }
                        }
                }
        }
        return "";
}
