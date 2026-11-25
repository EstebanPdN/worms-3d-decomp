
struct Service;struct Vtable{void *p[3];void(*retain)(Service*);void(*release)(Service*);};struct Service{Vtable*vtable;unsigned char opaque[20];int value;};
struct Inner{unsigned char opaque[24];void*properties;};struct Owner{unsigned char opaque[36];Inner*inner;};
extern "C" unsigned int flags_80240b84(void*);extern "C" Service *lookup_8020b680(void*);extern "C" unsigned char descriptor_8041aac8[];extern "C" int dispatch_8021e930(void*,Service*);
struct Handle{Service*p;inline Handle(Service*x){p=x;if(p)p->vtable->retain(p);}inline ~Handle(){if(p)p->vtable->release(p);}};
extern "C" void w3d_cx12b_flagged_property_dispatch_8021c294(Owner*self,int value){void*p=self->inner->properties;if(flags_80240b84(p)&64){Handle h(lookup_8020b680(descriptor_8041aac8));h.p->value=value;dispatch_8021e930(p,h.p);}}


