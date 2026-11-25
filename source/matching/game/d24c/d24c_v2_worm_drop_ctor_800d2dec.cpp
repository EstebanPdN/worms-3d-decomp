// d24c cleaner source for 0x800d2dec (376 bytes), one-word Ref with a real release held
// in an inline helper. Same behaviour as d24c_worm_drop_ctor_800d2dec.
typedef unsigned int size_t;
struct String {
    char *text;
    unsigned opaque;
    String(const char *);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Object;
struct ObjectVtable {
    void *unknown00[3];
    void (*retain)(Object *);       // +12
    void (*release)(Object *);      // +16
};
struct Object { ObjectVtable *vtable; };
struct Key { const char *text; };
extern "C" int read_800fc1b0(Key *, void *);

struct Ref {
    Object *value;
    ~Ref() { if (value) value->vtable->release(value); }
};
struct Vec3 {
    float x, y, z;
    Vec3() {}
    void set(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Drop {
    unsigned char u0[72];
    const void *vtable;  // +72
    Vec3 v76, v88, v100, v112, v124;
    int w136;            // +136
    Vec3 v140, v152, v164;
    float f176, f180, f184, f188, f192;
    unsigned char u196[4];
    unsigned char b200;  // +200
    Object *ref;         // +204
};
extern "C" void base_8015a0d4(Drop *, int, int);
extern "C" Object *as_a_80342a74(Object *);
extern const unsigned char vtable_8040fc90[];
extern const float z_80388cac[], one_80388cb0[], k_80388cb4[];
extern const char name_80388c94[];
inline void read_ref(Drop *self, Key *key) {
    Ref r;
    r.value = 0;
    read_800fc1b0(key, &r);
    Object *o = as_a_80342a74(r.value);
    if (o) o->vtable->retain(o);
    if (self->ref) self->ref->vtable->release(self->ref);
    self->ref = o;
}
extern "C" Drop *d24c_v2_worm_drop_ctor_800d2dec(Drop *self, int a, int unused, int b) {
    base_8015a0d4(self, a, b);
    self->vtable = vtable_8040fc90;
    self->w136 = 0;
    self->ref = 0;
    float z = z_80388cac[0];
    self->v140.set(z, z, z);
    self->v152.set(z, z, z);
    self->v164.set(z, z, z);
    float one = one_80388cb0[0];
    self->f176 = z;
    self->f180 = z;
    self->f184 = z;
    self->f188 = one;
    self->f192 = one;
    self->b200 = 0;
    self->v76.set(z, z, z);
    float k = k_80388cb4[0];
    self->v88.set(k, z, z);
    self->v100.set(z, k, z);
    self->v112.set(z, z, z);
    self->v124.set(z, z, z);
    Key key;
    key.text = name_80388c94;
    read_ref(self, &key);
    return self;
}
