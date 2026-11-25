struct K5aVec3
{
    float x, y, z;
    K5aVec3() {}
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 scaled(float k) const { K5aVec3 r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    K5aVec3 plus(const K5aVec3 &o) const { K5aVec3 r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct K5aClock { char pad0[40]; float step; };
struct K5aBody { char pad0[16]; K5aVec3 pos; char pad1[8]; K5aVec3 vel; };
extern "C" const float w3d_f32_8036a93c[];
extern "C" K5aClock *w3d_clock_804aa6d8;

extern "C" K5aVec3 k5a_body_predict_position_800196dc(const K5aBody *body, float dt)
{
    if (dt == w3d_f32_8036a93c[0])
        dt = w3d_clock_804aa6d8->step;
    return body->pos.plus(body->vel.scaled(dt));
}
