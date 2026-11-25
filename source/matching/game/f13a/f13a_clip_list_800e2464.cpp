struct F13ClipMesh;

extern float zero_80389f10[],one_80389f14[],blend_80389f0c[];
extern char flag_80389f04[];
extern "C" int compare_802ef074(const char*,const char*);
extern "C" int play_80181640(F13ClipMesh*,const char*,int*,int,float,float,float);
extern "C" int control_8018179c(F13ClipMesh*,int,int);
extern "C" void f13a_clip_list_800e2464(void*,F13ClipMesh*mesh,const char*text){
 char buffer[256];int clip;int flag=0;bool blend=false;char*cursor=buffer;
 while(*text){
 int*result=&clip;
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
