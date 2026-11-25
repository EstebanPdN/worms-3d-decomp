
// PPC32: primary/secondary +20/+24, bounds +28/+32/+36, state +40, z_stream +44 (fifty-six bytes).
struct Interface{void**table;char pad[16];Interface*secondary;};struct Owner{char pad[20];Interface*a,*b;unsigned x,y,z,state;unsigned stream[14];};
extern "C" int initialize_802c8304(void*,int,const char*,int);extern "C" const char version_803b19d4[];
inline void retain(Interface*p){((void(*)(Interface*))p->table[3])(p);}inline void release(Interface*p){((void(*)(Interface*))p->table[4])(p);}
extern "C" int w3d_cx14b_compressed_stream_attach_801f937c(Owner*self,Interface*p,unsigned x,unsigned y,unsigned z){if(p)retain(p);if(self->a)release(self->a);self->x=x;self->y=y;self->z=z;self->a=p;self->state=0;Interface*q=p->secondary;if(q)retain(q);if(self->b)release(self->b);self->b=q;self->stream[8]=0;self->stream[9]=0;self->stream[10]=0;self->stream[1]=0;self->stream[3]=0;if(initialize_802c8304(self->stream,-15,version_803b19d4,56)!=0)return 0x80004005;return 0;}



