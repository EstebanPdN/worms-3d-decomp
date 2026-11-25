// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {void *s0[3];void (*retain)(Service*);void (*release)(Service*);void *s1[17];void (*visible)(Service*,int);void (*attach)(Service*,Service*,int);void (*remove)(Service*,void*);void *s2[4];void *(*item)(Service*,int);int (*count)(Service*);};struct Service {Vtable *vtable;};
struct Owner {unsigned char opaque[28];Service *children;int state;unsigned char opaque2[4];Service *s40,*s44,*s48,*s52,*s56,*s60,*s64;unsigned char rest[36];int enabled;template<unsigned int Offset>void clear(Service *zero){Service **slot=(Service **)((unsigned char*)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void setup_802c6434(Owner*);
extern "C" void setup_802c663c(Owner*);
extern "C" void setup_802c68bc(Owner*);

extern "C" Service **w3d_cx12b_child_view_initialize_802c6384(Service **out,Owner *self,Service **parent){
 Service *p=*parent;p->vtable->attach(p,self->children,0);
setup_802c6434(self);
setup_802c663c(self);
setup_802c68bc(self);

 self->state=1;*out=self->children;if(*out)(*out)->vtable->retain(*out);if(*parent)(*parent)->vtable->release(*parent);return out;
}

