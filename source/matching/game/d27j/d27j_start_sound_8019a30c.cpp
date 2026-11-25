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
    unsigned loop : 1;
    unsigned once : 1;
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
struct Mask { int *start, *finish, *cap, *alloc; };
template <class T> struct List {
    T *start, *finish, *cap, *alloc;
    T *begin() { return start; }
    T *end() { return finish; }
    T &operator[](int i) { return start[i]; }
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
struct Info { unsigned u0; float length; };
struct Registry;
struct RegistryVtable { void *u0[9]; Info *(*info)(Registry *, unsigned); };
struct Registry { RegistryVtable *vtable; };
struct Mixer;
struct MixerVtable { void *u0[7]; Registry *(*registry)(Mixer *); void *u20[8]; void (*setVolume)(Mixer *, unsigned, float); void (*setPos)(Mixer *, unsigned, float, float); };
struct Mixer { MixerVtable *vtable; };
struct Player { void *vtable; unsigned char u4[16]; Mixer *mixer; float time; unsigned char u1c[4]; List<Rec> active; List<Rec> queued; int seq; List<Mask> masks; };
extern "C" int drop_8019ab0c(Player *, Rec *);
extern "C" void play_8019a868(Player *, Rec *);
inline const float &minimum(const float &a, const float &b) { return b < a ? b : a; }
inline const float &maximum(const float &a, const float &b) { return a < b ? b : a; }
inline bool overlap(const Mask &a, const Mask &b) {
    const int *p = a.start, *q = b.start;
    for (; p != a.finish; ++p, ++q) if (*p & *q) return true;
    return false;
}
inline void finishVoice(Player *self, Rec *a) {
    self->mixer->vtable->setVolume(self->mixer, a->channel, 0.0f);
    drop_8019ab0c(self, a);
    self->active.erase(a);
}
extern "C" void d27j_start_sound_8019a30c(Player *self, Rec *r) {
    float fadeLen = r->t3 - r->t2;
    bool any = false;
    float limit = self->time;
    Rec *a = self->active.begin();
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
    Registry *g = self->mixer->vtable->registry(self->mixer);
    Info *in = g->vtable->info(g, r->channel);
    float rate = in->length / (r->t1 - r->t0);
    self->mixer->vtable->setPos(self->mixer, r->channel, -r->t0 * rate, rate);
}
