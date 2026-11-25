// d27c: 0x800d6b44. Orbit camera constructor: base constructor 0x8015a0d4 with type 4, vtable 0x8040fd38 at +72, clears, then resolves the retained settings Camera.Orbit.Speed, AdditionalRadius, Height, Water.Level and IgnoreInput. Names are inferred.
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *name; };
struct Ref {
    Object *value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
};
extern "C" int read_setting_800fc1b0(Key *, void *);
static inline void assign(Object *&slot, Object *value) {
    if (value) value->vtable->retain(value);
    if (slot) slot->vtable->release(slot);
    slot = value;
}

struct Orbit {
    unsigned char u0[72];
    const void *vtable;
    Object *speed, *radius, *height, *ignore, *level;
};
extern "C" int base_8015a0d4(Orbit *, const char *, int);
extern "C" Object *as_float_80342a74(Object *);
extern "C" Object *as_int_80342a78(Object *);
extern const void *const vtable_8040fd38[];
extern const char n_80389028[], n_8038903c[], n_8038905c[], n_80389070[], n_8038907c[];
static inline void load_float(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_float_80342a74(found.value));
}
static inline void load_int(Object *&slot, const char *name) {
    Ref found;
    Key key;
    key.name = name;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_int_80342a78(found.value));
}
extern "C" Orbit *d27c_orbit_camera_construct_800d6b44(Orbit *self, const char *name) {
    base_8015a0d4(self, name, 4);
    Object *&level = self->level;
    self->vtable = vtable_8040fd38;
    self->speed = 0;
    self->radius = 0;
    self->height = 0;
    self->ignore = 0;
    self->level = 0;
    load_float(self->speed, n_80389028);
    load_float(self->radius, n_8038903c);
    load_float(self->height, n_8038905c);
    load_float(level, n_80389070);
    load_int(self->ignore, n_8038907c);
    return self;
}
