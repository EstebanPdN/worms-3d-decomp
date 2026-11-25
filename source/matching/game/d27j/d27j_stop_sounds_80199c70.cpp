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
struct FalseType {};
template <class T> inline void DestroyAux(T *first, T *last, const FalseType &) { for (; first != last; ++first) first->~T(); }
template <class T> inline void DestroyValue(T *first, T *last, T *) { DestroyAux(first, last, FalseType()); }
template <class T> inline void DestroyRange(T *first, T *last) { DestroyValue(first, last, first); }
template <class T> inline void Distance(T *first, T *last, int &n) { n += last - first; }
template <class T> inline T *CopyRange(T *first, T *last, T *result) {
    int n = 0;
    Distance(first, last, n);
    for (; n > 0; --n) { *result = *first; ++first; ++result; }
    return result;
}
template <class T> struct List {
    T *start, *finish, *cap, *alloc;
    T *begin() { return start; }
    T *end() { return finish; }
    T *erase(T *pos) {
        if (pos + 1 != finish) CopyRange(pos + 1, finish, pos);
        --finish;
        finish->~T();
        return pos;
    }
    T *erase(T *first, T *last) {
        T *e = CopyRange(last, finish, first);
        DestroyRange(e, finish);
        finish = e;
        return first;
    }
    void clear() { erase(begin(), end()); }
};
struct Bank { unsigned u0; unsigned count; };
struct Registry;
struct RegistryVtable { void *u0[8]; Bank *(*bank)(Registry *); };
struct Registry { RegistryVtable *vtable; };
struct Mixer;
struct MixerVtable { void *u0[7]; Registry *(*registry)(Mixer *); void *u20[8]; void (*setVolume)(Mixer *, unsigned, float); };
struct Mixer { MixerVtable *vtable; };
struct Player { unsigned char u0[20]; Mixer *mixer; unsigned char u18[8]; List<Rec> active; List<Rec> queued; };
extern "C" int drop_8019ab0c(Player *, Rec *);
extern "C" int d27j_stop_sounds_80199c70(Player *self, int id) {
    if (id == -1) {
        self->active.clear();
        self->queued.clear();
        unsigned i = 0;
        Registry *r = self->mixer->vtable->registry(self->mixer);
        unsigned n = r->vtable->bank(r)->count;
        for (; i < n; ++i) self->mixer->vtable->setVolume(self->mixer, i, 0.0f);
    } else if (id == -2) {
        self->queued.clear();
    } else {
        Rec *p;
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
