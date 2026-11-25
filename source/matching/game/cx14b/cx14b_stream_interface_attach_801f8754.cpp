
// PPC32: held interface at +20. Method-table slots +12/+16 retain/release.
struct Interface{void**table;};struct Owner{char pad[20];Interface*held;};
extern "C" int validate_801f8838(Owner*);
inline void retain(Interface*p){((void(*)(Interface*))p->table[3])(p);}
inline void release(Interface*p){((void(*)(Interface*))p->table[4])(p);}
extern "C" int w3d_cx14b_stream_interface_attach_801f8754(Owner*self,Interface*p){if(p)retain(p);if(self->held)release(self->held);self->held=p;int result=validate_801f8838(self);if(result){if(self->held)release(self->held);self->held=0;}return result;}

