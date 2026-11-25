struct K7aVec { float x, y, z; };
extern "C" void w3d_empty_80343740(K7aVec *vector);
struct K7aMatrix
{
    K7aVec axis_x, axis_y, axis_z, translation;
    K7aMatrix() { w3d_empty_80343740(&translation); }
};
struct K7aSource { void **vtable; };
struct K7aFollower { char pad0[40]; K7aSource *source; char pad44[52]; void *light; };
extern "C" int w3d_handle_member_query_801265ec(void *member, K7aVec *position);
extern "C" void w3d_s20_notify_global_800fdf24(K7aVec *position);

extern "C" void w3d_k7a_follow_transform_8002e670(K7aFollower *self)
{
    K7aVec position;
    K7aMatrix transform;
    ((void (*)(K7aSource *, K7aMatrix *))self->source->vtable[31])(self->source, &transform);
    position = transform.translation;
    w3d_handle_member_query_801265ec(self->light, &position);
    w3d_s20_notify_global_800fdf24(&position);
}
