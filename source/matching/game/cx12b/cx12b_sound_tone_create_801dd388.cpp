
struct Parameters{unsigned int f0,f4,f8,f12;int f16;unsigned int f20,f24;float f28,f32,f36,f40,f44,f48;unsigned int f52,f56,f60;};
struct Sound;struct SoundVtable{void*p0[3];void(*retain)(Sound*);void(*release)(Sound*);void*p1[4];void(*set36)(Sound*,unsigned int);void*p2[1];void(*set44)(Sound*,unsigned int);void*p3[3];void(*set60)(Sound*,unsigned int);void*p4[2];void(*set72)(Sound*,unsigned int);void*p5[1];void(*set80)(Sound*,float,float);void*p6[1];void(*set88)(Sound*,Parameters*);};struct Sound{SoundVtable*vtable;};
struct SoundRef{Sound*p;inline SoundRef(Sound*x){p=x;if(p)p->vtable->retain(p);}inline ~SoundRef(){if(p)p->vtable->release(p);}};
extern "C" Sound*create_8020fcb4(void*);extern "C" int append_801ddf5c(void*,Sound*);

extern "C" unsigned char descriptor_8036564c[];extern "C" float default_803b01c0[];
extern "C" void set_801df234(Sound*,int);extern "C" void set_801df1dc(Sound*,unsigned int);extern "C" void set_801df1fc(Sound*,float);extern "C" void set_801df1e4(Sound*,float,float);extern "C" void set_801df204(Sound*,float);extern "C" void set_801df1f0(Sound*,float,float);extern "C" int set_801df20c(Sound*,unsigned int);extern "C" void set_801df280(Sound*,unsigned int);
extern "C" int w3d_cx12b_sound_tone_create_801dd388(void*,void*owner,Parameters*p){SoundRef h(create_8020fcb4(descriptor_8036564c));h.p->vtable->set36(h.p,p->f0);h.p->vtable->set60(h.p,p->f4);if(p->f16>0)set_801df234(h.p,p->f16);h.p->vtable->set44(h.p,p->f20);set_801df1dc(h.p,p->f24);set_801df1fc(h.p,p->f28);set_801df1e4(h.p,p->f32,default_803b01c0[0]);set_801df204(h.p,p->f36);set_801df1f0(h.p,p->f40,p->f44);set_801df20c(h.p,p->f12);set_801df280(h.p,p->f52);if(!append_801ddf5c(owner,h.p))return (int)0x80004005;return 0;}

