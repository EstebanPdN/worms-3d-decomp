// Scrollbar event routing. Owner, engine and message are borrowed views.
// Position is a complete three-float return object, independently witnessed
// by the stores in 0x8029662c; the pointer-message reader writes two floats.
namespace H2cBox {
template<class T> inline T& field(void* p,unsigned offset){return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);}
struct Position {float x,y,z;};
struct CaptureFlags {unsigned unknownHigh:7,captured:1,unknownLow:24;};
struct Cache {unsigned state;const char*name;};
inline int enabled(void* self){return (field<int>(self,60)!=0)&(field<int>(self,56)!=0);}
}
using namespace H2cBox;
extern int current_804abb5c,modal_804abb48;
extern void* engine_804aac54;
extern Cache cache_804b0d94,cache_804b0d6c,cache_804b0d74,cache_804b0d7c,cache_804b0d84,cache_804b0d64,cache_804b0d5c;
extern float step_803d0778[],half_803d077c[],arrow_803d0780[],pulse_803d0784[],zero_803d0788[];
extern "C" int fn_8015fb34(void*,void*),fn_8015f65c(unsigned,Cache*);
extern "C" void fn_802950c8(void*),fn_80295204(void*),fn_80069a50(void*,float*,float*),fn_80296410(void*,float),fn_80296598(void*,int);
extern "C" Position* fn_8029662c(Position*,void*);
extern "C" int w3d_h2c_box_events_80294a60(void*self,void*message){
 Position origin;
 float motionX,motionY,pressX,pressY,releaseX,releaseY;
 float value;
 unsigned captureState;
 void* engine;
 switch(field<unsigned short>(message,0)){
 case 64:if(fn_8015fb34(self,message)>=0){fn_802950c8(self);goto handled;}return static_cast<int>(0x80004005u);
 case 66:fn_80295204(self);return fn_8015fb34(self,message);
 }
 if(current_804abb5c!=field<int>(self,216)||modal_804abb48)return fn_8015fb34(self,message);
 if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d94)){
  fn_80069a50(message,&motionX,&motionY);
  float prior=field<float>(self,44);
  motionX=step_803d0778[0]/field<float>(self,100);
  field<float>(self,44)=motionY;
  motionX=(prior-motionY)*motionX;
  value=field<float>(self,92)+motionX;
  if(value>field<float>(self,84))value=field<float>(self,84);
  if(value<field<float>(self,80))value=field<float>(self,80);
  goto apply_value;
 }else if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d6c)&&enabled(self)){
  fn_80069a50(message,&pressX,&pressY);field<float>(self,44)=pressY;fn_8029662c(&origin,self);
  if(pressX>origin.x+field<float>(self,160))goto handled;
  if(pressX<origin.x-field<float>(self,160))goto handled;
  float extent=field<float>(self,48)*half_803d077c[0];
  float top=origin.y+extent;
  if(pressY>top)goto handled;
  float bottom=origin.y-extent;
  if(pressY<bottom)goto handled;
  float arrow=field<float>(self,164)*arrow_803d0780[0];
  float thumbTop=field<float>(self,108)*half_803d077c[0]+(field<float>(self,104)+origin.y);
  arrow+=arrow;
  float thumbBottom=thumbTop-field<float>(self,108);
  float topTrack=top-arrow;
  float bottomTrack=bottom+arrow;
  if(pressY<=top&&pressY>=topTrack){fn_80296410(self,field<float>(self,92)-step_803d0778[0]);field<float>(self,112)=pulse_803d0784[0];return 0;}
  if(pressY<=bottomTrack&&pressY>=bottom){fn_80296410(self,field<float>(self,92)+step_803d0778[0]);field<float>(self,116)=pulse_803d0784[0];return 0;}
  if(pressY<=thumbTop&&pressY>=thumbBottom&&field<float>(self,100)!=zero_803d0788[0]){
   engine=engine_804aac54;captureState=1;goto set_capture;
  }
  if(pressY<=topTrack&&pressY>=thumbTop&&field<float>(self,100)!=zero_803d0788[0]){fn_80296410(self,field<float>(self,92)-field<float>(self,88));goto handled;}
  if(pressY<=thumbBottom&&pressY>=bottomTrack&&field<float>(self,100)!=zero_803d0788[0]){fn_80296410(self,field<float>(self,92)+field<float>(self,88));goto handled;}
  goto handled;
 }else if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d74)){
  fn_80069a50(message,&releaseX,&releaseY);
  engine=engine_804aac54;captureState=0;
set_capture:
  field<int>(self,68)=captureState;
  field<CaptureFlags>(engine,96).captured=captureState;
  fn_80296598(self,0);goto handled;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d7c)){
  value=field<float>(self,92)-step_803d0778[0];if(value<field<float>(self,80))value=field<float>(self,80);goto apply_value;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d84)){
  value=field<float>(self,92)+step_803d0778[0];if(value>field<float>(self,84))value=field<float>(self,84);
apply_value:
  fn_80296410(self,value);goto handled;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d64)){
  fn_80296410(self,field<float>(self,92)+field<float>(self,88));goto handled;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d5c)){
  fn_80296410(self,field<float>(self,92)-field<float>(self,88));goto handled;
 }
 return fn_8015fb34(self,message);
handled:
 return 0;
}
