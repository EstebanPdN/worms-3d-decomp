// Partial event/receiver views; dispatch preserves base status and the original
// motion strength conversion. Vector return uses the observed hidden-result ABI.
struct d11a_Message {unsigned short id;};
struct d11a_Receiver;
struct d11a_MessageCache {unsigned flags;const char *name;};
struct d11a_Vector {float x,y,z; d11a_Vector(){} d11a_Vector(const d11a_Vector &v){float a=v.x,b=v.y,c=v.z;x=a;y=b;z=c;} };
extern d11a_MessageCache d11a_motion_event_804af13c;
extern const float d11a_maximum_80398144[];
extern "C" int d11a_base_message_8016293c(d11a_Receiver *,d11a_Message *);
extern "C" int d11a_initialize_800fdc34(d11a_Receiver *);
extern "C" void d11a_cleanup_800fdc7c(d11a_Receiver *);
extern "C" int d11a_event_equals_8015f65c(unsigned,d11a_MessageCache *);
extern "C" float d11a_strength_800668fc(d11a_Message *);
extern "C" d11a_Vector d11a_velocity_800668b8(d11a_Message *);
extern "C" int d11a_start_fade_800fdc80(unsigned,unsigned,const d11a_Vector *,unsigned,int,int);
extern "C" int d11a_motion_message_800fda04(d11a_Receiver *self,d11a_Message *message)
{
 switch(message->id) {
 case 64:
   if(d11a_base_message_8016293c(self,message)>=0) {
     d11a_initialize_800fdc34(self);
     return 0;
   }
   return (int)0x80004005u;
 case 66:d11a_cleanup_800fdc7c(self);break;
 default:
   if(d11a_event_equals_8015f65c(message->id,&d11a_motion_event_804af13c)) {
     float strength=d11a_strength_800668fc(message)*d11a_maximum_80398144[0];
     strength+=strength;
     unsigned char value;
     if(strength<d11a_maximum_80398144[0])value=(unsigned char)strength;
     else value=255;
     d11a_Vector velocity=d11a_velocity_800668b8(message);
     d11a_start_fade_800fdc80(0,value,&velocity,500,-1,-1);
   }
 }
 return d11a_base_message_8016293c(self,message);
}
