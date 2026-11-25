
struct Parameters{unsigned int f0,f4,f8,f12;int f16;unsigned int f20,f24;float f28,f32,f36,f40,f44,f48;unsigned int f52,f56,f60;};
struct Sound;struct SoundVtable{void*p0[3];void(*retain)(Sound*);void(*release)(Sound*);void*p1[4];void(*set36)(Sound*,unsigned int);void*p2[1];void(*set44)(Sound*,unsigned int);void*p3[3];void(*set60)(Sound*,unsigned int);void*p4[2];void(*set72)(Sound*,unsigned int);void*p5[1];void(*set80)(Sound*,float,float);void*p6[1];void(*set88)(Sound*,Parameters*);};struct Sound{SoundVtable*vtable;};
struct SoundRef{Sound*p;inline SoundRef(Sound*x){p=x;if(p)p->vtable->retain(p);}inline ~SoundRef(){if(p)p->vtable->release(p);}};
extern "C" Sound*create_8020fcb4(void*);extern "C" int append_801ddf5c(void*,Sound*);

extern "C" unsigned char descriptor_803656dc[];extern "C" void set_801e25cc(Sound*,unsigned int);
extern "C" int w3d_cx12b_sound_sample_create_801dd4f4(void*,void*owner,Parameters*p){SoundRef h(create_8020fcb4(descriptor_803656dc));h.p->vtable->set88(h.p,p);h.p->vtable->set36(h.p,p->f0);h.p->vtable->set60(h.p,p->f12);h.p->vtable->set80(h.p,p->f48,p->f44);h.p->vtable->set72(h.p,*(unsigned int*)&p->f28);set_801e25cc(h.p,p->f60);if(!append_801ddf5c(owner,h.p))return (int)0x80004005;return 0;}


