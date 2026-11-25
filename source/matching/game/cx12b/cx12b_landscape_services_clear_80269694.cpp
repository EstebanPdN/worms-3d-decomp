
struct Service;struct Vtable {void *p[4];void (*release)(Service*);};struct Service{Vtable*vtable;};
struct Owner {unsigned char opaque[212];Service *first;unsigned char rest[268];Service *second;inline void clear(Service **slot,Service *zero){if(*slot)(*slot)->vtable->release(*slot);*slot=zero;}};
extern "C" void reset_8026c0d0(Owner*,int);extern "C" void member_802b0fec(void*);
inline void cleanup(Owner*self,Service*zero){self->clear(&self->first,zero);reset_8026c0d0(self,0);self->clear(&self->second,zero);member_802b0fec((unsigned char*)self+28);}
extern "C" void w3d_cx12b_landscape_services_clear_80269694(Owner*self){cleanup(self,0);}

