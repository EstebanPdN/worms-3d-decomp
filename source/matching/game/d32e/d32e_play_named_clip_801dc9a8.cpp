// (Worms 3D GameCube PAL, 0x801dc9a8).
//
// Plays a named sound clip from a bank: hands the bank's interface (at +124)
// to the caller's reference, fails with E_FAIL if the bank is not ready,
// then searches the categories for the name. When several consecutive items
// share the name, picks one at random; finds the player whose id equals the
// clip key and forwards to its play method. Returns 0 if nothing was found.

extern "C" int strcmp(const char *, const char *);
extern "C" int rand();
struct Entry;
struct Item;
struct Unk { virtual void v0(); virtual void AddRef(); virtual int Release(); };
struct Clip {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual int Key();
    virtual void v7(); virtual const char *Name();
};
struct Player : Unk {
    virtual void v3(); virtual void v4();
    virtual int Id();
    virtual int Play(Clip *, Unk **);
};
struct Cat { char u0[20]; int count; };
extern "C" int w3d_s21_has_name_801ddff4(Cat *, const char *);
extern "C" int w3d_s21_index_of_name_801de080(Cat *, const char *);
extern "C" Clip *w3d_s21_get_item_801de10c(Cat *, int);
template<class T> struct List { unsigned count; int cap; T *data; T &operator[](int i) { return *(T *)(i * 4 + (int)data); } T *begin() { return data; } };
struct Bank {
    char u0[36];
    List<Cat *> cats;
    List<Player *> players;
    char u60[64];
    Unk iface;
    char u128[48];
    int ready;
};
struct Ref { Unk *p; Ref &operator=(Unk *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; } };
extern "C" int w3d_d32e_play_named_clip_801dc9a8(Bank *self, const char *name, Ref *out)
{
    *out = &self->iface;
    if (!self->ready) return 0x80004005;
    int k = 0;
    for (unsigned i = 0; i < self->cats.count; i++) {
        Cat *c = self->cats[i];
        if (w3d_s21_has_name_801ddff4(c, name)) {
            int first = w3d_s21_index_of_name_801de080(c, name);
            int n = 1;
            while (first + n < c->count && !strcmp(w3d_s21_get_item_801de10c(c, first + n)->Name(), name)) n++;
            if (n > 1) k = rand() % n;
            Clip *it = w3d_s21_get_item_801de10c(c, first + k);
            int key = it->Key();
            for (Player **p = self->players.begin(); p != self->players.begin() + self->players.count; p++) {
                if ((*p)->Id() == key) return (*p)->Play(it, &out->p);
            }
        }
    }
    return 0;
}
