// Inferred frontend message cache identities and temporary string representation.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short*fn_80341884(void*);
struct Message{unsigned short id;};struct Cache{int words[2];};
extern "C" void fn_803426b8(void*);
struct F7aString{char*text;F7aString();F7aString(const char*);F7aString(const F7aString&o){fn_8020c5c0(this);text=o.text;unsigned short*h=fn_80341884(this);++*h;}~F7aString(){fn_8020c5c4(this);fn_80341588(this);}};
struct Key{const char*text;Key(const char*p):text(p){}};
extern char selected_803d092c[],new_803d093c[];
extern "C" int fn_8016293c(void*,Message*),fn_8015f65c(unsigned short,Cache*),fn_802ef234(const char*,const char*),fn_802ed89c(const char*);
extern "C" const char*fn_8010a8fc(Message*);extern "C" int fn_800a830c(Message*);
extern "C" int fn_800fc550(Key*,const char*),fn_800fc2b0(Key*,const char**);
extern "C" void fn_8020bd38(F7aString*,const char*);
extern "C" void fn_802972f0(void*),fn_802975f8(void*);
extern "C" void fn_80297620(void*,F7aString),fn_802979b8(void*),fn_80299a74(void*),fn_8029cdb4(void*),fn_80298e84(void*),fn_80299630(void*),fn_80297f7c(void*,F7aString,int,int),fn_8029d0ec(void*,F7aString),fn_8029d410(void*,int),fn_80298abc(void*,int),fn_80299520(void*,F7aString),fn_80298dd4(void*,F7aString),fn_802991b0(void*,F7aString),fn_80299ca4(void*,int),fn_8029a238(void*,const char*),fn_8029b83c(void*,const char*),fn_8029b73c(void*,const char*),fn_8029b410(void*),fn_8029b4dc(void*,const char*),fn_8029c4d0(void*,int),fn_80299fc4(void*,int);
extern Cache cache_804b0d9c,cache_804b0dd4,cache_804b0de4,cache_804b0e4c,cache_804b0db4,cache_804b0ddc,cache_804b0dac,cache_804b0e04,cache_804b0dfc,cache_804b0e0c,cache_804b0dbc,cache_804b0da4,cache_804b0dcc,cache_804b0dc4,cache_804b0dec,cache_804b0e14,cache_804b0e1c,cache_804b0e44,cache_804b0e24,cache_804b0e3c,cache_804b0e2c,cache_804b0e34,cache_804b0df4;
extern "C" int w3d_f7a_team_message_80296de0(void*self,Message*msg){
 switch(msg->id){case 64:if(fn_8016293c(self,msg)>=0){fn_802972f0(self);return 0;}return (int)0x80004005;case 66:fn_802975f8(self);goto done;default:break;}
 if(fn_8015f65c(msg->id,&cache_804b0d9c)){fn_80297620(self,F7aString(fn_8010a8fc(msg)));}
 else if(fn_8015f65c(msg->id,&cache_804b0dd4)){fn_802979b8(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0de4)){fn_80299a74(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0e4c)){fn_8029cdb4(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0db4)){fn_80298e84(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0ddc)){fn_80299630(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0dac)){fn_80297f7c(self,F7aString(fn_8010a8fc(msg)),1,1);}
 else if(fn_8015f65c(msg->id,&cache_804b0e04)){F7aString text;fn_8020bd38(&text,fn_8010a8fc(msg));fn_8029d0ec(self,F7aString(text));}
 else if(fn_8015f65c(msg->id,&cache_804b0dfc)){Key key(selected_803d092c);fn_800fc550(&key,fn_8010a8fc(msg));}
 else if(fn_8015f65c(msg->id,&cache_804b0e0c)){fn_8029d410(self,fn_800a830c(msg));}
 else if(fn_8015f65c(msg->id,&cache_804b0dbc)){if(fn_802ef234(new_803d093c,fn_8010a8fc(msg))==0)fn_80298abc(self,1);else fn_80298abc(self,0);}
 else if(fn_8015f65c(msg->id,&cache_804b0da4)){fn_80299520(self,F7aString(fn_8010a8fc(msg)));}
 else if(fn_8015f65c(msg->id,&cache_804b0dcc)){fn_80298dd4(self,F7aString(fn_8010a8fc(msg)));}
 else if(fn_8015f65c(msg->id,&cache_804b0dc4)){fn_802991b0(self,F7aString(fn_8010a8fc(msg)));}
 else if(fn_8015f65c(msg->id,&cache_804b0dec)){fn_80299ca4(self,fn_802ed89c(fn_8010a8fc(msg)));}
 else if(fn_8015f65c(msg->id,&cache_804b0e14)){fn_8029a238(self,fn_8010a8fc(msg));}
 else if(fn_8015f65c(msg->id,&cache_804b0e1c)){fn_8029b83c(self,fn_8010a8fc(msg));}
 else if(fn_8015f65c(msg->id,&cache_804b0e44)){Key key(selected_803d092c);const char*name;fn_800fc2b0(&key,&name);fn_8029b73c(self,name);}
 else if(fn_8015f65c(msg->id,&cache_804b0e24)){fn_8029b410(self);}
 else if(fn_8015f65c(msg->id,&cache_804b0e3c)){fn_8029b4dc(self,fn_8010a8fc(msg));}
 else if(fn_8015f65c(msg->id,&cache_804b0e2c)){fn_8029c4d0(self,0);}
 else if(fn_8015f65c(msg->id,&cache_804b0e34)){fn_8029c4d0(self,1);}
 else if(fn_8015f65c(msg->id,&cache_804b0df4)){fn_80299fc4(self,fn_802ed89c(fn_8010a8fc(msg)));}
 done:return fn_8016293c(self,msg);
}
