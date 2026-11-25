#include "w3d_ptr.h"
#line 1 "cx12b_sound_sample_create_801dd4f4.cpp"

struct Parameters{unsigned int f0,f4,f8,f12;int f16;unsigned int f20,f24;float f28,f32,f36,f40,f44,f48;unsigned int f52,f56,f60;};
struct Sound;struct SoundVtable{Ptr32<void> p0[3];Ptr32<void (Ptr32<Sound>)> retain;Ptr32<void (Ptr32<Sound>)> release;Ptr32<void> p1[4];Ptr32<void (Ptr32<Sound>, unsigned int)> set36;Ptr32<void> p2[1];Ptr32<void (Ptr32<Sound>, unsigned int)> set44;Ptr32<void> p3[3];Ptr32<void (Ptr32<Sound>, unsigned int)> set60;Ptr32<void> p4[2];Ptr32<void (Ptr32<Sound>, unsigned int)> set72;Ptr32<void> p5[1];Ptr32<void (Ptr32<Sound>, float, float)> set80;Ptr32<void> p6[1];Ptr32<void (Ptr32<Sound>, Ptr32<Parameters>)> set88;};struct Sound{Ptr32<SoundVtable> vtable;};
struct SoundRef{Ptr32<Sound> p;template <class W3dU> SoundRef(Ptr32<W3dU> w3d_p) : SoundRef((Sound *)w3d_p.get()) {}
 inline SoundRef(Sound*x){p=x;if(p)p->vtable->retain(p);}inline ~SoundRef(){if(p)p->vtable->release(p);}};
extern "C" Ptr32<Sound> create_8020fcb4(Ptr32<void>);extern "C" int append_801ddf5c(Ptr32<void>,Ptr32<Sound>);

extern "C" unsigned char descriptor_803656dc[];extern "C" void set_801e25cc(Ptr32<Sound>,unsigned int);
extern "C" int w3d_cx12b_sound_sample_create_801dd4f4(Ptr32<void>,Ptr32<void> owner,Ptr32<Parameters> p){SoundRef h(create_8020fcb4(descriptor_803656dc));h.p->vtable->set88(h.p,p);h.p->vtable->set36(h.p,p->f0);h.p->vtable->set60(h.p,p->f12);h.p->vtable->set80(h.p,p->f48,p->f44);h.p->vtable->set72(h.p,*(Ptr32<unsigned int>)&p->f28);set_801e25cc(h.p,p->f60);if(!append_801ddf5c(owner,h.p))return (int)0x80004005;return 0;}




