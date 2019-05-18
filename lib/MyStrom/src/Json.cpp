
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
        int i=0;
        while (stream->available()) {
                data.concat( char(stream->read()));
                if (data.endsWith("\":{") && (i==index)) {
                        data=data.substring(data.indexOf("\"")+1);
                        data=data.substring(0,data.indexOf("\""));
                        return data;
                }
                if (data.endsWith("},")) {
                        data="";
                        i++;
                }
        }
        return "";
}

String Json::getJsonJ(Stream *stream,String id){
        while (stream->available()) {
                data.concat( char(stream->read()));
                if (data.endsWith(id) ) {
                        return   data;
                }
                if (data.length()>id.length()) {
                        data=data.substring(1);
                }
        }
        return "";
}
