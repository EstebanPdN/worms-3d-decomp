// Inferred message header, cache objects and by-value string ABI.
struct F7aMessage{unsigned short id;};
struct F7aText_8020bb54{char*text;F7aText_8020bb54(const char*);~F7aText_8020bb54();};
struct F7aCache{int words[2];};
extern F7aCache cache_804b0cfc,cache_804b0d2c,cache_804b0d04,cache_804b0d34,cache_804b0d0c,cache_804b0d14,cache_804b0d1c,cache_804b0d24,cache_804b0d3c,cache_804b0d44;
extern char full_803d0148[];
extern "C" int fn_8016293c(void*,F7aMessage*),fn_8015f65c(unsigned short,F7aCache*),fn_802ef234(const char*,const char*);
extern "C" const char* fn_8010a8fc(F7aMessage*);
extern "C" void fn_8028f338(void*),fn_8028f4a0(void*),fn_80292d4c(void*),fn_80290204(void*,int),fn_80291b90(void*),fn_802924e4(void*),fn_8028fb10(void*),fn_8029301c(void*);
extern "C" void fn_8028f4ac(void*,F7aText_8020bb54),fn_80293020(void*,F7aText_8020bb54),fn_80290d50(void*,F7aText_8020bb54),fn_80292818(void*,F7aText_8020bb54);
extern "C" int w3d_f7a_scheme_message_8028f0d8(void*self,F7aMessage*msg){
 switch(msg->id){case 64:{if(fn_8016293c(self,msg)>=0){fn_8028f338(self);return 0;}return (int)0x80004005;}case 66:fn_8028f4a0(self);goto done;default:break;}
 if(fn_8015f65c(msg->id,&cache_804b0cfc))fn_8028f4ac(self,F7aText_8020bb54(fn_8010a8fc(msg)));
 else if(fn_8015f65c(msg->id,&cache_804b0d2c))fn_80292d4c(self);
 else if(fn_8015f65c(msg->id,&cache_804b0d04)){if(fn_802ef234(fn_8010a8fc(msg),full_803d0148)==0)fn_80290204(self,1);else fn_80290204(self,0);}
 else if(fn_8015f65c(msg->id,&cache_804b0d34))fn_80293020(self,F7aText_8020bb54(fn_8010a8fc(msg)));
 else if(fn_8015f65c(msg->id,&cache_804b0d0c))fn_80290d50(self,F7aText_8020bb54(fn_8010a8fc(msg)));
 else if(fn_8015f65c(msg->id,&cache_804b0d14))fn_80291b90(self);
 else if(fn_8015f65c(msg->id,&cache_804b0d1c))fn_802924e4(self);
 else if(fn_8015f65c(msg->id,&cache_804b0d24))fn_8028fb10(self);
 else if(fn_8015f65c(msg->id,&cache_804b0d3c))fn_8029301c(self);
 else if(fn_8015f65c(msg->id,&cache_804b0d44))fn_80292818(self,F7aText_8020bb54(fn_8010a8fc(msg)));
 done:return fn_8016293c(self,msg);
}
