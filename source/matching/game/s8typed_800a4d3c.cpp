struct s8_Interface { void **vtable; };
struct s8_MeshOwner { char pad0[32]; s8_Interface *mesh; };
extern "C" void s8_virtual_forward_800a4d3c(s8_MeshOwner *self,void *child) {
    s8_Interface *mesh=self->mesh;
    ((void (*)(s8_Interface *,void *,int))mesh->vtable[19])(mesh,child,0);
}
