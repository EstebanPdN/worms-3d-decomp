#include "w3d_ptr.h"
#line 1 "d27j_stop_sounds_80199c70.cpp"
// Stop playing records by tag, GWMP8P rev0 0x80199c70. Tag -1 clears both
// record lists and silences every channel; -2 clears the queued list;
// otherwise the first record with the tag is silenced and erased from the
// active list (dropping its reference) or from the queued list. Lists are the
// standard vector with the copy-loop erase that folds away for a full clear
// (see 0x80044638). The record destructor is empty, as the surviving destroy
// loops show.

struct Rec {
    float t0, t1, t2, t3;
    unsigned short channel, tag, state, seq;
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
struct Bank { unsigned u0; unsigned count; };
struct Registry;
struct RegistryVtable { Ptr32<void> u0[8]; Ptr32<Ptr32<Bank> (Ptr32<Registry>)> bank; };
struct Registry { Ptr32<RegistryVtable> vtable; };
struct Mixer;
struct MixerVtable { Ptr32<void> u0[7]; Ptr32<Ptr32<Registry> (Ptr32<Mixer>)> registry; Ptr32<void> u20[8]; Ptr32<void (Ptr32<Mixer>, unsigned int, float)> setVolume; };
struct Mixer { Ptr32<MixerVtable> vtable; };
struct Player { unsigned char u0[20]; Ptr32<Mixer> mixer; unsigned char u18[8]; List<Rec> active; List<Rec> queued; };
extern "C" int drop_8019ab0c(Ptr32<Player>, Ptr32<Rec>);
extern "C" int d27j_stop_sounds_80199c70(Ptr32<Player> self, int id) {
    if (id == -1) {
        self->active.clear();
        self->queued.clear();
        unsigned i = 0;
        Ptr32<Registry> r = self->mixer->vtable->registry(self->mixer);
        unsigned n = r->vtable->bank(r)->count;
        for (; i < n; ++i) self->mixer->vtable->setVolume(self->mixer, i, 0.0f);
    } else if (id == -2) {
        self->queued.clear();
    } else {
        Ptr32<Rec> p;
        for (p = self->active.begin(); p != self->active.end(); ++p) {
            if (p->tag == id) {
                self->mixer->vtable->setVolume(self->mixer, p->channel, 0.0f);
                drop_8019ab0c(self, p);
                self->active.erase(p);
                return 1;
            }
        }
        for (p = self->queued.begin(); p != self->queued.end(); ++p) {
            if (p->tag == id) {
                self->mixer->vtable->setVolume(self->mixer, p->channel, 0.0f);
                self->queued.erase(p);
                return 1;
            }
        }
    }
    return 0;
}


