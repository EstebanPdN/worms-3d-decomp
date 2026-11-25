#include "w3d_ptr.h"
#line 1 "d27j_start_sound_8019a30c.cpp"
// Start a sound record against the active voices, GWMP8P rev0 0x8019a30c.
// Every active voice whose channel mask overlaps the new record's mask is cut
// at once when the new fade is zero; otherwise it is faded out according to
// its state (1 fading in, 2 fading out, 3 steady), and voices whose fade has
// run out are silenced, dropped and erased. The new record then fades in up to
// the latest end found, or starts steady when nothing overlapped, and is
// handed to 0x8019a868 before its play position is set. Same list and record
// types as 0x80198c10 and 0x80199c70. Each switch case ends with its own
// increment and continue, which the code shows through the allocator priority
// of the next-record pointer.

struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state;
    unsigned short :14; unsigned short once:1; unsigned short loop:1;
    ~Rec() {}
};
struct FalseType { char w3d_empty; };
template <class T> inline void DestroyAux(T *first, T *last, const FalseType &) { for (; first != last; ++first) first->~T(); }
template <class T> inline void DestroyValue(T *first, T *last, T *) { DestroyAux(w3d::R(first), w3d::R(last), FalseType()); }
template <class T> inline void DestroyRange(T *first, T *last) { DestroyValue(w3d::R(first), w3d::R(last), w3d::R(first)); }
template <class T> inline void Distance(T *first, T *last, int &n) { n += last - first; }
template <class T> inline Ptr32<T> CopyRange(T *first, T *last, T *result) {
    int n = 0;
    Distance(w3d::R(first), w3d::R(last), n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
struct Mask { Ptr32<int> start; Ptr32<int> finish; Ptr32<int> cap; Ptr32<int> alloc; };
template <class T> struct List {
    Ptr32<T> start; Ptr32<T> finish; Ptr32<T> cap; Ptr32<T> alloc;
    Ptr32<T> begin() { return start; }
    Ptr32<T> end() { return finish; }
    T &operator[](int i) { return start[i]; }
    Ptr32<T> erase(Ptr32<T> pos) {
        if (pos + 1 != finish) CopyRange(w3d::R(pos + 1), w3d::R(finish), w3d::R(pos));
        --finish;
        finish->~T();
        return pos;
    }
    Ptr32<T> erase(Ptr32<T> first, Ptr32<T> last) {
        Ptr32<T> e = CopyRange(w3d::R(last), w3d::R(finish), w3d::R(first));
        DestroyRange(w3d::R(e), w3d::R(finish));
        finish = e;
        return first;
    }
    void clear() { erase(begin(), end()); }
};
struct Info { unsigned u0; float length; };
struct Registry;
struct RegistryVtable { Ptr32<void> u0[9]; Ptr32<Ptr32<Info> (Ptr32<Registry>, unsigned int)> info; };
struct Registry { Ptr32<RegistryVtable> vtable; };
struct Mixer;
struct MixerVtable { Ptr32<void> u0[7]; Ptr32<Ptr32<Registry> (Ptr32<Mixer>)> registry; Ptr32<void> u20[8]; Ptr32<void (Ptr32<Mixer>, unsigned int, float)> setVolume; Ptr32<void (Ptr32<Mixer>, unsigned int, float, float)> setPos; };
struct Mixer { Ptr32<MixerVtable> vtable; };
struct Player { Ptr32<void> vtable; unsigned char u4[16]; Ptr32<Mixer> mixer; float time; unsigned char u1c[4]; List<Rec> active; List<Rec> queued; int seq; List<Mask> masks; };
extern "C" int drop_8019ab0c(Ptr32<Player>, Ptr32<Rec>);
extern "C" void play_8019a868(Ptr32<Player>, Ptr32<Rec>);
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }
inline const float &maximum(const float &a, const float &b) { return a < b ? b : a; }
inline bool overlap(const Mask &a, const Mask &b) {
    Ptr32<const int> p = a.start; Ptr32<const int> q = b.start;
    for (; p != a.finish; ++p, ++q) if (*p & *q) return true;
    return false;
}
inline void finishVoice(Ptr32<Player> self, Ptr32<Rec> a) {
    self->mixer->vtable->setVolume(self->mixer, a->channel, 0.0f);
    drop_8019ab0c(self, a);
    self->active.erase(a);
}
extern "C" void d27j_start_sound_8019a30c(Ptr32<Player> self, Ptr32<Rec> r) {
    float fadeLen = r->t3 - r->t2;
    bool any = false;
    float limit = self->time;
    Ptr32<Rec> a = self->active.begin();
    while (a != self->active.end()) {
        if (overlap(self->masks[a->channel], self->masks[r->channel])) {
        any = true;
        if (fadeLen == 0.0f) { finishVoice(self, a); continue; }
        float t = 0.0f;
        switch (a->state) {
        case 1:
            a->state = 2;
            if (a->t3 - a->t2 == 0.0f) t = 1.0f;
            else t = (self->time - a->t2) / (a->t3 - a->t2);
            if (t == 0.0f) { finishVoice(self, a); continue; }
            t = minimum(t, 1.0f);
            a->t2 = r->t3 - (r->t3 - self->time) / t;
            a->t3 = r->t3;
            if (a->t3 == a->t2) { finishVoice(self, a); continue; }
            ++a;
            continue;
        case 2:
            if (a->t3 > r->t3) {
                t = (a->t3 - self->time) / (a->t3 - a->t2);
                if (t == 0.0f) { finishVoice(self, a); continue; }
                a->t2 = r->t3 - (r->t3 - self->time) / t;
                a->t3 = r->t3;
                limit = r->t3;
            } else {
                limit = maximum(limit, a->t3);
            }
            ++a;
            continue;
        case 3:
            a->state = 2;
            a->t2 = r->t2;
            if (a->loop || a->t1 > r->t3) {
                a->t3 = r->t3;
                limit = r->t3;
            } else {
                a->t3 = a->t1;
                limit = maximum(limit, a->t1);
            }
            ++a;
            continue;
        }
        }
        ++a;
    }
    if (!any) {
        r->state = 3;
        r->t3 = r->t2 = r->t0;
    } else {
        r->state = 1;
        r->t3 = limit;
    }
    play_8019a868(self, r);
    Ptr32<Registry> g = self->mixer->vtable->registry(self->mixer);
    Ptr32<Info> in = g->vtable->info(g, r->channel);
    float rate = in->length / (r->t1 - r->t0);
    self->mixer->vtable->setPos(self->mixer, r->channel, -r->t0 * rate, rate);
}


