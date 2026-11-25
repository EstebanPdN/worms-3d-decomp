#include "w3d_ptr.h"
#line 1 "cx11b_property_stream_serialize_801e1e70.cpp"
// Inferred observed properties and stream vtable byte offsets; zero flags remain explicit.
struct Stream;struct Vtable {Ptr32<void> p0[10];Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s40;Ptr32<void> p1[9];Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s80;Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s84;Ptr32<void> p2[6];Ptr32<int (Ptr32<Stream>, float, int, int)> s112;Ptr32<void> p3[3];Ptr32<int (Ptr32<Stream>, Ptr32<void>, int, int)> s128;Ptr32<void> p4[5];Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)> s152;};struct Stream {Ptr32<Vtable> vtable;};
struct Properties {unsigned char opaque[20];unsigned int f20,f24,f28,f32;float f36;unsigned int f40;float f44,f48,f52,f56,f60;unsigned int f64,f68,f72,f76,f80,f84,f88,f92;Ptr32<void> f96;unsigned int f100;};
extern "C" int w3d_cx11b_property_stream_serialize_801e1e70(Ptr32<Properties> self,Ptr32<Stream> s){
 s->vtable->s128(s,&self->f20,0,0);
 s->vtable->s128(s,&self->f32,0,0);
 s->vtable->s80(s,self->f28,0,0);
 s->vtable->s112(s,self->f36,0,0);
 s->vtable->s84(s,self->f24,0,0);
 s->vtable->s40(s,self->f40,0,0);
 s->vtable->s112(s,self->f44,0,0);
 s->vtable->s112(s,self->f48,0,0);
 s->vtable->s112(s,self->f56,0,0);
 s->vtable->s112(s,self->f60,0,0);
 s->vtable->s112(s,self->f52,0,0);
 s->vtable->s80(s,self->f72,0,0);
 s->vtable->s80(s,self->f76,0,0);
 s->vtable->s80(s,self->f68,0,0);
 s->vtable->s84(s,self->f100,0,0);
 s->vtable->s152(s,self->f96,self->f100,0);
 s->vtable->s80(s,self->f80,0,0);
 s->vtable->s80(s,self->f84,0,0);
 return 0;}



