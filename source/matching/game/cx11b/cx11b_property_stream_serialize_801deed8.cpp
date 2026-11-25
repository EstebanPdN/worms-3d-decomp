// Original PPC32 property serializer offsets and virtual stream slots; inferred field labels.
struct Stream;struct Vtable {void *a[8];int (*s32)(Stream *,unsigned int,int);void *b[1];int (*s40)(Stream *,unsigned int,int,int);void *c[2];int (*s52)(Stream *,unsigned char,int,int);void *d[6];int (*s80)(Stream *,unsigned int,int,int);int (*s84)(Stream *,unsigned int,int,int);void *e[6];int (*s112)(Stream *,float,int,int);void *f[3];int (*s128)(Stream *,void *,int,int);};struct Stream {Vtable *vtable;};
struct Properties {unsigned char opaque[20];unsigned int f20,f24,f28,f32,f36,f40,f44;float f48,f52,f56,f60;unsigned int f64;unsigned char f68,f69,pad[2];float f72,f76;unsigned int f80,f84;};
extern "C" int w3d_cx11b_property_stream_serialize_801deed8(Properties *self,Stream *s){
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

