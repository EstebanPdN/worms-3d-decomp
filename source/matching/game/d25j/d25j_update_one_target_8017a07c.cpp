// Update one target of a scene node (Worms 3D GameCube PAL, 0x8017a07c).
//
// Builds the target frame from the rotation (0x801a3eb0), scale (0x801f6448)
// and translation, applies the flags byte unless it is 7, combines it with the
// local frame when the node has one (0x801f740c), and gives target i that frame
// or the frame made by its source object. The target is then notified through
// virtual +76 with the value of virtual +100. Same classes as
// d25j_node_transform_setters_8017a2b0. Real virtual calls: -fvtable-thunks.

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
extern float float_803a7068[];

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

extern "C" void d25j_update_one_target_8017a07c(Node *self, int i)
{
    Frame b;
    Frame a;
    Frame *pa = &a;
    void *space = self->world->inner->space;
    fn_801a3eb0(&self->rotation, (int)space, pa);
    fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
    a.set(self->translation);
    if (self->flags != 7) {
        if (self->flags & 2) fn_801a3eb0(&self->rotation, (int)space, pa);
        else fn_801f6034(pa);
        if (self->flags & 4) fn_801f6448(pa, self->scale.x, self->scale.y, self->scale.z);
        if ((self->flags ^ 1) & 1) {
            float zero = float_803a7068[0];
            Frame *q = &a;
            q->zero(zero);
        }
    }
    if (self->is_local()) fn_801f740c(&b, &a, &self->local_frame);
    else b = a;
    Sources *srcs = &self->sources;
    void *src = srcs->data[i];
    if (src) {
        void *out;
        self->makers.data[i]->make(src, self->world, &out);
        (*(Target **)((char *)self->kids.start + (i << 2)))->update(out);
    } else {
        (*(Target **)((char *)self->kids.start + (i << 2)))->update(&b);
    }
    Target *t = (*(Target **)((char *)self->kids.start + (i << 2)));
    t->changed_translation(t->translation_key(), 1);
}
