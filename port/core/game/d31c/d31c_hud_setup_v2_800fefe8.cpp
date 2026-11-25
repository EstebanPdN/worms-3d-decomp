#include "w3d_ptr.h"
#line 1 "d31c_hud_setup_v2_800fefe8.cpp"
// d31c: 0x800fefe8. HUD panel set-up: loads the panel meshes and settings by name, binds the score sink and crosshair meshes and clears their flags. Replaces the held d31c_hud_setup_800fefe8 without its dead pointer set. Names are inferred; classes are partial views.
// HUD panel set-up.
struct String_;
extern "C" Ptr32<String_> string_from_text_8020bb54(Ptr32<void>, Ptr32<const char>);
struct String {
    Ptr32<char> text;
    String() {}
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(Ptr32<String>);
extern "C" void string_release_80341588(Ptr32<String>);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Vec3 { float x, y, z; };
struct Pair { float a, b; };
struct Object;
struct ObjectVt { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVt> vt; };
struct Ref {
    Ptr32<Object> value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vt->release(value); }
};
struct Key { Ptr32<const char> name; };
struct Sink;
struct SinkV { Ptr32<void> u[19]; Ptr32<int (Ptr32<Sink>, Ptr32<const Vec3>, int)> a; Ptr32<void> u80; Ptr32<int (Ptr32<Sink>, Ptr32<const Vec3>, int)> c; };
struct Sink { Ptr32<SinkV> vt; };
struct Mesh;
extern "C" int load_8015adf4(const String &, Ptr32<void>, unsigned char);
extern "C" int read_setting_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" int read_vec_800fc2f0(Ptr32<Key>, Ptr32<Vec3>);
extern "C" Ptr32<Object> cast_80342a74(Ptr32<Object>);
extern "C" Ptr32<Object> cast_80342a78(Ptr32<Object>);
extern "C" Ptr32<Object> cast_80342fa4(Ptr32<Object>);
extern "C" Ptr32<const Vec3> vec_80178ec4(Ptr32<Object>);
extern "C" Ptr32<Mesh> as_mesh_8034380c(Ptr32<void>);
extern "C" int mesh_set_80189450(Ptr32<Mesh>, int);
extern "C" int mesh_alloc_8018920c(Ptr32<Mesh>, int);
extern "C" Ptr32<unsigned char> flags_80189704(Ptr32<Mesh>);
extern "C" Ptr32<Pair> sizes_8018963c(Ptr32<Mesh>);
struct Hud { char u0[28]; Ptr32<Sink> h28; Ptr32<void> h32; Ptr32<void> h36; Vec3 v40; int u52; char u56[12]; Ptr32<Object> o68; Ptr32<Object> o72; Ptr32<Object> o76; Ptr32<Object> o80; Ptr32<Object> o84; Ptr32<Object> o88; Ptr32<Object> o92; };
template <Ptr32<Object> (*CAST)(Ptr32<Object>)>
inline void load(Ptr32<Object> &slot, Ptr32<const char> name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    Ptr32<Object> v = CAST(found.value);
    if (v) v->vt->retain(v);
    if (slot) slot->vt->release(slot);
    slot = v;
}
static inline int read_key(Ptr32<Key> key, Ptr32<int> to) { return read_setting_800fc1b0(key, to); }
extern const char s0_8039828c[], s1_80398298[], s2_803982b0[], s3_803982c4[], s4_803982dc[], s5_803982f4[], s6_8039830c[], s7_80398328[], s8_80398340[], s9_80398354[], s10_80398360[], s11_80398370[];
extern "C" void d31c_hud_setup_v2_800fefe8(Ptr32<Hud> self) {
    { String n; string_from_text_8020bb54(&n, s0_8039828c); load_8015adf4(n, &self->h28, 255); }
    load<cast_80342a74>(self->o68, s1_80398298);
    load<cast_80342a74>(self->o72, s2_803982b0);
    load<cast_80342a78>(self->o76, s3_803982c4);
    load<cast_80342fa4>(self->o80, s4_803982dc);
    load<cast_80342fa4>(self->o84, s5_803982f4);
    load<cast_80342fa4>(self->o88, s6_8039830c);
    load<cast_80342a74>(self->o92, s7_80398328);
    Ptr32<const Vec3> pv = vec_80178ec4(self->o88);
    Ptr32<Vec3> d = &self->v40;
    *d = *pv;
    self->h28->vt->a(self->h28, d, 0);
    Key k;
    k.name = s8_80398340;
    Vec3 t;
    read_vec_800fc2f0(&k, &t);
    self->h28->vt->c(self->h28, &t, 0);
    { String n; string_from_text_8020bb54(&n, s9_80398354); load_8015adf4(n, &self->h32, 255); }
    Ptr32<Mesh> m = as_mesh_8034380c(self->h32);
    mesh_set_80189450(m, 1);
    mesh_alloc_8018920c(m, 16);
    Ptr32<const Vec3> cp = vec_80178ec4(self->o80);
    float cx = cp->x, cy = cp->y, cz = cp->z;
    Vec3 c; c.x = cx; c.y = cy; c.z = cz;
    for (unsigned i = 0; i < 16; i++) {
        flags_80189704(m)[i] = 0;
        Ptr32<Pair> p = sizes_8018963c(m);
        float ax = c.x, ay = c.y;
        Pair &q = p[i];
        q.a = ax;
        q.b = ay;
    }
    { String n; string_from_text_8020bb54(&n, s10_80398360); load_8015adf4(n, &self->h36, 255); }
    Ptr32<Mesh> m2 = as_mesh_8034380c(self->h36);
    mesh_set_80189450(m2, 4);
    mesh_alloc_8018920c(m2, 1);
    flags_80189704(m2)[0] = 0;
    Key k2;
    k2.name = s11_80398370;
    read_key(&k2, &self->u52);
}


