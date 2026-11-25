#include "w3d_ptr.h"
#line 1 "d27j_play_sound_8019a868.cpp"
// Hand a sound record to the mixer, GWMP8P rev0 0x8019a868. Unless the
// channel's sample status is 2 it asks the buffer manager to prepare the
// channel, passing the record's loop flag; then it counts a reference on the
// channel info and pushes the record on the active list (inlined STLport
// push_back with overflow growth). Same types as 0x80198c10.

inline void *operator new(__SIZE_TYPE__, void *p) { return p; }
struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state;
    unsigned short :14; unsigned short once:1; unsigned short loop:1;
    ~Rec() {}
};
inline void construct(Ptr32<Rec> p, const Rec &x) { if (p) new (p) Rec(x); }
inline const unsigned &maximum(const unsigned &a, const unsigned &b) { return a < b ? b : a; }
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }
inline Ptr32<Rec> copy_records(Ptr32<const Rec> first, Ptr32<const Rec> last, Ptr32<Rec> out) {
    for (; first != last; first++, out++) construct(out, *first);
    return out;
}
inline Ptr32<Rec> fill_records(Ptr32<Rec> out, unsigned n, const Rec &x) {
    for (; n != 0; n--, out++) construct(out, x);
    return out;
}
inline void destroy_records(Ptr32<Rec> first, Ptr32<Rec> last) {
    for (; first != last; first++) first->~Rec();
}
struct NotPod { char w3d_empty; };
extern "C" Ptr32<void> alloc_801907a8(unsigned);
extern "C" void release_801907d0(Ptr32<void>);
struct List {
    Ptr32<Rec> start; Ptr32<Rec> finish;
    int allocator;
    Ptr32<Rec> end_of_storage;
    void set(Ptr32<Rec> s, Ptr32<Rec> f, Ptr32<Rec> e) { start = s; finish = f; end_of_storage = e; }
    unsigned size() const { return finish - start; }
    void overflow(Ptr32<Rec> pos, const Rec &x, const NotPod &, unsigned n, bool at_end) {
        const unsigned old_size = size();
        const unsigned length = old_size + maximum(old_size, n);
        Ptr32<Rec> new_start = (Ptr32<Rec>)alloc_801907a8(length * 24);
        Ptr32<Rec> new_finish = new_start;
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
struct RegistryVtable { Ptr32<void> u0[9]; Ptr32<Ptr32<Info> (Ptr32<Registry>, unsigned int)> info; };
struct Registry { Ptr32<RegistryVtable> vtable; };
struct Mixer;
struct MixerVtable { Ptr32<void> u0[7]; Ptr32<Ptr32<Registry> (Ptr32<Mixer>)> registry; };
struct Mixer { Ptr32<MixerVtable> vtable; };
struct Player { Ptr32<void> vtable; unsigned char u4[16]; Ptr32<Mixer> mixer; float time; unsigned char u1c[4]; List active; List queued; int seq; };
extern "C" int status_80198160(Ptr32<void>);
extern "C" Ptr32<void> manager_803439d8();
extern "C" int prepare_801983cc(Ptr32<void>, unsigned, Ptr32<Registry>, int, unsigned);
extern "C" void d27j_play_sound_8019a868(Ptr32<Player> self, Ptr32<const Rec> r) {
    Ptr32<Registry> g = self->mixer->vtable->registry(self->mixer);
    Ptr32<Info> in = g->vtable->info(g, r->channel);
    if (status_80198160(in->u8) != 2)
        prepare_801983cc(manager_803439d8(), r->channel, self->mixer->vtable->registry(self->mixer), 0, r->loop);
    ++in->refs;
    self->active.push_back(*r);
}


