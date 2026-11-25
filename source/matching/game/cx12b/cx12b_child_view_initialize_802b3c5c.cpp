// Observed PPC32 interface layout; names are inferred from call patterns.
struct Service;struct Vtable {void *s0[3];void (*retain)(Service*);void (*release)(Service*);void *s1[17];void (*visible)(Service*,int);void (*attach)(Service*,Service*,int);void (*remove)(Service*,void*);void *s2[4];void *(*item)(Service*,int);int (*count)(Service*);};struct Service {Vtable *vtable;};
struct Owner {unsigned char opaque[28];Service *children;int state;unsigned char opaque2[4];Service *s40,*s44,*s48,*s52,*s56,*s60,*s64;unsigned char rest[36];int enabled;template<unsigned int Offset>void clear(Service *zero){Service **slot=(Service **)((unsigned char*)this+Offset);(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void setup_802b3148(Owner*);
extern "C" void setup_802b38d4(Owner*);


extern "C" Service **w3d_cx12b_child_view_initialize_802b3c5c(Service **out,Owner *self,Service **parent){
 Service *p=*parent;p->vtable->attach(p,self->children,0);
setup_802b3148(self);
setup_802b38d4(self);


 self->state=1;*out=self->children;if(*out)(*out)->vtable->retain(*out);if(*parent)(*parent)->vtable->release(*parent);return out;
}


