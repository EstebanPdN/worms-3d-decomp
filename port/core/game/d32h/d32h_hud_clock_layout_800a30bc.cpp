#include "w3d_ptr.h"
#line 1 "d32h_hud_clock_layout_800a30bc.cpp"
// GWMP8P rev0 0x800a30bc. HUD clock layout: places the clock background and
// digit meshes from settings; eases the clock position toward its target by
// a factor of 0.1 and interpolates the width between two settings by the
// clock height.
struct Object;
struct ObjectVtable { Ptr32<void> unknown00[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
inline Ptr32<void> Slot(Ptr32<Object> o, int off) { return *(Ptr32<Ptr32<void>>)((Ptr32<char>)o->vtable + off); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) { Vec r; r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; return r; }
inline Vec operator*(const Vec &a, float k) { Vec r; r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; return r; }
extern "C" Object *castM_8034380c(Object *);
extern "C" Ptr32<const Vec> value_80178ec4(Ptr32<Object>);
extern "C" float number_80178df0(Ptr32<Object>);
extern "C" int flag_80178d1c(Ptr32<Object>);
extern "C" Ptr32<Vec> positions_80189518(Ptr32<Object>);
typedef Ptr32<int (Ptr32<Object>, int)> SetFn;
struct Clock {
    char unknown0[40]; Vec v40; Ptr32<Object> o52; Ptr32<Object> o56;
    char unknown60[28]; Ptr32<Object> f88; Ptr32<Object> f92; Ptr32<Object> f96; char unknown100[4]; Ptr32<Object> f104; Ptr32<Object> f108; Ptr32<Object> f112; Ptr32<Object> f116; char unknown120[16]; Ptr32<Object> f136; Ptr32<Object> f140; Ptr32<Object> f144; int f148, f152; Ptr32<Object> f156; Ptr32<Object> f160; char unknown164[8]; float f172;
};
extern "C" void d32h_hud_clock_layout_800a30bc(Ptr32<Clock> self) {
    Ptr32<Object> ma = castM_8034380c(self->o56);
    Ptr32<Object> mb = castM_8034380c(self->o52);
    Vec v;
    if (self->f148 && self->f152) {
        if (flag_80178d1c(self->f156)) v = *value_80178ec4(self->f140);
        else v = *value_80178ec4(self->f160);
        positions_80189518(mb)[0] = v;
        v.x += number_80178df0(self->f116);
        positions_80189518(mb)[1] = v;
        self->v40 += (*value_80178ec4(self->f136) - self->v40) * 0.1f;
        v = self->v40;
    } else {
        self->v40 += (*value_80178ec4(self->f144) - self->v40) * 0.1f;
        v = self->v40;
    }
    Vec keep(v);
    Ptr32<const Vec> top = value_80178ec4(self->f104);
    float span = top->y - value_80178ec4(self->f96)->y;
    float frac = (self->f172 - value_80178ec4(self->f96)->y) / span;
    float lo = number_80178df0(self->f88);
    float w = (number_80178df0(self->f92) - lo) * frac + lo;
    v.y += number_80178df0(self->f112);
    v.x += number_80178df0(self->f108);
    positions_80189518(ma)[2] = v;
    float half = w * 0.75f;
    v.x -= half;
    positions_80189518(ma)[1] = v;
    v.x -= w;
    positions_80189518(ma)[0] = v;
    v = keep;
    v.x += number_80178df0(self->f108);
    v.y += number_80178df0(self->f112);
    v.x += half;
    positions_80189518(ma)[3] = v;
    v.x += w;
    positions_80189518(ma)[4] = v;
    if (!flag_80178d1c(self->f156)) ((SetFn)Slot(self->o56, 88))(self->o56, 0);
}


