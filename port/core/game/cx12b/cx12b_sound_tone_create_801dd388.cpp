#include "w3d_ptr.h"
#line 1 "cx12b_sound_tone_create_801dd388.cpp"

struct Parameters{unsigned int f0,f4,f8,f12;int f16;unsigned int f20,f24;float f28,f32,f36,f40,f44,f48;unsigned int f52,f56,f60;};
struct Sound;struct SoundVtable{Ptr32<void> p0[3];Ptr32<void (Ptr32<Sound>)> retain;Ptr32<void (Ptr32<Sound>)> release;Ptr32<void> p1[4];Ptr32<void (Ptr32<Sound>, unsigned int)> set36;Ptr32<void> p2[1];Ptr32<void (Ptr32<Sound>, unsigned int)> set44;Ptr32<void> p3[3];Ptr32<void (Ptr32<Sound>, unsigned int)> set60;Ptr32<void> p4[2];Ptr32<void (Ptr32<Sound>, unsigned int)> set72;Ptr32<void> p5[1];Ptr32<void (Ptr32<Sound>, float, float)> set80;Ptr32<void> p6[1];Ptr32<void (Ptr32<Sound>, Ptr32<Parameters>)> set88;};struct Sound{Ptr32<SoundVtable> vtable;};
struct SoundRef{Ptr32<Sound> p;template <class W3dU> SoundRef(Ptr32<W3dU> w3d_p) : SoundRef((Sound *)w3d_p.get()) {}
 inline SoundRef(Sound*x){p=x;if(p)p->vtable->retain(p);}inline ~SoundRef(){if(p)p->vtable->release(p);}};
extern "C" Ptr32<Sound> create_8020fcb4(Ptr32<void>);extern "C" int append_801ddf5c(Ptr32<void>,Ptr32<Sound>);

extern "C" unsigned char descriptor_8036564c[];extern "C" float default_803b01c0[];
extern "C" void set_801df234(Ptr32<Sound>,int);extern "C" void set_801df1dc(Ptr32<Sound>,unsigned int);extern "C" void set_801df1fc(Ptr32<Sound>,float);extern "C" void set_801df1e4(Ptr32<Sound>,float,float);extern "C" void set_801df204(Ptr32<Sound>,float);extern "C" void set_801df1f0(Ptr32<Sound>,float,float);extern "C" int set_801df20c(Ptr32<Sound>,unsigned int);extern "C" void set_801df280(Ptr32<Sound>,unsigned int);
extern "C" int w3d_cx12b_sound_tone_create_801dd388(Ptr32<void>,Ptr32<void> owner,Ptr32<Parameters> p){SoundRef h(create_8020fcb4(descriptor_8036564c));h.p->vtable->set36(h.p,p->f0);h.p->vtable->set60(h.p,p->f4);if(p->f16>0)set_801df234(h.p,p->f16);h.p->vtable->set44(h.p,p->f20);set_801df1dc(h.p,p->f24);set_801df1fc(h.p,p->f28);set_801df1e4(h.p,p->f32,default_803b01c0[0]);set_801df204(h.p,p->f36);set_801df1f0(h.p,p->f40,p->f44);set_801df20c(h.p,p->f12);set_801df280(h.p,p->f52);if(!append_801ddf5c(owner,h.p))return (int)0x80004005;return 0;}



