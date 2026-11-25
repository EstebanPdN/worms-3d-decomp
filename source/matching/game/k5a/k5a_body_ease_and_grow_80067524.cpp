struct K5aVec3
{
    float x, y, z;
    K5aVec3() {}
    K5aVec3(float a, float b, float c) { x = a; y = b; z = c; }
    K5aVec3(const K5aVec3 &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    K5aVec3 scaled(float k) const { K5aVec3 r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    void add(const K5aVec3 &o) { x += o.x; y += o.y; z += o.z; }
};
struct K5aBody { char pad0[32]; float level; char pad1[4]; K5aVec3 vel; };
extern "C" const float w3d_f32_8037a0d0[];
extern "C" const float w3d_f32_8037a0d4[];
extern "C" const float w3d_f32_8037a0d8[];
extern "C" const float w3d_f32_8037a0dc[];
extern "C" int w3d_auto_8015fd1c(K5aBody *self);

extern "C" void k5a_body_ease_and_grow_80067524(K5aBody *self)
{
    float level = self->level;
    float target = w3d_f32_8037a0d0[0];
    if (level < target)
        self->level = level + (target - level) * w3d_f32_8037a0d4[0];
    else if (level > target)
        self->level = level - (target - level) * w3d_f32_8037a0d8[0];
    float k = w3d_f32_8037a0dc[0];
    self->vel.add(self->vel.scaled(k));
    if (self->vel.y < k)
        w3d_auto_8015fd1c(self);
}
