// Hand a sound record to the mixer, GWMP8P rev0 0x8019a868. Unless the
// channel's sample status is 2 it asks the buffer manager to prepare the
// channel, passing the record's loop flag; then it counts a reference on the
// channel info and pushes the record on the active list (inlined STLport
// push_back with overflow growth). Same types as 0x80198c10.

inline void *operator new(unsigned, void *p) { return p; }
struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state;
    unsigned loop : 1;
    unsigned once : 1;
    ~Rec() {}
};
inline void construct(Rec *p, const Rec &x) { if (p) new (p) Rec(x); }
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }
inline Rec *copy_records(const Rec *first, const Rec *last, Rec *out) {
    for (; first != last; first++, out++) construct(out, *first);
    return out;
}
inline Rec *fill_records(Rec *out, unsigned n, const Rec &x) {
    for (; n != 0; n--, out++) construct(out, x);
    return out;
}
inline void destroy_records(Rec *first, Rec *last) {
    for (; first != last; first++) first->~Rec();
}
struct NotPod {};
extern "C" void *alloc_801907a8(unsigned);
extern "C" void release_801907d0(void *);
struct List {
    Rec *start, *finish;
    int allocator;
    Rec *end_of_storage;
    void set(Rec *s, Rec *f, Rec *e) { start = s; finish = f; end_of_storage = e; }
    unsigned size() const { return finish - start; }
    void overflow(Rec *pos, const Rec &x, const NotPod &, unsigned n, bool at_end) {
        const unsigned old_size = size();
        const unsigned length = old_size + maximum(old_size, n);
        Rec *new_start = (Rec *)alloc_801907a8(length * 24);
        Rec *new_finish = new_start;
        new_finish = copy_records(start, pos, new_start);
        if (n == 1) {
            construct(new_finish, x);
            new_finish++;
        } else {
            new_finish = fill_records(new_finish, n, x);
        }
        destroy_records(start, finish);
        if (start) release_801907d0(start);
        set(new_start, new_finish, new_start + length);
    }
    void push_back(const Rec &x) {
        if (finish != end_of_storage) {
            construct(finish, x);
            finish++;
        } else {
            overflow(finish, x, NotPod(), 1, true);
        }
    }
};
struct Info { unsigned u0; float length; unsigned char u8[72]; unsigned char refs; };
struct Registry;
struct RegistryVtable { void *u0[9]; Info *(*info)(Registry *, unsigned); };
struct Registry { RegistryVtable *vtable; };
struct Mixer;
struct MixerVtable { void *u0[7]; Registry *(*registry)(Mixer *); };
struct Mixer { MixerVtable *vtable; };
struct Player { void *vtable; unsigned char u4[16]; Mixer *mixer; float time; unsigned char u1c[4]; List active; List queued; int seq; };
extern "C" int status_80198160(void *);
extern "C" void *manager_803439d8();
extern "C" int prepare_801983cc(void *, unsigned, Registry *, int, unsigned);
extern "C" void d27j_play_sound_8019a868(Player *self, const Rec *r) {
    Registry *g = self->mixer->vtable->registry(self->mixer);
    Info *in = g->vtable->info(g, r->channel);
    if (status_80198160(in->u8) != 2)
        prepare_801983cc(manager_803439d8(), r->channel, self->mixer->vtable->registry(self->mixer), 0, r->loop);
    ++in->refs;
    self->active.push_back(*r);
}
