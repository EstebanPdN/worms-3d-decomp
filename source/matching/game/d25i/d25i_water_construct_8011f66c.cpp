// d25i: 0x8011f66c. Water object constructor: base constructor 0x8015a0d4 with
// type 15, vtable 0x80410ae0 at +72, clears, an embedded handle member at +144
// configured with slot 0, word 23 and 5.0f, then resolves the retained
// settings Water.Level, Land.Radius, Land.Center and Water.RiseSpeed.Graphic.
// Handles have one word and a user copy constructor.
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

struct WaterMember { unsigned char unknown00[8]; };
struct Water {
    unsigned char unknown00[72];
    const void *vtable;       // +72
    int a;                    // +76
    int b;                    // +80
    unsigned char unknown54[4];
    int c;                    // +88
    unsigned char unknown5c[52];
    WaterMember member;       // +144
    Object *level;            // +152
    Object *radius;           // +156
    Object *center;           // +160
    Object *rise;             // +164
};
extern "C" int base_8015a0d4(Water *, const char *, int);
extern "C" void * member_init_80126184(WaterMember *);
extern "C" void member_slot_801262e4(WaterMember *, int);
extern "C" void member_word_8012632c(WaterMember *, int);
extern "C" void member_float_8012629c(WaterMember *, float);
extern "C" Object *as_float_80342a74(Object *);
extern "C" Object *as_vector_80342fa4(Object *);
extern const void *const vtable_80410ae0[];
extern const char n_8039b5b0[], n_8039b5bc[], n_8039b5c8[], n_8039b5d4[];
extern const float f_8039b5ec[];
static inline void load_float(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_float_80342a74(found.value));
}
static inline void load_vector(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    assign(slot, as_vector_80342fa4(found.value));
}
extern "C" Water *d25i_water_construct_8011f66c(Water *self, const char *name) {
    base_8015a0d4(self, name, 15);
    self->c = 0;
    self->vtable = vtable_80410ae0;
    member_init_80126184(&self->member);
    self->level = 0;
    self->radius = 0;
    self->center = 0;
    Object *&rise = self->rise;
    rise = 0;
    self->a = -1;
    self->b = -1;
    member_slot_801262e4(&self->member, 0);
    member_word_8012632c(&self->member, 23);
    member_float_8012629c(&self->member, f_8039b5ec[0] /* 5.0f */);
    load_float(self->level, n_8039b5b0);
    load_float(self->radius, n_8039b5bc);
    load_vector(self->center, n_8039b5c8);
    load_float(rise, n_8039b5d4);
    return self;
}
