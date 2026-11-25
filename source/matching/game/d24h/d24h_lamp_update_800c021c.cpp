// Lamp update (Worms 3D GameCube PAL, 0x800c021c, 548 bytes).
//
// Field names are inferred. Copies through an inline helper taking const
// references give the original's direct frame loads; a plain assignment
// from a named vector uses a base register.

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    Vec3 operator*(float k) const { return Vec3(x * k, y * k, z * k); }
    Vec3 operator+(const Vec3 &o) const { Vec3 r(x + o.x, y + o.y, z + o.z); return r; }
    void operator*=(const Vec3 &o) { x *= o.x; y *= o.y; z *= o.z; }
    Vec3 Scale(const Vec3 &o) const { return Vec3(x * o.x, y * o.y, z * o.z); }
};
extern Vec3 lbl_8043c3ac[], lbl_8043c3b8[], lbl_8043c3c4[], lbl_8043c3d0[];
extern float lbl_80382f4c[];   // 0.0f; the owned pool starts 8-byte aligned after it.
extern int lbl_804aada8;
extern unsigned lbl_804b1764;
extern "C" int fn_800c06a0(int);
extern "C" int fn_800b0824(const Vec3 *, const Vec3 *, const Vec3 *, int, int);
struct LightData { unsigned char u0[120]; Vec3 a120; Vec3 a132; unsigned char u144[12]; Vec3 a156; };
struct Lamp {
    Vec3 pos;
    LightData *data;    // +12
    unsigned char u16[4];
    float power;        // +20
    unsigned char u24[8];
    float reach;        // +32
    Vec3 colour;        // +36
    Vec3 tint;          // +48
};
inline void SetLights(Lamp *self, const Vec3 &a, const Vec3 &b) { self->data->a120 = a; self->data->a132 = b; }
extern "C" void w3d_d24h_lamp_update_800c021c(Lamp *self) {
    Vec3 start;
    fn_800c06a0(lbl_804aada8);
    Vec3 up(lbl_80382f4c[0], lbl_80382f4c[0], lbl_80382f4c[0]);
    start = self->pos + *lbl_8043c3b8 * self->reach;
    fn_800b0824(&start, lbl_8043c3b8, &up, 1000, 1);
    float ratio;
    if (lbl_804b1764 <= 999) ratio = (float)lbl_804b1764 / 1000.0f;
    else ratio = 1.0f;
    ratio *= self->power;
    Vec3 light = *lbl_8043c3c4 * ratio;
    self->tint = light;
    light.x *= self->colour.x;
    light.y *= self->colour.y;
    light.z *= self->colour.z;
    Vec3 ambient(lbl_8043c3d0->x * self->colour.x, lbl_8043c3d0->y * self->colour.y, lbl_8043c3d0->z * self->colour.z);
    SetLights(self, light, ambient);
    self->data->a156 = *lbl_8043c3ac;
}
