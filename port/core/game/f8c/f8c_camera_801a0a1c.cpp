#include "w3d_ptr.h"
#line 1 "f8c_camera_801a0a1c.cpp"
// Names, roles, types, qualifiers and layouts are inferred from original instructions.
struct F8cCamVec{float x,y,z;};struct F8cCamMatrix{float m[16];};struct F8cCamAffine{float rotation[9];F8cCamVec position;};
extern const float lbl_803a9b14[],lbl_803a9b18[],lbl_803a9b1c[],lbl_803a9b20[];
extern "C" void fn_801a0b80(Ptr32<void>);extern "C" int fn_801f69ec(Ptr32<F8cCamMatrix>,Ptr32<const F8cCamMatrix>);
struct F8cCamConfig{char unknown[44];float width,height,nearValue,farValue,divisor;};
struct F8cCamProvider{Ptr32<Ptr32<void>> vtable;};
struct F8cCamOwner{char unknown0[20];F8cCamMatrix inverse;char unknown1[64];float negativeX,positiveX,negativeY,positiveY,farValue,nearValue;unsigned zero;char unknown2[36];unsigned dirty;};
struct F8cCamView{Ptr32<F8cCamAffine> matrix;unsigned unknown;};
inline void F8cCamConvert(F8cCamMatrix&full,Ptr32<F8cCamAffine> m){Ptr32<float> pos=(Ptr32<float>)&m->position;full.m[0]=m->rotation[0];full.m[1]=m->rotation[1];full.m[2]=m->rotation[2];full.m[3]=lbl_803a9b1c[0];full.m[4]=m->rotation[3];full.m[5]=m->rotation[4];full.m[6]=m->rotation[5];full.m[7]=lbl_803a9b1c[0];full.m[8]=m->rotation[6];full.m[9]=m->rotation[7];full.m[10]=m->rotation[8];full.m[11]=lbl_803a9b1c[0];full.m[12]=pos[0];full.m[13]=pos[1];full.m[14]=pos[2];full.m[15]=lbl_803a9b20[0];}extern "C" int f8c_camera_801a0a1c(Ptr32<F8cCamOwner> self,Ptr32<F8cCamConfig> config,Ptr32<void> arg,Ptr32<F8cCamProvider> provider){float x=config->width*lbl_803a9b14[0];float y=config->height*lbl_803a9b14[0];float f=lbl_803a9b18[0];float d=config->divisor;x*=f;y*=f;self->zero=0;self->farValue=config->farValue;self->nearValue=config->nearValue;self->negativeX=-x/d;self->positiveX=x/d;self->negativeY=-y/d;self->positiveY=y/d;fn_801a0b80(self);F8cCamView view;((Ptr32<int (Ptr32<F8cCamProvider>, Ptr32<F8cCamConfig>, Ptr32<void>, Ptr32<F8cCamView>)>)provider->vtable[9])(provider,config,arg,&view);Ptr32<F8cCamAffine> m=view.matrix;F8cCamMatrix full;F8cCamConvert(full,m); fn_801f69ec(&self->inverse,&full);self->dirty=0;return 0;}


