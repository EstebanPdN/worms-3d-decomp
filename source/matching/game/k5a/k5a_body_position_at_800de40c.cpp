struct K5aVec3
{
    float x, y, z;
    K5aVec3() {}
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 scaled(float k) const { K5aVec3 r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    K5aVec3 plus(const K5aVec3 &o) const { K5aVec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct K5aTrajectory { char pad0[36]; K5aVec3 origin; K5aVec3 velocity; char pad1[40]; unsigned int start_time; };

extern "C" void k5a_body_position_at_800de40c(K5aTrajectory *self, unsigned int now, K5aVec3 *out)
{
    float elapsed = (float)(now - self->start_time);
    *out = self->origin.plus(self->velocity.scaled(elapsed));
}
