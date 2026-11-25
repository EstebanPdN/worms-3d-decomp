// Scrollbar event routing. Owner, engine and message are borrowed views.
// Position is a complete three-float return object, independently witnessed
// by the stores in 0x8029662c; the pointer-message reader writes two floats.
namespace H2cBox {
template<class T> inline T& field(void* p,unsigned offset){return *reinterpret_cast<T*>(static_cast<char*>(p)+offset);}
struct Position {float x,y,z;};
struct Point {float x,y;};
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
 Point motion,press,release;
 switch(field<unsigned short>(message,0)){
 case 64:if(fn_8015fb34(self,message)>=0){fn_802950c8(self);return 0;}return static_cast<int>(0x80004005u);
 case 66:fn_80295204(self);return fn_8015fb34(self,message);
 }
 if(current_804abb5c!=field<int>(self,216)||modal_804abb48)return fn_8015fb34(self,message);
 if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d94)){
  fn_80069a50(message,&motion.x,&motion.y);
  float prior=field<float>(self,44);
  motion.x=step_803d0778[0]/field<float>(self,100);
  field<float>(self,44)=motion.y;
  motion.x=(prior-motion.y)*motion.x;
  float value=field<float>(self,92)+motion.x;
  if(value>field<float>(self,84))value=field<float>(self,84);
  if(value<field<float>(self,80))value=field<float>(self,80);
  fn_80296410(self,value);return 0;
 }else if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d6c)&&enabled(self)){
  fn_80069a50(message,&press.x,&press.y);field<float>(self,44)=press.y;fn_8029662c(&origin,self);
  if(press.x>origin.x+field<float>(self,160))return 0;
  if(press.x<origin.x-field<float>(self,160))return 0;
  float extent=field<float>(self,48)*half_803d077c[0];
  float top=origin.y+extent;
  if(press.y>top)return 0;
  float bottom=origin.y-extent;
  if(press.y<bottom)return 0;
  float arrow=field<float>(self,164)*arrow_803d0780[0];
  float thumbTop=field<float>(self,108)*half_803d077c[0]+(field<float>(self,104)+origin.y);
  arrow+=arrow;
  float thumbBottom=thumbTop-field<float>(self,108);
  float topTrack=top-arrow;
  float bottomTrack=bottom+arrow;
  if(press.y<=top&&press.y>=topTrack){fn_80296410(self,field<float>(self,92)-step_803d0778[0]);field<float>(self,112)=pulse_803d0784[0];return 0;}
  if(press.y<=bottomTrack&&press.y>=bottom){fn_80296410(self,field<float>(self,92)+step_803d0778[0]);field<float>(self,116)=pulse_803d0784[0];return 0;}
  if(press.y<=thumbTop&&press.y>=thumbBottom&&field<float>(self,100)!=zero_803d0788[0]){
   field<int>(self,68)=1;field<unsigned>(engine_804aac54,96)=(field<unsigned>(engine_804aac54,96)&0xfeffffffu)|0x01000000u;fn_80296598(self,0);return 0;
  }
  if(press.y<=topTrack&&press.y>=thumbTop&&field<float>(self,100)!=zero_803d0788[0]){fn_80296410(self,field<float>(self,92)-field<float>(self,88));return 0;}
  if(press.y<=thumbBottom&&press.y>=bottomTrack&&field<float>(self,100)!=zero_803d0788[0]){fn_80296410(self,field<float>(self,92)+field<float>(self,88));return 0;}
  return 0;
 }else if(fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d74)){
  fn_80069a50(message,&release.x,&release.y);
  field<int>(self,68)=0;field<unsigned>(engine_804aac54,96)&=0xfeffffffu;fn_80296598(self,0);return 0;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d7c)){
  float value=field<float>(self,92)-step_803d0778[0];if(value<field<float>(self,80))value=field<float>(self,80);fn_80296410(self,value);return 0;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d84)){
  float value=field<float>(self,92)+step_803d0778[0];if(value>field<float>(self,84))value=field<float>(self,84);fn_80296410(self,value);return 0;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d64)){
  fn_80296410(self,field<float>(self,92)+field<float>(self,88));return 0;
 }else if(enabled(self)&&fn_8015f65c(field<unsigned short>(message,0),&cache_804b0d5c)){
  fn_80296410(self,field<float>(self,92)-field<float>(self,88));return 0;
 }
 return fn_8015fb34(self,message);
}
