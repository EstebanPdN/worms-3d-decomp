#include "w3d_ptr.h"
#line 1 "k7a_follow_transform_8002e670.cpp"
struct K7aVec { float x, y, z; };
extern "C" void w3d_empty_80343740(Ptr32<K7aVec> vector);
struct K7aMatrix
{
    K7aVec axis_x, axis_y, axis_z, translation;
    K7aMatrix() { w3d_empty_80343740(&translation); }
};
struct K7aSource { Ptr32<Ptr32<void>> vtable; };
struct K7aFollower { char pad0[40]; Ptr32<K7aSource> source; char pad44[52]; Ptr32<void> light; };
extern "C" int w3d_handle_member_query_801265ec(Ptr32<void> member, Ptr32<K7aVec> position);
extern "C" void w3d_s20_notify_global_800fdf24(Ptr32<K7aVec> position);

extern "C" void w3d_k7a_follow_transform_8002e670(Ptr32<K7aFollower> self)
{
    K7aVec position;
    K7aMatrix transform;
    ((Ptr32<void (Ptr32<K7aSource>, Ptr32<K7aMatrix>)>)self->source->vtable[31])(self->source, &transform);
    position = transform.translation;
    w3d_handle_member_query_801265ec(self->light, &position);
    w3d_s20_notify_global_800fdf24(&position);
}


