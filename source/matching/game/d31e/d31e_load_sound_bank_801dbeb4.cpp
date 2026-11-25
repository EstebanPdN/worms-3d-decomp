// (Worms 3D GameCube PAL, 0x801dbeb4).
//
// Loads a MusyX sound bank by base name: first walks the group definitions
// (56-byte records ending with a null first word): if a group with the
// record's id is not in the list at +36, calls the add slot and searches the
// same record again; once found, calls the attach slot and advances. If not
// already started, loads <name>.pool, .proj, .samp (from the audio heap) and
// .sdir through 0x801db7a8, returning 0 on the first failure; stops any
// running sound system, starts it with the four buffers, sets the master
// volume 127/0/255, frees the sample buffer and clears +196. Always returns
// 0. Names are inferred.

struct String;
extern "C" void w3d_string_default(String *);
extern "C" void w3d_string_format(String *, const char *, ...);
extern "C" void w3d_string_base_init(String *);
extern "C" unsigned short *w3d_string_header(String *);
extern "C" void w3d_string_base_finish(String *);
extern "C" void w3d_string_release(String *);
struct String {
    char *p;
    String();
    String(const String &o) {
        w3d_string_base_init(this);
        p = o.p;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
static inline void use(String) { }
struct Group { char pad[36]; int id; };
struct Def { void *ptr; int a; int id; char rest[44]; };
struct GroupList {
    unsigned count;
    int x4;
    Group **data;
    unsigned size() const { return count; }
    Group *operator[](unsigned i) { return data[i]; }
    Group *&at(unsigned i) { return data[i]; }
};
struct BankBase {
    virtual void a0(),a1(),a2(),a3(),a4(),a5(),a6(),a7(),a8(),a9(),a10(),a11(),a12(),a13(),a14(),a15(),a16(),a17(),a18(),a19(),a20(),a21(),a22(),a23(),a24(),a25(),a26(),a27(),a28(),a29(),a30(),a31(),a32(),a33();
    virtual void a33b();
    virtual void missing(int);
    virtual void a35(),a36();
    virtual void found(Group *, Def *);
};
struct Bank : BankBase {
    char pad4[32];
    GroupList list;
    char pad48[132];
    int started;
    void *pool, *proj, *sdir, *samp;
};
struct Heap;
extern Heap *g_audioHeap;
extern int g_trace;
extern const char s_pool[], s_proj[], s_samp[], s_sdir[], s_freeing[];
extern "C" void *fn_801db7a8(Bank *, const char *, int);
extern "C" void fn_8032fb54();
extern "C" void fn_8032f828(void *, int, void *, void *, void *);
extern "C" void fn_803229fc(int, int, int);
extern "C" void w3d_trace_stub_80347324(int *, const char *, ...);
extern "C" void w3d_heap_release(Heap *, void *);
extern "C" void w3d_auto_80209968(Heap *);

extern "C" int w3d_d31e_load_sound_bank_801dbeb4(Bank *self, const char *name, Def *defs)
{
    int i = 0;
    Group *item = 0;
    while (defs[i].ptr) {
        bool found = false;
        for (unsigned j = 0; j < self->list.size(); j++) {
            Group *g = self->list[j];
            item = g;
            if (self->list[j]->id == defs[i].id) { found = true; break; }
        }
        if (!found) self->missing(defs[i].id);
        else {
            self->found(item, &defs[i]);
            i++;
        }
    }
    String s;
    if (self->started) return 0;
    w3d_string_format(&s, s_pool, name);
    use(s);
    self->pool = fn_801db7a8(self, s.p, 0);
    if (!self->pool) return 0;
    w3d_string_format(&s, s_proj, name);
    use(s);
    self->proj = fn_801db7a8(self, s.p, 0);
    if (!self->proj) return 0;
    w3d_string_format(&s, s_samp, name);
    use(s);
    self->samp = fn_801db7a8(self, s.p, 1);
    if (!self->samp) return 0;
    w3d_string_format(&s, s_sdir, name);
    use(s);
    self->sdir = fn_801db7a8(self, s.p, 0);
    if (!self->sdir) return 0;
    if (self->started) {
        fn_8032fb54();
        self->started = 0;
    }
    if (self->proj && self->samp && self->sdir && self->pool) {
        fn_8032f828(self->proj, 0, self->samp, self->sdir, self->pool);
        self->started = 1;
        fn_803229fc(127, 0, 255);
    }
    if (self->samp) w3d_trace_stub_80347324(&g_trace, s_freeing, self->samp, g_audioHeap);
    w3d_heap_release(g_audioHeap, self->samp);
    w3d_auto_80209968(g_audioHeap);
    self->samp = 0;
    return 0;
}
