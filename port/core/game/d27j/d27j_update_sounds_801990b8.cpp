#include "w3d_ptr.h"
#line 1 "d27j_update_sounds_801990b8.cpp"
// Per-frame update of active sound records, GWMP8P rev0 0x801990b8. Records
// fading out past their fade end are silenced, dropped and erased; records
// fading in past theirs are set to full volume and become steady (state 3).
// Looping records past their end are moved forward by whole lengths and have
// their play position reset; other records past their end are stopped,
// silenced, dropped and erased. Same types as 0x80198c10. The first drop
// always uses element 0 and the second uses an index reset every iteration:
// idx is incremented only on the fall-through path, so it is always zero when
// read.

struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag;
    unsigned short state;
    unsigned short :15; unsigned short loop:1;
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
struct MixerVtable { Ptr32<void> u0[7]; Ptr32<Ptr32<Registry> (Ptr32<Mixer>)> registry; Ptr32<void> u20[4]; Ptr32<int (Ptr32<Mixer>, unsigned int)> stop; Ptr32<void> u34[3]; Ptr32<void (Ptr32<Mixer>, unsigned int, float)> setVolume; Ptr32<void (Ptr32<Mixer>, unsigned int, float, float)> setPos; };
struct Mixer { Ptr32<MixerVtable> vtable; };
struct Player { unsigned char u0[20]; Ptr32<Mixer> mixer; float time; unsigned char u1c[4]; List<Rec> active; List<Rec> queued; };
extern "C" int drop_8019ab0c(Ptr32<Player>, Ptr32<Rec>);
extern "C" void d27j_update_sounds_801990b8(Ptr32<Player> self) {
    Ptr32<Rec> p = self->active.begin();
    while (p != self->active.end()) {
        int idx = 0;
        if (p->state == 2 && p->t3 <= self->time) {
            self->mixer->vtable->setVolume(self->mixer, p->channel, 0.0f);
            drop_8019ab0c(self, &self->active[idx]);
            p = self->active.erase(p);
            continue;
        }
        if (p->state == 1 && p->t3 <= self->time) {
            self->mixer->vtable->setVolume(self->mixer, p->channel, 1.0f);
            p->state = 3;
        }
        if (p->loop) {
            float len = p->t1 - p->t0;
            while (p->t1 <= self->time) {
                p->t1 += len;
                p->t0 += len;
            }
            Ptr32<Registry> r = self->mixer->vtable->registry(self->mixer);
            Ptr32<Info> in = r->vtable->info(r, p->channel);
            float rate = in->length / (p->t1 - p->t0);
            self->mixer->vtable->setPos(self->mixer, p->channel, -p->t0 * rate, rate);
            ++p;
            continue;
        }
        if (p->t1 <= self->time) {
            if (p->state == 1 || p->state == 3) self->mixer->vtable->stop(self->mixer, p->channel);
            self->mixer->vtable->setVolume(self->mixer, p->channel, 0.0f);
            drop_8019ab0c(self, &self->active[idx]);
            p = self->active.erase(p);
            continue;
        }
        ++p;
        ++idx;
    }
}


