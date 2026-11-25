// PPC32 interface words and byte offsets are observed; semantic names are inferred.
struct Interface; struct Vtable {void (*slot[25])(Interface*);}; struct Interface {Vtable *vtable;};
struct Ref {Interface *value;};
inline void retain(Interface *p){if(p)p->vtable->slot[3](p);} inline void release(Interface*p){if(p)p->vtable->slot[4](p);}

struct Object{unsigned char opaque[104];Interface *held;};extern "C" void changed_802bdd24(Object*);
extern "C" void w3d_cx13b_changed_interface_assign_802bdc88(Object*self,Ref*value){if(self->held!=value->value){retain(value->value);release(self->held);self->held=value->value;changed_802bdd24(self);}release(value->value);}

