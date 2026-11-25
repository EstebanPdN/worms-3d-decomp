// Transform setters of a scene node with no owned space, GWMP8P rev0
// 0x80185ba4, 0x80185f10, 0x80186254. Same template as the setters at
// 0x8017a2b0 without the validity test, the space pointer (0x801a3eb0 receives
// null) and the per-target source objects: an unchanged value returns 0 unless
// forced; otherwise the value is stored and a node that is not local and has
// no targets ends in a plain virtual setter. Else the world frame is built
// from rotation, scale and translation and passed to virtual slot +148, a
// frame for the targets is rebuilt from the components the flags byte selects
// unless it is 7, and every target gets the frame and a change notification.
// The unread Vec3 copies in the translation and scale setters are witnessed by
// the original, which writes all three floats to sp+8 and never reads them.
// The zero literals are the pool words 0x803a7aa4, 0x803a7aa8 and 0x803a7aac.

struct Vec3 {
    float x, y, z;
    Vec3();
    Vec3(const Vec3 &o) { x = o.x; y = o.y; z = o.z; }
    bool operator==(const Vec3 &o) const
    {
        return *(const int *)&x == *(const int *)&o.x
            && *(const int *)&y == *(const int *)&o.y
            && *(const int *)&z == *(const int *)&o.z;
    }
};

struct Frame {
    float r[9];
    Vec3 t;
    void set(const Vec3 &v) { t = v; }
    void zero(float v) { t.x = v; t.y = v; t.z = v; }
};

extern "C" void fn_801a3eb0(const Vec3 *rotation, int space, Frame *out);
extern "C" void fn_801f6448(Frame *frame, float x, float y, float z);
extern "C" void fn_801f6034(Frame *frame);
extern "C" void fn_801f740c(Frame *out, const Frame *a, const Frame *b);
extern float float_803a7aa4[];
extern float float_803a7aa8[];
extern float float_803a7aac[];

struct World;

struct Target {
    virtual void slot_8();
    virtual void slot_12();
    virtual void slot_16();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_32();
    virtual void slot_36();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_52();
    virtual void slot_56();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_72();
    virtual void changed_translation(int a, int b);
    virtual void changed_rotation(int a, int b);
    virtual void changed_scale(int a, int b);
    virtual void slot_88();
    virtual void slot_92();
    virtual void slot_96();
    virtual int translation_key();
    virtual int rotation_key();
    virtual int scale_key();
    virtual void slot_112();
    virtual void slot_116();
    virtual void slot_120();
    virtual void slot_124();
    virtual void update(const void *m);
};

struct Maker {
    virtual void slot_8();
    virtual void slot_12();
    virtual void slot_16();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_32();
    virtual void slot_36();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_52();
    virtual void slot_56();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_72();
    virtual void make(void *a, World *w, void **out);
};

struct Inner { char u[108]; void *space; };
struct World { char u[48]; Inner *inner; };

struct Targets {
    Target **start, **finish, **cap;
    unsigned size() const { return finish - start; }
    Target **end() { return finish; }
};

struct Makers { int a, b; Maker **data; };
struct Sources { int a, b; void **data; };

struct NodeBase {
    virtual void slot_8();
    virtual void slot_12();
    virtual void slot_16();
    virtual void slot_20();
    virtual void slot_24();
    virtual int is_local();
    virtual void slot_32();
    virtual void slot_36();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_52();
    virtual void slot_56();
    virtual void slot_60();
    virtual void slot_64();
    virtual void slot_68();
    virtual void slot_72();
    virtual void slot_76();
    virtual void slot_80();
    virtual void slot_84();
    virtual void slot_88();
    virtual void slot_92();
    virtual void slot_96();
    virtual void slot_100();
    virtual void slot_104();
    virtual void slot_108();
    virtual void slot_112();
    virtual void slot_116();
    virtual void slot_120();
    virtual void slot_124();
    virtual void slot_128();
    virtual void slot_132();
    virtual void slot_136();
    virtual int plain_translation(const Vec3 *);
    virtual int plain_rotation(const Vec3 *);
    virtual int world_frame(const Frame *);
    virtual int plain_scale(const Vec3 *);
};

struct Node : NodeBase {
    char u4[8];
    Vec3 translation;
    Vec3 rotation;
    Vec3 scale;
    char u48[4];
    unsigned char flags;
    char u53[3];
    Frame local_frame;
    Targets kids;
    char u116[4];
    World *world;
    char u124[4];
    Makers makers;
    Sources sources;
    char u152[12];
    int valid;
};

extern "C" int d26j_set_translation_80185ba4(Node *self, const Vec3 *k, int force)
{
    if (!force && self->translation == *k) return 0;
    self->translation = *k;
    Targets *kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_translation(&self->translation);
    Vec3 old(self->translation);
    Frame b;
    Frame a;
    Frame *pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aa4[0];
            Frame *q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Target **it = self->kids.start;
    Target **end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Target *t = *it;
        t->changed_translation(t->translation_key(), 1);
    }
    return result;
}

extern "C" int d26j_set_rotation_80185f10(Node *self, const Vec3 *k, int force)
{
    if (!force && self->rotation == *k) return 0;
    self->rotation = *k;
    Targets *kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_rotation(&self->rotation);
    Frame b;
    Frame a;
    Frame *pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aa8[0];
            Frame *q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Target **it = self->kids.start;
    Target **end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Target *t = *it;
        t->changed_rotation(t->rotation_key(), 1);
    }
    return result;
}

extern "C" int d26j_set_scale_80186254(Node *self, const Vec3 *k, int force)
{
    if (!force && self->scale == *k) return 0;
    self->scale = *k;
    Targets *kids = &self->kids;
    if (!self->is_local() && kids->size() == 0)
        return self->plain_scale(&self->scale);
    Vec3 old(self->scale);
    Frame b;
    Frame a;
    Frame *pa = &a;
    fn_801a3eb0(&self->rotation, 0, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    int result;
    if (self->is_local()) {
        fn_801f740c(&b, &a, &self->local_frame);
        result = self->world_frame(&b);
    } else {
        b = a;
        result = self->world_frame(&a);
    }
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, 0, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7aac[0];
            Frame *q = &a;
            q->zero(zero);
        }
        if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
        else b = a;
    }
    Target **it = self->kids.start;
    Target **end = kids->end();
    for (; it != end; ++it) {
        (*it)->update(&b);
        Target *t = *it;
        t->changed_scale(t->scale_key(), 1);
    }
    return result;
}
