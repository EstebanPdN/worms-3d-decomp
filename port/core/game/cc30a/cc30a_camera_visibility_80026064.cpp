#include "w3d_ptr.h"
#line 1 "cc30a_camera_visibility_80026064.cpp"
// Original visibility and animation sequence; class extents beyond used fields unknown.
struct cc30a_Control_80026064;
struct cc30a_VTable_80026064 {char gap[88];Ptr32<void (Ptr32<cc30a_Control_80026064>, bool)> visible;};
struct cc30a_Control_80026064 {Ptr32<cc30a_VTable_80026064> vt;};
struct cc30a_Owner_80026064 {char gap[60];Ptr32<cc30a_Control_80026064> a; Ptr32<cc30a_Control_80026064> b; Ptr32<cc30a_Control_80026064> c; Ptr32<cc30a_Control_80026064> d;char gap4c[16];int mode,active,blocked;};
struct cc30a_Global_80026064 {char gap[188];unsigned flags;};
extern Ptr32<cc30a_Global_80026064> cc30a_global_804b1788;
extern float cc30a_float_8036c9cc[],cc30a_float_8036c9d0[],cc30a_float_8036c9d4[];
extern Ptr32<char> cc30a_name_804aa7f4; extern Ptr32<char> cc30a_name_804aa7f8;
extern "C" {
int cc30a_call_801817e0(Ptr32<void>,int);
int cc30a_call_80181640(Ptr32<void>,Ptr32<const char>,Ptr32<unsigned int>,int,float,float,float);
int cc30a_call_8018179c(Ptr32<void>,unsigned,int);
void cc30a_camera_visibility_80026064(Ptr32<cc30a_Owner_80026064> self){
 if(cc30a_global_804b1788->flags&1024)self->b->vt->visible(self->b,!self->mode&&!self->blocked);
 self->a->vt->visible(self->a,self->mode&&!self->blocked);
 self->c->vt->visible(self->c,self->mode&&!self->blocked);
 self->d->vt->visible(self->d,self->mode&&!self->blocked);
 if(self->mode){unsigned track[2];cc30a_call_801817e0(self->a,-1);
 cc30a_call_80181640(self->a,cc30a_name_804aa7f4,track,0,*cc30a_float_8036c9cc,*cc30a_float_8036c9d0,*cc30a_float_8036c9d0);
 cc30a_call_80181640(self->a,cc30a_name_804aa7f8,track,1,*cc30a_float_8036c9cc,*cc30a_float_8036c9d0,*cc30a_float_8036c9d4);
 cc30a_call_8018179c(self->a,track[0],1);
 }
}}


