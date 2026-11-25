// d25c: 0x800e21b8. Sibling of 0x800e4414: flag 16 queries the hit vector (0x800e25dc) instead of zeroing it. The
// target check keeps a checked cast with two equal arms, which leaves the original's unused compare. Names
// are inferred.
struct Type { unsigned char unknown00[20]; const Type *parent; };
struct Words { int a, b, c; };
struct Target {
    struct V { void *u[5]; const Type *(*type)(Target *); void *u24[5]; void (*hit)(Target *, int, Words *); } *vtable;
};
struct Sub {
    struct V { void *u[4]; void (*hit)(Sub *, int, Words *); } **vtable_slot;
};
struct Part { unsigned char u[228]; struct V { void *u[4]; void (*hit)(Part *, int, Words *); } *vtable; };
struct Bullet {
    unsigned char u0[28];
    unsigned char sub[40];
    int target;          // +68
    unsigned char u72[24];
    Words origin;        // +96
    Words hit;           // +108
    unsigned char u120[24];
    int id144;           // +144
    unsigned char u148[28];
    int state;           // +176
    unsigned flags;      // +180
};
extern "C" void step_800df7b8(void *, void *);
extern "C" int query_800e25dc(Bullet *, Words *);
extern "C" Target *lookup_80164fc8(int);
extern "C" int flag_800dfd48(Part *, int);
extern const Type type_80360e10[], type_80360cf0[];
inline bool is_a(const Type *t, const Type *target) {
    while (t != target) {
        if (t == t->parent) return false;
        t = t->parent;
    }
    return true;
}
extern "C" void d25c_bullet_update_query_800e21b8(Bullet *self, int dt, int when) {
    step_800df7b8(self->sub, (void *)dt);
    if (self->flags & 16) {
        query_800e25dc(self, &self->hit);
        return;
    }
    if (self->flags & 64) {
        self->hit = self->origin;
        Target *o = lookup_80164fc8(self->target);
        if (o) {
            if (is_a(o->vtable->type(o), type_80360e10)) {
                o->vtable->hit(o, when, &self->hit);
                return;
            }
            Part *p;
            if (is_a(o->vtable->type(o), type_80360cf0)) p = o ? (Part *)((char *)o + 28) : 0;
            else p = o ? (Part *)((char *)o + 28) : 0;
            if (flag_800dfd48(p, self->id144)) {
                p->vtable->hit(p, self->id144, &self->hit);
                return;
            }
        }
        self->state = 3;
    }
}
