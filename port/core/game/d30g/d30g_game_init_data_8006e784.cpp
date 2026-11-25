#include "w3d_ptr.h"
#line 1 "d30g_game_init_data_8006e784.cpp"
/* Worms 3D GameCube PAL 0x8006e784. Game start bookkeeping. Unless the random generators are already seeded (0x804abac0), seeds them from the application seed or from the elapsed milliseconds (0 when flag 0x00200000 is set), which also logs the game count; reads GM.GameInitData and, with more than one player, tallies the active teams by kind, advances each team's cycle index, then advances the starting team and the per-kind turn index. Field names are inferred from the original instructions; strings and globals are external views of original data. */
struct Object;
struct ObjectVtable { Ptr32<void> u[3]; Ptr32<void (Ptr32<Object>)> retain; Ptr32<void (Ptr32<Object>)> release; };
struct Object { Ptr32<ObjectVtable> vtable; };
struct Descriptor_80178474 {
    int a; unsigned b;
    Descriptor_80178474() : a(0), b(58280) {}
    ~Descriptor_80178474();
};
struct Data : Object { char u4[52] __attribute__((aligned(__alignof__(Object)))); unsigned n0; char u60[8]; int cur3; int cur2; int cur1; int cur0; int order; char u88[4]; unsigned players; char u96[40]; unsigned n1; char u140[8]; int c0; int k0; char u156[52]; unsigned n2; char u212[8]; int c1; int k1; int k2; int c3; int k3; char u240[44]; unsigned n3; char u288[8]; int c2; };
template <class T> struct Ref {
    Ptr32<T> value;
    Ref() {}
    template <class W3dU> Ref<T>(Ptr32<W3dU> w3d_p) : Ref<T>((T *)w3d_p.get()) {}
 Ref(T *p) { value = p; if (p) p->vtable->retain(p); }
    Ref(const Ref &);
    ~Ref() { if (value) value->vtable->release(value); }
    Ref &operator=(const Ref &o) {
        Ptr32<T> n = o.value;
        if (n) {
            n->vtable->retain(n);
            if (value) value->vtable->release(value);
            value = n;
        }
        return *this;
    }
    Ptr32<T> operator->() const { return value; }
};
struct Key { Ptr32<const char> text; };
struct App { char u0[164]; int seed; };
struct Self { char u0[240]; unsigned flags; };
extern int ready_804abac0;
extern Ptr32<App> app_804b1788;
extern int rounds_804aaac8;
extern const char s_8037c454[], s_8037c474[];
extern "C" int printf(Ptr32<const char>, ...);
extern "C" Ptr32<void> memset(Ptr32<void>, ...);
extern "C" int seed_a_80162c18(int);
extern "C" int seed_b_80162c90(int);
extern "C" int elapsed_801fe45c();
extern "C" int w3d_env_int(const char *, int *);
extern "C" unsigned random_80162ba8();
extern "C" int lookup_800fc1b0(Ptr32<Key>, Ptr32<void>);
extern "C" Ptr32<Object> cast_80341584(Ptr32<Object>);
extern "C" Ptr32<Data> data_80179598(Ptr32<Object>, Ptr32<Descriptor_80178474>);
#define PICK(cnt, type, cur, slot) { \
    counts[data->type]++; \
    Data *d = data.value; \
    teams[slot] = d->type; \
    if (d->cur == -1) d->cur = random_80162ba8() % data->cnt; \
    else d->cur = (d->cur + 1) % d->cnt; \
}
#define NEXT(k, cur) \
    if (counts[k]) { \
        int r = data->cur; \
        if (r == -1) r = random_80162ba8() % (unsigned)counts[k]; \
        else r = (r + 1) % counts[k]; \
        int n = 0; \
        if (r >= 0) { \
            int *p = teams; \
            do { if (*p++ == k) r--; n++; } while (r >= 0); \
        } \
        data->cur = n - 1; \
    }
extern "C" void w3d_d30g_game_init_data_8006e784(Ptr32<Self> self)
{
    if (ready_804abac0 == 0) {
        w3d_env_int("W3D_SEED", &app_804b1788->seed);
        if (app_804b1788->seed) {
            seed_a_80162c18(app_804b1788->seed);
            seed_b_80162c90(app_804b1788->seed);
        } else {
            int t = elapsed_801fe45c();
            if (self->flags & 0x00200000) t = 0;
            seed_a_80162c18(t);
            seed_b_80162c90(t);
            printf(s_8037c454, ++rounds_804aaac8);
        }
    }
    Ref<Object> h;
    h.value = 0;
    Descriptor_80178474 desc;
    { Key k; k.text = s_8037c474; if (lookup_800fc1b0(&k, &h) < 0) return; }
    Ref<Data> data;
    data.value = 0;
    data = Ref<Data>(data_80179598(cast_80341584(h.value), &desc));
    if (data->players > 1) {
        int counts[4];
        int teams[4];
        memset(counts, 0, 16);
        memset(teams, 0, 16);
        if (data->n0) PICK(n0, k0, c0, 0)
        if (data->n1 && data->players > 1) PICK(n1, k1, c1, 1)
        if (data->n2 && data->players > 2) PICK(n2, k2, c2, 2)
        if (data->n3 && data->players > 3) PICK(n3, k3, c3, 3)
        int x = data->order;
        if (x == -1) x = random_80162ba8() & 3;
        else x = (x + 1) % 4;
        while (counts[x] == 0) x = (x + 1) % 4;
        data->order = x;
        NEXT(0, cur0)
        NEXT(1, cur1)
        NEXT(2, cur2)
        NEXT(3, cur3)
    }
}


