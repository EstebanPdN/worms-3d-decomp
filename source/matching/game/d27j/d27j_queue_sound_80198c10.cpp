// Start or queue a sound record, GWMP8P rev0 0x80198c10. Takes a sequence tag,
// resolves negative delay and fade from the virtual position query, builds the
// 24-byte record (start, end from the channel length over the rate, fade
// limited to the end), then starts it now when the delay is zero or pushes it
// on the queued list, keeping at most ten. The list push is the inlined
// STLport push_back with overflow growth old + max(old, 1). Returns the tag,
// or -1 when the position query fails.

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
struct Info { unsigned u0; float length; };
struct Registry;
struct RegistryVtable { void *u0[9]; Info *(*info)(Registry *, unsigned); };
struct Registry { RegistryVtable *vtable; };
struct Mixer;
struct MixerVtable { void *u0[7]; Registry *(*registry)(Mixer *); };
struct Mixer { MixerVtable *vtable; };
struct Player;
struct PlayerVtable { void *u0[11]; int (*position)(Player *, float *); };
struct Player { PlayerVtable *vtable; unsigned char u4[16]; Mixer *mixer; float time; unsigned char u1c[4]; List active; List queued; int seq; };
extern "C" int start_8019a30c(Player *, Rec *);
extern "C" int d27j_queue_sound_80198c10(Player *self, unsigned channel, unsigned loop, unsigned once, float delay, float rate, float fade) {
    int seq = self->seq++;
    Rec r;
    if (delay < 0.0f) {
        float now;
        if (!self->vtable->position(self, &now)) return -1;
        delay = now;
    }
    if (fade < 0.0f) {
        float end;
        self->vtable->position(self, &end);
        if (end < delay) fade = 0.0f;
        else fade = end - delay;
    }
    r.loop = loop;
    r.once = once;
    r.t0 = delay + self->time;
    Registry *g = self->mixer->vtable->registry(self->mixer);
    Info *in = g->vtable->info(g, channel);
    float len = in->length / rate;
    r.channel = channel;
    r.t2 = r.t0;
    r.tag = seq;
    r.t1 = r.t0 + len;
    r.t3 = r.t0 + fade;
    r.t3 = minimum(r.t3, r.t1);
    fade = r.t3 - r.t0;
    r.state = fade == 0.0f ? 3 : 1;
    if (delay == 0.0f) {
        start_8019a30c(self, &r);
    } else if (self->queued.size() <= 9) {
        self->queued.push_back(r);
    }
    return seq;
}
