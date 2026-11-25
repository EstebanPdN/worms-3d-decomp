#include "w3d_ptr.h"
#line 1 "s4_controller.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (void)>> vtable; };
struct S4Controller { Ptr32<void> vtable; unsigned char pad[28]; Ptr32<S4Object> a; Ptr32<S4Object> b; Ptr32<S4Object> c; Ptr32<S4Object> d; Ptr32<S4Object> e; int unknown; unsigned int flags; };
int w3d_ctor_801628b0(Ptr32<void>);
void w3d_service_destroy_801628ec(Ptr32<void>,int);
extern unsigned char w3d_vtable_8041bfd0[];
Ptr32<S4Controller> w3d_s4_controller_construct(Ptr32<S4Controller> self)
{
    w3d_ctor_801628b0(self);
    unsigned int flags=self->flags & 0x3fffffff;
    self->vtable=w3d_vtable_8041bfd0;
    self->a=0; self->b=0; self->c=0; self->d=0; self->e=0;
    self->flags=flags;
    return self;
}
void w3d_s4_controller_destroy(Ptr32<S4Controller> self,int flags)
{
    self->vtable=w3d_vtable_8041bfd0;
    if(self->e) ((Ptr32<void (Ptr32<S4Object>)>)self->e->vtable[4])(self->e);
    if(self->d) ((Ptr32<void (Ptr32<S4Object>)>)self->d->vtable[4])(self->d);
    if(self->c) ((Ptr32<void (Ptr32<S4Object>)>)self->c->vtable[4])(self->c);
    if(self->b) ((Ptr32<void (Ptr32<S4Object>)>)self->b->vtable[4])(self->b);
    if(self->a) ((Ptr32<void (Ptr32<S4Object>)>)self->a->vtable[4])(self->a);
    w3d_service_destroy_801628ec(self,flags);
}
}


