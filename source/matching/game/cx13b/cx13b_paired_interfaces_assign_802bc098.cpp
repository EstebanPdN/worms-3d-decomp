// PPC32 interface words and byte offsets are observed; semantic names are inferred.
struct Interface; struct Vtable {void (*slot[25])(Interface*);}; struct Interface {Vtable *vtable;};
struct Ref {Interface *value;};
inline void retain(Interface *p){if(p)p->vtable->slot[3](p);} inline void release(Interface*p){if(p)p->vtable->slot[4](p);}

struct Object{unsigned char opaque[28];Interface *first;unsigned char gap[56];Interface *second;};
extern "C" void w3d_cx13b_paired_interfaces_assign_802bc098(Object*self,Ref*first,Ref*second){retain(first->value);release(self->first);self->first=first->value;retain(second->value);release(self->second);self->second=second->value;release(first->value);release(second->value);}

