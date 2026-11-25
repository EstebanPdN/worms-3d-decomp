extern "C" {
struct S4Object { void (**vtable)(); };
struct S4Controller { void *vtable; unsigned char pad[28]; S4Object *a,*b,*c,*d,*e; int unknown; unsigned int flags; };
int w3d_ctor_801628b0(void *);
void w3d_service_destroy_801628ec(void *,int);
extern unsigned char w3d_vtable_8041bfd0[];
S4Controller *w3d_s4_controller_construct(S4Controller *self)
{
    w3d_ctor_801628b0(self);
    unsigned int flags=self->flags & 0x3fffffff;
    self->vtable=w3d_vtable_8041bfd0;
    self->a=0; self->b=0; self->c=0; self->d=0; self->e=0;
    self->flags=flags;
    return self;
}
void w3d_s4_controller_destroy(S4Controller *self,int flags)
{
    self->vtable=w3d_vtable_8041bfd0;
    if(self->e) ((void (*)(S4Object *))self->e->vtable[4])(self->e);
    if(self->d) ((void (*)(S4Object *))self->d->vtable[4])(self->d);
    if(self->c) ((void (*)(S4Object *))self->c->vtable[4])(self->c);
    if(self->b) ((void (*)(S4Object *))self->b->vtable[4])(self->b);
    if(self->a) ((void (*)(S4Object *))self->a->vtable[4])(self->a);
    w3d_service_destroy_801628ec(self,flags);
}
}
