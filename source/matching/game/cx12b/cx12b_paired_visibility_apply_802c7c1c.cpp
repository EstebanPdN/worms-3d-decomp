// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {void *s0[3];void (*retain)(Service*);void (*release)(Service*);void *s1[17];void (*visible)(Service*,int);void (*attach)(Service*,Service*,int);void (*remove)(Service*,void*);void *s2[4];void *(*item)(Service*,int);int (*count)(Service*);};struct Service {Vtable *vtable;};
struct Owner {unsigned char opaque[28];Service *children;int state;unsigned char opaque2[4];Service *s40,*s44,*s48,*s52,*s56,*s60,*s64;unsigned char rest[40];int enabled;template<unsigned int Offset>void clear(Service *zero){Service **slot=(Service **)((unsigned char*)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};

extern "C" void w3d_cx12b_paired_visibility_apply_802c7c1c(Owner *self){if(self->enabled){
 int *flag=(int*)((unsigned char*)self+104);
 self->s40->vtable->visible(self->s40,*flag^1);self->s48->vtable->visible(self->s48,*flag^1);self->s56->vtable->visible(self->s56,*flag^1);
 self->s44->vtable->visible(self->s44,*flag);self->s52->vtable->visible(self->s52,*flag);self->s60->vtable->visible(self->s60,*flag);
}}


