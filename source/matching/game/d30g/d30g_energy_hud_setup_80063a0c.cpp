/* Worms 3D GameCube PAL 0x80063a0c. Energy HUD setup: caches the HUD.Energy tweakables in reference slots, loads the team energy gradient, flag and font resources with scales from the tweakables, then runs the layout and property updates. Field names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVtable *vtable; };
struct Vec { float x, y, z; };
struct Drawn;
struct DrawnVtable { void *u[21]; int (*scale)(Drawn *, Vec *, int); };
struct Drawn { DrawnVtable *vtable; };
struct Ref {
    Object *value;
    Ref(const Ref &);
    Ref() {}
    ~Ref() { if (value) value->vtable->release(value); }
};
struct String;
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
struct String {
    char *text;
    String(const char *);
    String(const String &);
    ~String() { string_finish_8020c5c4(this); string_release_80341588(this); }
};
struct Key { const char *text; };
struct Self {
    char u0[28]; Drawn *gradient; Drawn *flag; Object *font; char u40[20]; Vec colour; char u72[32];
    Object *textScale; Object *barSpacing; Object *offScreen; Object *onScreen; Object *textXOffset; Object *barXOffset; Object *flagXScale; Object *flagYScale; Object *scrollSpeed; Object *decreaseRate; Object *barHeight;
};
extern const char s_80379bfc[], s_80379c14[], s_80379c2c[], s_80379c44[], s_80379c58[], s_80379c70[], s_80379c88[], s_80379ca0[], s_80379cb8[], s_80379cd0[], s_80379ce8[], s_80379d00[], s_80379d10[], s_80379d24[];
extern float one_80379d2c[];
extern "C" int lookup_800fc1b0(Key *, void *);
extern "C" Object *float_cast_80342a74(Object *);
extern "C" Object *vector_cast_80342fa4(Object *);
extern "C" int set_name_8015adf4(String *, void *, int);
extern "C" float read_float_80178df0(Object *);
extern "C" const Vec *read_vector_80178ec4(Object *);
extern "C" void layout_80064a80(Self *);
extern "C" Drawn *font_cast_80343580(Object *);
extern "C" int font_flags_8018d324(Drawn *, int);
extern "C" void update_800642ac(Self *);
extern "C" void update_80064198(Self *);
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
extern "C" void w3d_d30g_energy_hud_setup_80063a0c(Self *self)
{
    READ(textScale, s_80379bfc, float_cast_80342a74, 0)
    READ(barSpacing, s_80379c14, float_cast_80342a74, 0)
    READ(offScreen, s_80379c2c, vector_cast_80342fa4, 0)
    READ(onScreen, s_80379c44, vector_cast_80342fa4, 0)
    {
        Object *zero = 0;
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
    Vec *q = &v;
    float one = one_80379d2c[0];
    v.x = one;
    q->y = one;
    q->z = one;
    v.x = read_float_80178df0(self->flagXScale);
    v.y = read_float_80178df0(self->flagYScale);
    self->flag->vtable->scale(self->flag, q, 0);
    layout_80064a80(self);
    LOAD(font, s_80379d24)
    Drawn *font = font_cast_80343580(self->font);
    Vec size;
    float t = read_float_80178df0(self->textScale);
    size.x = t; size.y = t; size.z = t;
    font->vtable->scale(font, &size, 0);
    font_flags_8018d324(font, 8);
    self->colour = *read_vector_80178ec4(self->offScreen);
    update_800642ac(self);
    update_80064198(self);
}
