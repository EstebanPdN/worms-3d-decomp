struct K5aVec3
{
    float x, y, z;
    K5aVec3() {}
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 scaled(float k) const { K5aVec3 r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    K5aVec3 plus(const K5aVec3 &o) const { K5aVec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct K5aBody { char pad0[48]; K5aVec3 pos; K5aVec3 vel; };
extern "C" const float w3d_f32_8038b614[];

extern "C" void k5a_body_integrate_800ed5f8(K5aBody *self)
{
    self->pos = self->pos.plus(self->vel.scaled(w3d_f32_8038b614[0]));
}
