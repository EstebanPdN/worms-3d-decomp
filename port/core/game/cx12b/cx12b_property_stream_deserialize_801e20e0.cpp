#include "w3d_ptr.h"
#line 1 "cx12b_property_stream_deserialize_801e20e0.cpp"

// PPC32 field offsets, virtual slot byte offsets and argument widths are observed.
struct Stream;struct Vtable {
 Ptr32<void> a[12];Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>, int)> s48;Ptr32<void> b[18];Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>, int)> s124;Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>, int)> s128;Ptr32<void> c[2];Ptr32<int (Ptr32<Stream>, Ptr32<float>, int)> s140;Ptr32<void> d[1];Ptr32<int (Ptr32<Stream>, Ptr32<unsigned int>, int)> s148;Ptr32<void> e[2];Ptr32<int (Ptr32<Stream>, Ptr32<void>, unsigned int, int)> s160;
};struct Stream{Ptr32<Vtable> vtable;};
struct Properties{unsigned char opaque[20];unsigned int f20,f24,f28,f32;float f36;unsigned int f40;float f44,f48,f52,f56,f60;unsigned int f64,f68,f72,f76,f80,f84,f88,f92;Ptr32<void> data;unsigned int bytes;};
struct Heap{unsigned int words[2];};extern "C" Heap heap_804b0564;
extern "C" void release_80209920(Ptr32<Heap>,Ptr32<void>);extern "C" void collect_80209968(Ptr32<Heap>);extern "C" Ptr32<void> allocate_802098d8(Ptr32<Heap>,unsigned int);
extern "C" int w3d_cx12b_property_stream_deserialize_801e20e0(Ptr32<Properties> self,Ptr32<Stream> s){
 s->vtable->s148(s,&self->f20,0);s->vtable->s148(s,&self->f32,0);s->vtable->s124(s,&self->f28,0);s->vtable->s140(s,&self->f36,0);s->vtable->s128(s,&self->f24,0);s->vtable->s48(s,&self->f40,0);
 s->vtable->s140(s,&self->f44,0);s->vtable->s140(s,&self->f48,0);s->vtable->s140(s,&self->f56,0);s->vtable->s140(s,&self->f60,0);s->vtable->s140(s,&self->f52,0);
 s->vtable->s124(s,&self->f72,0);s->vtable->s124(s,&self->f76,0);unsigned int value;s->vtable->s124(s,&value,0);self->f68=value;
 s->vtable->s128(s,&self->bytes,0);if(self->data){release_80209920(&heap_804b0564,self->data);collect_80209968(&heap_804b0564);}
 self->data=allocate_802098d8(&heap_804b0564,self->bytes);s->vtable->s160(s,self->data,self->bytes,0);
 s->vtable->s124(s,&self->f80,0);s->vtable->s124(s,&self->f84,0);return 0;
}



