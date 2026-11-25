#include "w3d_ptr.h"
#line 1 "d30g_energy_hud_setup_80063a0c.cpp"
/* Worms 3D GameCube PAL 0x80063a0c. Energy HUD setup: caches the HUD.Energy tweakables in reference slots, loads the team energy gradient, flag and font resources with scales from the tweakables, then runs the layout and property updates. Field names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Vec { float x, y, z; };
struct Drawn;
struct DrawnVtable { Ptr32<void> u[21]; Ptr32<int (Ptr32<Drawn>, Ptr32<Vec>, int)> scale; };
struct Drawn { Ptr32<DrawnVtable> vtable; };
struct Ref {
    Ptr32<Object> value;
    Ref(const Ref &);
    Ref() {}
    ~Ref() { if (value) value->vtable->release(value); }
};
struct String;
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Key { Ptr32<const char> text; };
struct Self {
    char u0[28]; Ptr32<Drawn> gradient; Ptr32<Drawn> flag; Ptr32<Object> font; char u40[20]; Vec colour; char u72[32];
    Ptr32<Object> textScale; Ptr32<Object> barSpacing; Ptr32<Object> offScreen; Ptr32<Object> onScreen; Ptr32<Object> textXOffset; Ptr32<Object> barXOffset; Ptr32<Object> flagXScale; Ptr32<Object> flagYScale; Ptr32<Object> scrollSpeed; Ptr32<Object> decreaseRate; Ptr32<Object> barHeight;
};
extern const char s_80379bfc[], s_80379c14[], s_80379c2c[], s_80379c44[], s_80379c58[], s_80379c70[], s_80379c88[], s_80379ca0[], s_80379cb8[], s_80379cd0[], s_80379ce8[], s_80379d00[], s_80379d10[], s_80379d24[];
extern float one_80379d2c[];
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> float_cast_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> vector_cast_80342fa4(Ptr32<Object>);
extern "C" int set_name_8015adf4(Ptr32<String>, Ptr32<void>, int);
extern "C" float read_float_80178df0(Ptr32<Object>);
extern "C" Ptr32<const Vec> read_vector_80178ec4(Ptr32<Object>);
extern "C" void layout_80064a80(Ptr32<Self>);
extern "C" Ptr32<Drawn> font_cast_80343580(Ptr32<Object>);
extern "C" int font_flags_8018d324(Ptr32<Drawn>, int);
extern "C" void update_800642ac(Ptr32<Self>);
extern "C" void update_80064198(Ptr32<Self>);
#define READ(slot, name, cast, zero) { \
    Ref r; \
    r.value = zero; \
    Key k; \
    k.text = name; \
    Ref *p = &r; \
    lookup_800fc1b0(&k, p); \
    Object *o = cast(r.value); \
    if (o) o->vtable->retain(o); \
    if (self->slot) self->slot->vtable->release(self->slot); \
    self->slot = o; \
}
#define LOAD(field, name) { String s(name); set_name_8015adf4(&s, &self->field, 255); }
extern "C" void w3d_d30g_energy_hud_setup_80063a0c(Ptr32<Self> self)
{
    READ(textScale, s_80379bfc, float_cast_80342a74, 0)
    READ(barSpacing, s_80379c14, float_cast_80342a74, 0)
    READ(offScreen, s_80379c2c, vector_cast_80342fa4, 0)
    READ(onScreen, s_80379c44, vector_cast_80342fa4, 0)
    {
        Ptr32<Object> zero = 0;
        READ(textXOffset, s_80379c58, float_cast_80342a74, zero)
        READ(barXOffset, s_80379c70, float_cast_80342a74, zero)
        READ(flagXScale, s_80379c88, float_cast_80342a74, zero)
        READ(flagYScale, s_80379ca0, float_cast_80342a74, zero)
    }
    READ(scrollSpeed, s_80379cb8, float_cast_80342a74, 0)
    READ(decreaseRate, s_80379cd0, float_cast_80342a74, 0)
    READ(barHeight, s_80379ce8, float_cast_80342a74, 0)
    Vec v;
    LOAD(gradient, s_80379d00)
    LOAD(flag, s_80379d10)
    Ptr32<Vec> q = &v;
    float one = one_80379d2c[0];
    v.x = one;
    q->y = one;
    q->z = one;
    v.x = read_float_80178df0(self->flagXScale);
    v.y = read_float_80178df0(self->flagYScale);
    self->flag->vtable->scale(self->flag, q, 0);
    layout_80064a80(self);
    LOAD(font, s_80379d24)
    Ptr32<Drawn> font = font_cast_80343580(self->font);
    Vec size;
    float t = read_float_80178df0(self->textScale);
    size.x = t; size.y = t; size.z = t;
    font->vtable->scale(font, &size, 0);
    font_flags_8018d324(font, 8);
    self->colour = *read_vector_80178ec4(self->offScreen);
    update_800642ac(self);
    update_80064198(self);
}


