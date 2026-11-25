// GWMP8P rev0 0x800a30bc. HUD clock layout: places the clock background and
// digit meshes from settings; eases the clock position toward its target by
// a factor of 0.1 and interpolates the width between two settings by the
// clock height.
struct Object;
struct ObjectVtable { void *unknown00[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
inline void *Slot(Object *o, int off) { return *(void **)((char *)o->vtable + off); }
struct Vec {
    float x, y, z;
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec &o) { float a = o.x, b = o.y, c = o.z; x = a; y = b; z = c; }
    void operator+=(const Vec &o) { x += o.x; y += o.y; z += o.z; }
};
inline Vec operator-(const Vec &a, const Vec &b) return r { r.x = a.x - b.x; r.y = a.y - b.y; r.z = a.z - b.z; }
inline Vec operator*(const Vec &a, float k) return r { r.x = a.x * k; r.y = a.y * k; r.z = a.z * k; }
extern "C" Object *castM_8034380c(Object *);
extern "C" const Vec *value_80178ec4(Object *);
extern "C" float number_80178df0(Object *);
extern "C" int flag_80178d1c(Object *);
extern "C" Vec *positions_80189518(Object *);
typedef int (*SetFn)(Object *, int);
struct Clock {
    char unknown0[40]; Vec v40; Object *o52, *o56;
    char unknown60[28]; Object *f88, *f92, *f96; char unknown100[4]; Object *f104, *f108, *f112, *f116; char unknown120[16]; Object *f136, *f140, *f144; int f148, f152; Object *f156, *f160; char unknown164[8]; float f172;
};
extern "C" void d32h_hud_clock_layout_800a30bc(Clock *self) {
    Object *ma = castM_8034380c(self->o56);
    Object *mb = castM_8034380c(self->o52);
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
    const Vec *top = value_80178ec4(self->f104);
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
