#include "w3d_ptr.h"
#line 1 "d29g_sheep_motion_step_800713c0.cpp"
/* Worms 3D GameCube PAL 0x800713c0. Super sheep motion step: runs the debug draw when enabled; while flying free (+332 or +120) it integrates the position at +48 with the velocity at +60 and the frame step; otherwise it reads the speed from the handle at +192, updates the orientation and sets +48 to the rotation's z axis times the speed. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    Vec operator*(float k) const { Vec r; r.x = x * k; r.y = y * k; r.z = z * k; return r; }
    Vec operator+(const Vec &o) const { Vec r; r.x = x + o.x; r.y = y + o.y; r.z = z + o.z; return r; }
};
struct Row { float x, y, z; };
struct Mat {
    Row r[3];
    const Row &R(int i) const { return r[i]; }
    void rotate(Vec &o, const Vec &v) const {
        o.x = v.x * R(0).x + v.y * R(1).x + v.z * R(2).x;
        o.y = v.x * R(0).y + v.y * R(1).y + v.z * R(2).y;
        o.z = v.x * R(0).z + v.y * R(1).z + v.z * R(2).z;
    }
};
struct Handle;
struct Config { char u[640]; float speed; };
struct Sheep { char u0[48]; Vec pos; Vec vel; char u72[120 - 72]; int boosting; Mat m; char u160[192 - 160]; Ptr32<Handle> a192; char u196[332 - 196]; int a332; };
extern "C" {
void fn_80071e30(Ptr32<Sheep>);
Ptr32<Handle> w3d_empty_80341584(Ptr32<Handle>);
Ptr32<Config> w3d_auto_801797b4(Ptr32<Handle>);
void fn_800715b0(Ptr32<Sheep>);
}
extern int debug_804aaae8;
extern unsigned step_804b1944;
extern "C" void w3d_d29g_sheep_motion_step_800713c0(Ptr32<Sheep> self)
{
    if (debug_804aaae8) fn_80071e30(self);
    if (self->a332 || self->boosting) {
        self->pos = self->pos + self->vel * (float)step_804b1944;
    } else {
        Ptr32<Config> c = w3d_auto_801797b4(w3d_empty_80341584(self->a192));
        fn_800715b0(self);
        Vec z(0.0f, 0.0f, 1.0f);
        Vec o;
        self->m.rotate(o, z);
        self->pos = o * c->speed;
    }
}


