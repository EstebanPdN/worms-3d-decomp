// Textbox event routing recovered from original code. External owner/message
// layouts are accessed as borrowed views; no incomplete object is constructed.
namespace H1cTextbox {
template<class T> inline T& field(void* p,unsigned offset){return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);}
struct Cache {unsigned state; const char* name;};
struct Hit {float x,y; int slot,value;};
inline void activate(void* self,void* control,int state){
 typedef void(*Activate)(void*,int);
 field<Activate*>(self,208)[13](control,state);
}
inline unsigned length(const char* text){return *reinterpret_cast<const unsigned short*>(text-4);}
}
using namespace H1cTextbox;
extern Cache msg_804b0ae0,msg_804b0b18,msg_804b0ae8,msg_804b0af0,
 msg_804b0af8,msg_804b0b00,msg_804b0b08,msg_804b0b20,msg_804b0b10;
extern int modal_804abb48;
extern "C" int fn_8015fb34(void*,void*),fn_802b264c(void*),fn_8015f65c(int,Cache*),fn_80270300(void*),fn_802ef234(const char*,const char*);
extern "C" unsigned fn_802bc71c(void*);
extern "C" int fn_8026f820(void*,int*,int*,float,float),fn_802ed8c4(const char*);
extern "C" void fn_8026e98c(void*),fn_8026ec30(void*),fn_80069a50(void*,float*,float*),fn_8026f948(void*,int,int),fn_802bc8b4(void*,int),fn_8026fc98(void*,int),fn_8010a904(void*,const char**,const char**),fn_802aff9c(void*,void*);
extern "C" int w3d_h1c_textbox_events_8026e288(void* self,void* message){
 Hit hover,selected,pressed;
 const char *name,*value;
 unsigned type=field<unsigned short>(message,0);
 switch(type){
 case 64: if(fn_8015fb34(self,message)>=0){fn_8026e98c(self);return 0;}return static_cast<int>(0x80004005u);
 case 66: fn_8026ec30(self);return fn_8015fb34(self,message);
 }
 void* control=static_cast<char*>(self)+28;
 if(!fn_802b264c(control))return fn_8015fb34(self,message);
 if(!modal_804abb48 && !field<int>(self,128)){
  if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0ae0)){
   if(field<int>(self,296)==1 && field<int>(self,188)==1){
    fn_80069a50(message,&hover.x,&hover.y);
    if(fn_8026f820(self,&hover.slot,&hover.value,hover.x,hover.y)==1 && hover.slot!=-1){
     fn_8026f948(self,hover.value,0);fn_802bc8b4(field<void*>(self,288),hover.value);
     field<int>(self,300)=hover.value;field<int>(self,304)=hover.slot;
    }
   }
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0b18)){
   if(field<int>(self,296)==1){
    if(field<int>(self,188)==1){
     fn_80069a50(message,&selected.x,&selected.y);
     if(fn_8026f820(self,&selected.slot,&selected.value,selected.x,selected.y)==1){
      if(selected.slot==-1)return 0;
      fn_8026f948(self,selected.value,0);fn_802bc8b4(field<void*>(self,288),selected.value);
      field<int>(self,300)=selected.value;field<int>(self,304)=selected.slot;
      fn_8026fc98(self,1);return 0;
     }
    }else{
     fn_80069a50(message,&pressed.x,&pressed.y);
     if(fn_8026f820(self,&pressed.slot,&pressed.value,pressed.x,pressed.y)!=1)return 0;
     if(!(field<int>(control,152)==1?field<int>(control,156):field<int>(control,148)))return 0;
     if(!field<int>(self,140))return 0;
     activate(self,control,1);
     if(pressed.slot==-1)return 0;
     fn_8026f948(self,pressed.value,0);fn_802bc8b4(field<void*>(self,288),pressed.value);
     field<int>(self,300)=pressed.value;field<int>(self,304)=pressed.slot;return 0;
    }
   }
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0ae8) && field<int>(self,296)==1 && field<int>(self,176)==1 && field<int>(self,188)==1){
   if(--field<int>(self,300)<0)field<int>(self,300)=0;
   field<int>(self,260)=0;field<int>(self,256)=2000;
   fn_8026f948(self,field<int>(self,300),0);fn_802bc8b4(field<void*>(self,288),field<int>(self,300));field<int>(self,304)=-1;
   return fn_8015fb34(self,message);
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0af0) && field<int>(self,296)==1 && field<int>(self,176)==1 && field<int>(self,188)==1){
   ++field<int>(self,300);
   if(static_cast<float>(field<int>(self,300))>=static_cast<float>(fn_802bc71c(field<void*>(self,288))))field<int>(self,300)=fn_802bc71c(field<void*>(self,288))-1;
   if(field<int>(self,300)<0)field<int>(self,300)=0;
   field<int>(self,260)=2000;field<int>(self,256)=0;
   fn_8026f948(self,field<int>(self,300),0);fn_802bc8b4(field<void*>(self,288),field<int>(self,300));field<int>(self,304)=-1;
   return fn_8015fb34(self,message);
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0af8) && field<int>(self,296)==1 && field<int>(self,176)==1){
   if(!field<int>(self,140))return 0;
   if(field<int>(self,188)!=1){activate(self,control,1);return 0;}
   if(field<int>(self,300)!=-1){fn_8026fc98(self,1);return 0;}
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0b00) && field<int>(self,296)==1 && field<int>(self,176)==1 && field<int>(self,188)==1){
   if(!fn_80270300(self))return 0;
   activate(self,control,0);
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0b08) && field<int>(self,188)==1){
   if(!length(field<const char*>(field<void*>(self,40),84)))return fn_8015fb34(self,message);
   activate(self,control,0);
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0b20) && field<int>(self,188)==0){
   fn_8010a904(message,&name,&value);
   if(!fn_802ef234(field<const char*>(field<void*>(self,40),88),name))fn_8026f948(self,fn_802ed8c4(value),0);
  }else if(fn_8015f65c(field<unsigned short>(message,0),&msg_804b0b10) && field<int>(self,188)==1){
   if(!length(field<const char*>(field<void*>(self,40),80)))return fn_8015fb34(self,message);
   activate(self,control,0);
  }
 }
 fn_802aff9c(control,message);
 return fn_8015fb34(self,message);
}
