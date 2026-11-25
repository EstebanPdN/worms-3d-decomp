#include "w3d_ptr.h"
#line 1 "s4_mouse.cpp"
extern "C" {
struct S4Object { Ptr32<Ptr32<void (Ptr32<S4Object>)>> vtable; };
struct S4Vector { float x,y,z; };
struct S4Mouse { Ptr32<void> vtable; unsigned char pad[24]; Ptr32<S4Object> object; S4Vector position, previous; float size; Ptr32<S4Object> first; Ptr32<S4Object> second; };
int w3d_ctor_8015fef0(Ptr32<void>);
void w3d_base_destroy_8015ff2c(Ptr32<void>,int);
extern unsigned char w3d_vtable_8041bf00[];
extern const float w3d_f32_803cf35c[];
Ptr32<void> w3d_s4_mouse_construct(Ptr32<void> self)
{
    w3d_ctor_8015fef0(self);
    *(Ptr32<Ptr32<void>>)self = w3d_vtable_8041bf00;
    *(Ptr32<int>)((Ptr32<char>)self+28) = 0;
    Ptr32<float> a = (Ptr32<float>)((Ptr32<char>)self+32);
    *(Ptr32<int>)((Ptr32<char>)self+60) = 0;
    Ptr32<float> b = (Ptr32<float>)((Ptr32<char>)self+44);
    *(Ptr32<int>)((Ptr32<char>)self+64) = 0;
    *(Ptr32<float>)((Ptr32<char>)self+32) = w3d_f32_803cf35c[0]; a[1] = w3d_f32_803cf35c[0]; a[2] = w3d_f32_803cf35c[0];
    *(Ptr32<float>)((Ptr32<char>)self+44) = w3d_f32_803cf35c[0]; b[1] = w3d_f32_803cf35c[0]; b[2] = w3d_f32_803cf35c[0];
    return self;
}
void w3d_s4_mouse_destroy(Ptr32<S4Mouse> self,int flags)
{
    self->vtable = w3d_vtable_8041bf00;
    if(self->second) self->second->vtable[4](self->second);
    if(self->first) self->first->vtable[4](self->first);
    if(self->object) self->object->vtable[4](self->object);
    w3d_base_destroy_8015ff2c(self,flags);
}
}


