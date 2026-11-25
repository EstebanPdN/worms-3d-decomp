#include "w3d_ptr.h"
#line 1 "f13a_clip_list_800e2464.cpp"
struct F13ClipMesh;

extern float zero_80389f10[],one_80389f14[],blend_80389f0c[];
extern char flag_80389f04[];
extern "C" int compare_802ef074(Ptr32<const char>,Ptr32<const char>);
extern "C" int play_80181640(Ptr32<F13ClipMesh>,Ptr32<const char>,Ptr32<int>,int,float,float,float);
extern "C" int control_8018179c(Ptr32<F13ClipMesh>,int,int);
extern "C" void f13a_clip_list_800e2464(Ptr32<void>,Ptr32<F13ClipMesh> mesh,Ptr32<const char> text){
 char buffer[256];int clip;int flag=0;bool blend=false;Ptr32<char> cursor=buffer;
 while(*text){
 Ptr32<int> result=&clip;
  switch(*text){
  case '+':case ',':
   *cursor=0;{float amount=blend_80389f0c[0];if(!blend)amount=zero_80389f10[0];play_80181640(mesh,buffer,result,0,one_80389f14[0],amount,zero_80389f10[0]);}
   control_8018179c(mesh,clip,flag);blend=*text==',';cursor=buffer;flag=0;break;
  case ':':*cursor=0;if(compare_802ef074(buffer,flag_80389f04)==0)flag=1;cursor=buffer;break;
  default:if(*text!=' ')*cursor++=*text;break;
  }
  ++text;
 }
 *cursor=0;float amount;if(blend)amount=blend_80389f0c[0];else amount=zero_80389f10[0];play_80181640(mesh,buffer,&clip,0,one_80389f14[0],amount,zero_80389f10[0]);control_8018179c(mesh,clip,flag);
}


