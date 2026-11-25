/* Worms 3D GameCube PAL 0x8004ca00. Applies a motion's range response to a body unless the body's +124 flag is set: within the +28 radius of the motion position it runs the countdown step scaled by distance and the +20 strength; within the +30 radius of the motion velocity vector it nudges the body along the normalized offset, scaled by distance and the +24 strength. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" float sqrt_802e82c0(float);
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    float dist(const Vec &o) const { float dx = x - o.x, dy = y - o.y, dz = z - o.z; return sqrt_802e82c0(dx * dx + dy * dy + dz * dz); }
    Vec operator-(const Vec &o) const { Vec r; r.x = x - o.x; r.y = y - o.y; r.z = z - o.z; return r; }
    float len() const { return sqrt_802e82c0(x * x + y * y + z * z); }
    Vec &normalize() { float s = 1.0f / len(); x *= s; y *= s; z *= s; return *this; }
};
struct Motion;
struct Body { char u0[40]; Vec pos; char u52[124 - 52]; int off; };
extern "C" {
Vec w3d_motion_get_position_80066894(Motion *);
Vec w3d_motion_get_velocity_800668b8(Motion *);
float w3d_motion_get_28_800668e4(Motion *);
float w3d_motion_get_20_800668f4(Motion *);
float w3d_motion_get_30_800668dc(Motion *);
float w3d_motion_get_24_800668fc(Motion *);
void k4a_countdown_step_8004cc60(Body *, float);
void k5a_body_nudge_8004cbdc(Body *, const Vec *, float);
}
extern "C" void w3d_d28g_body_motion_range_response_8004ca00(Body *self, Motion *m)
{
    if (self->off != 0) return;
    float d;
    {
        Vec p = w3d_motion_get_position_80066894(m);
        d = self->pos.dist(p);
    }
    float r = w3d_motion_get_28_800668e4(m);
    if (d < r) k4a_countdown_step_8004cc60(self, (r - d) * w3d_motion_get_20_800668f4(m) / r);
    float d2;
    {
        Vec p = w3d_motion_get_velocity_800668b8(m);
        d2 = self->pos.dist(p);
    }
    float r2 = w3d_motion_get_30_800668dc(m);
    if (d2 < r2) {
        float s = (r2 - d2) * w3d_motion_get_24_800668fc(m) / r2;
        Vec q = self->pos - w3d_motion_get_velocity_800668b8(m);
        Vec n = q.normalize();
        k5a_body_nudge_8004cbdc(self, &n, s);
    }
}
