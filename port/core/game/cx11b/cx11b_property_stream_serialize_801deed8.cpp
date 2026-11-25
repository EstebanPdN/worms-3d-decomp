#include "w3d_ptr.h"
#line 1 "cx11b_property_stream_serialize_801deed8.cpp"
// Original PPC32 property serializer offsets and virtual stream slots; inferred field labels.
struct Stream;struct Vtable {Ptr32<void> a[8];Ptr32<int (Ptr32<Stream>, unsigned int, int)> s32;Ptr32<void> b[1];Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s40;Ptr32<void> c[2];Ptr32<int (Ptr32<Stream>, unsigned char, int, int)> s52;Ptr32<void> d[6];Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s80;Ptr32<int (Ptr32<Stream>, unsigned int, int, int)> s84;Ptr32<void> e[6];Ptr32<int (Ptr32<Stream>, float, int, int)> s112;Ptr32<void> f[3];Ptr32<int (Ptr32<Stream>, Ptr32<void>, int, int)> s128;};struct Stream {Ptr32<Vtable> vtable;};
struct Properties {unsigned char opaque[20];unsigned int f20,f24,f28,f32,f36,f40,f44;float f48,f52,f56,f60;unsigned int f64;unsigned char f68,f69,pad[2];float f72,f76;unsigned int f80,f84;};
extern "C" int w3d_cx11b_property_stream_serialize_801deed8(Ptr32<Properties> self,Ptr32<Stream> s){
 s->vtable->s128(s,&self->f24,0,0);
 s->vtable->s32(s,self->f28,0);
 s->vtable->s40(s,self->f64,0,0);
 s->vtable->s52(s,self->f68,0,0);
 s->vtable->s52(s,self->f69,0,0);
 s->vtable->s112(s,self->f60,0,0);
 s->vtable->s112(s,self->f56,0,0);
 s->vtable->s84(s,self->f44,0,0);
 s->vtable->s84(s,self->f20,0,0);
 s->vtable->s112(s,self->f72,0,0);
 s->vtable->s112(s,self->f76,0,0);
 s->vtable->s112(s,self->f48,0,0);
 s->vtable->s112(s,self->f52,0,0);
 s->vtable->s80(s,self->f84,0,0);
return 0;}



