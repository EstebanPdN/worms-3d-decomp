extern "C" {
struct S4Object { void (**vtable)(S4Object *); };
struct S4Vector { float x,y,z; };
struct S4Mouse { void *vtable; unsigned char pad[24]; S4Object *object; S4Vector position, previous; float size; S4Object *first, *second; };
int w3d_ctor_8015fef0(void *);
void w3d_base_destroy_8015ff2c(void *,int);
extern unsigned char w3d_vtable_8041bf00[];
extern const float w3d_f32_803cf35c[];
void *w3d_s4_mouse_construct(void *self)
{
    w3d_ctor_8015fef0(self);
    *(void **)self = w3d_vtable_8041bf00;
    *(int *)((char *)self+28) = 0;
    float *a = (float *)((char *)self+32);
    *(int *)((char *)self+60) = 0;
    float *b = (float *)((char *)self+44);
    *(int *)((char *)self+64) = 0;
    *(float *)((char *)self+32) = w3d_f32_803cf35c[0]; a[1] = w3d_f32_803cf35c[0]; a[2] = w3d_f32_803cf35c[0];
    *(float *)((char *)self+44) = w3d_f32_803cf35c[0]; b[1] = w3d_f32_803cf35c[0]; b[2] = w3d_f32_803cf35c[0];
    return self;
}
void w3d_s4_mouse_destroy(S4Mouse *self,int flags)
{
    self->vtable = w3d_vtable_8041bf00;
    if(self->second) self->second->vtable[4](self->second);
    if(self->first) self->first->vtable[4](self->first);
    if(self->object) self->object->vtable[4](self->object);
    w3d_base_destroy_8015ff2c(self,flags);
}
}
