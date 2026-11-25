struct K1aVec3 { int x, y, z; };
struct K1aTracked { char pad0[28]; K1aVec3 vec; char pad40[28]; char member[1]; };
extern "C" void w3d_handle_member_query_801262c0(void *);

extern "C" void k1a_tracked_set_vec_8003e1f8(K1aTracked *self, const K1aVec3 *v)
{
    self->vec = *v;
    w3d_handle_member_query_801262c0(self->member);
}
