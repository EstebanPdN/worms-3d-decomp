#include "w3d_ptr.h"
#line 1 "cc30a_camera_messages_80025ed0.cpp"
// GWMP8P original 80025ed0. Names are inferred; only observed offsets modeled.
typedef unsigned int cc30a_u32; typedef unsigned short cc30a_u16;
struct cc30a_Control_80025ed0;
struct cc30a_VTable_80025ed0 { char gap[88]; Ptr32<void (Ptr32<cc30a_Control_80025ed0>, int)> visible; };
struct cc30a_Control_80025ed0 { Ptr32<cc30a_VTable_80025ed0> vt; };
struct cc30a_Owner_80025ed0 { char gap[64]; Ptr32<cc30a_Control_80025ed0> control; char gap44[24]; int mode; int active; };
struct cc30a_Global_80025ed0 { char gap[188]; cc30a_u32 flags; };
extern Ptr32<cc30a_Global_80025ed0> cc30a_global_804b1788;
extern int cc30a_cache_804acb14,cc30a_cache_804acafc,cc30a_cache_804acaf4;
extern char cc30a_text_8036c9b8[];
extern "C" {
int cc30a_call_8015fb34(Ptr32<cc30a_Owner_80025ed0>,Ptr32<cc30a_u16>);
int cc30a_call_8015f65c(cc30a_u32,Ptr32<int>);
void cc30a_call_80026288(Ptr32<cc30a_Owner_80025ed0>);
void cc30a_call_800267a4(Ptr32<cc30a_Owner_80025ed0>);
void cc30a_call_80026064(Ptr32<cc30a_Owner_80025ed0>);
int cc30a_call_800fc230(Ptr32<Ptr32<char>>,Ptr32<int>);
int cc30a_camera_messages_80025ed0(Ptr32<cc30a_Owner_80025ed0> self,Ptr32<cc30a_u16> msg) {
 unsigned id=*msg;
 switch(id) {
 case 64: if(cc30a_call_8015fb34(self,msg)>=0){cc30a_call_80026288(self);return 0;}return 0x80004005;
 case 66:cc30a_call_800267a4(self);goto fallback;
 default:
 if(cc30a_call_8015f65c(id,&cc30a_cache_804acb14)) { Ptr32<char> key=cc30a_text_8036c9b8;int mode;cc30a_call_800fc230(&key,&mode);self->mode=(mode==1);cc30a_call_80026064(self); }
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acafc)) { self->control->vt->visible(self->control,0); self->active=0; }
 else if(cc30a_call_8015f65c(id,&cc30a_cache_804acaf4)) { if(cc30a_global_804b1788->flags&1024) { if(!self->mode)self->control->vt->visible(self->control,1);self->active=1; } }
 else { fallback:return cc30a_call_8015fb34(self,msg); }
 }
 return 0;
}
}


