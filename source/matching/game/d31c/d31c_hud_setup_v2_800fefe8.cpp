// d31c: 0x800fefe8. HUD panel set-up: loads the panel meshes and settings by name, binds the score sink and crosshair meshes and clears their flags. Replaces the held d31c_hud_setup_800fefe8 without its dead pointer set. Names are inferred; classes are partial views.
// HUD panel set-up.
struct String_;
extern "C" String_ *string_from_text_8020bb54(void *, const char *);
struct String {
    char *text;
    String() {}
    String(const String &);
    ~String();
};
extern "C" void string_finish_8020c5c4(String *);
extern "C" void string_release_80341588(String *);
inline String::~String() {
    string_finish_8020c5c4(this);
    string_release_80341588(this);
}
struct Vec3 { float x, y, z; };
struct Pair { float a, b; };
struct Object;
struct ObjectVt { void *u[3]; void (*retain)(Object *); void (*release)(Object *); };
struct Object { ObjectVt *vt; };
struct Ref {
    Object *value;
    Ref() { value = 0; }
    Ref(const Ref &);
    ~Ref() { if (value) value->vt->release(value); }
};
struct Key { const char *name; };
struct Sink;
struct SinkV { void *u[19]; int (*a)(Sink *, const Vec3 *, int); void *u80; int (*c)(Sink *, const Vec3 *, int); };
struct Sink { SinkV *vt; };
struct Mesh;
extern "C" int load_8015adf4(const String &, void *, unsigned char);
extern "C" int read_setting_800fc1b0(Key *, void *);
extern "C" int read_vec_800fc2f0(Key *, Vec3 *);
extern "C" Object *cast_80342a74(Object *);
extern "C" Object *cast_80342a78(Object *);
extern "C" Object *cast_80342fa4(Object *);
extern "C" const Vec3 *vec_80178ec4(Object *);
extern "C" Mesh *as_mesh_8034380c(void *);
extern "C" int mesh_set_80189450(Mesh *, int);
extern "C" int mesh_alloc_8018920c(Mesh *, int);
extern "C" unsigned char *flags_80189704(Mesh *);
extern "C" Pair *sizes_8018963c(Mesh *);
struct Hud { char u0[28]; Sink *h28; void *h32, *h36; Vec3 v40; int u52; char u56[12]; Object *o68, *o72, *o76, *o80, *o84, *o88, *o92; };
template <Object *(*CAST)(Object *)>
inline void load(Object *&slot, const char *name) {
    Key key;
    key.name = name;
    Ref found;
    read_setting_800fc1b0(&key, &found);
    Object *v = CAST(found.value);
    if (v) v->vt->retain(v);
    if (slot) slot->vt->release(slot);
    slot = v;
}
static inline int read_key(Key *key, int *to) { return read_setting_800fc1b0(key, to); }
extern const char s0_8039828c[], s1_80398298[], s2_803982b0[], s3_803982c4[], s4_803982dc[], s5_803982f4[], s6_8039830c[], s7_80398328[], s8_80398340[], s9_80398354[], s10_80398360[], s11_80398370[];
extern "C" void d31c_hud_setup_v2_800fefe8(Hud *self) {
    { String n; string_from_text_8020bb54(&n, s0_8039828c); load_8015adf4(n, &self->h28, 255); }
    load<cast_80342a74>(self->o68, s1_80398298);
    load<cast_80342a74>(self->o72, s2_803982b0);
    load<cast_80342a78>(self->o76, s3_803982c4);
    load<cast_80342fa4>(self->o80, s4_803982dc);
    load<cast_80342fa4>(self->o84, s5_803982f4);
    load<cast_80342fa4>(self->o88, s6_8039830c);
    load<cast_80342a74>(self->o92, s7_80398328);
    const Vec3 *pv = vec_80178ec4(self->o88);
    Vec3 *d = &self->v40;
    *d = *pv;
    self->h28->vt->a(self->h28, d, 0);
    Key k;
    k.name = s8_80398340;
    Vec3 t;
    read_vec_800fc2f0(&k, &t);
    self->h28->vt->c(self->h28, &t, 0);
    { String n; string_from_text_8020bb54(&n, s9_80398354); load_8015adf4(n, &self->h32, 255); }
    Mesh *m = as_mesh_8034380c(self->h32);
    mesh_set_80189450(m, 1);
    mesh_alloc_8018920c(m, 16);
    const Vec3 *cp = vec_80178ec4(self->o80);
    float cx = cp->x, cy = cp->y, cz = cp->z;
    Vec3 c; c.x = cx; c.y = cy; c.z = cz;
    for (unsigned i = 0; i < 16; i++) {
        flags_80189704(m)[i] = 0;
        Pair *p = sizes_8018963c(m);
        float ax = c.x, ay = c.y;
        Pair &q = p[i];
        q.a = ax;
        q.b = ay;
    }
    { String n; string_from_text_8020bb54(&n, s10_80398360); load_8015adf4(n, &self->h36, 255); }
    Mesh *m2 = as_mesh_8034380c(self->h36);
    mesh_set_80189450(m2, 4);
    mesh_alloc_8018920c(m2, 1);
    flags_80189704(m2)[0] = 0;
    Key k2;
    k2.name = s11_80398370;
    read_key(&k2, &self->u52);
}
