// d25c: 0x800e4414. Update a projectile: step the sub-object at +28, then zero the hit vector (flag 16) or copy the
// origin to it and notify the target (flag 64). The target check keeps a checked cast with two equal arms;
// it folds after allocation, leaving the original's unused compare. Names are inferred.
extern const float zero_8038a0c8[];
struct Vec3 { float x, y, z; void reset() { float v = zero_8038a0c8[0]; x = v; y = v; z = v; } };
struct Type { unsigned char u[20]; const Type *parent; };
struct Target {
    struct V { void *u[5]; const Type *(*type)(Target *); void *u6[5]; void (*attach)(Target *, void *, Vec3 *); } *vtable;
};
struct Spawn { char u0[228]; struct V { void *u[4]; void (*apply)(Spawn *, int, Vec3 *); } *vtable; };
struct Self {
    char u0[68];
    int handle;         // +68
    char u72[24];
    Vec3 source;        // +96
    Vec3 out;           // +108
    char u120[24];
    int key;            // +144
    char u148[28];
    int state;          // +176
    int flags;          // +180
};
extern "C" void step_800df7b8(void *, void *);
extern "C" Target *lookup_80164fc8(int);
extern "C" int query_800dfd48(Spawn *, int);
extern const Type type_80360e10[], type_80360cf0[];
extern const float zero_8038a0c8[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d25c_bullet_update_800e4414(Self *self, void *a, void *b) {
    step_800df7b8((char *)self + 28, a);
    int f = self->flags;
    if (f & 16) {
        self->out.reset();
        return;
    }
    if (f & 64) {
        self->out = self->source;
        Target *t = lookup_80164fc8(self->handle);
        if (t) {
            if (is_a(t->vtable->type(t), type_80360e10)) {
                t->vtable->attach(t, b, &self->out);
                return;
            }
            Spawn *s;
            if (is_a(t->vtable->type(t), type_80360cf0)) s = t ? (Spawn *)((char *)t + 28) : 0;
            else s = t ? (Spawn *)((char *)t + 28) : 0;
            if (query_800dfd48(s, self->key)) {
                s->vtable->apply(s, self->key, &self->out);
                return;
            }
        }
        self->state = 3;
    }
}
