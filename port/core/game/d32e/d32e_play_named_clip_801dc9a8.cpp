#include "w3d_ptr.h"
#line 1 "d32e_play_named_clip_801dc9a8.cpp"
// (Worms 3D GameCube PAL, 0x801dc9a8).
//
// Plays a named sound clip from a bank: hands the bank's interface (at +124)
// to the caller's reference, fails with E_FAIL if the bank is not ready,
// then searches the categories for the name. When several consecutive items
// share the name, picks one at random; finds the player whose id equals the
// clip key and forwards to its play method. Returns 0 if nothing was found.

extern "C" int strcmp(Ptr32<const char>, Ptr32<const char>);
extern "C" int rand();
struct Entry;
struct Item;
struct Unk { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Unk2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Unk6AddRefEv")); int w3d_r_Release() __asm__(W3D_SYM("_ZN3Unk7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Unk; };
struct Clip {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Clip2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Clip2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Clip2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN4Clip2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN4Clip2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Clip2v5Ev"));
    int w3d_r_Key() __asm__(W3D_SYM("_ZN4Clip3KeyEv"));
    void w3d_r_v7() __asm__(W3D_SYM("_ZN4Clip2v7Ev")); Ptr32<const char> w3d_r_Name() __asm__(W3D_SYM("_ZN4Clip4NameEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Key() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const char> Name() { return ((Ptr32<const char> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Clip, 10))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Clip; };
struct Player : Unk {
    void w3d_r_v3() __asm__(W3D_SYM("_ZN6Player2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN6Player2v4Ev"));
    int w3d_r_Id() __asm__(W3D_SYM("_ZN6Player2IdEv"));
    int w3d_r_Play(Ptr32<Clip>, Ptr32<Ptr32<Unk>>) __asm__(W3D_SYM("_ZN6Player4PlayEP4ClipPP3Unk"));
 __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Id() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Play(Ptr32<Clip> w3d_a0, Ptr32<Ptr32<Unk>> w3d_a1) { return ((int (*)(w3d_u32, Ptr32<Clip>, Ptr32<Ptr32<Unk>>))w3d::vfn(this->w3d_vptr_Unk, 8))(w3d::h2g(this), w3d_a0, w3d_a1); } };
struct Cat { char u0[20]; int count; };
extern "C" int w3d_s21_has_name_801ddff4(Ptr32<Cat>, Ptr32<const char>);
extern "C" int w3d_s21_index_of_name_801de080(Ptr32<Cat>, Ptr32<const char>);
extern "C" Ptr32<Clip> w3d_s21_get_item_801de10c(Ptr32<Cat>, int);
template<class T> struct List { unsigned count; int cap; Ptr32<T> data; T &operator[](int i) { return *(Ptr32<T>)(i * 4 + (int)data); } Ptr32<T> begin() { return data; } };
struct Bank {
    char u0[36];
    List <Ptr32<Cat> > cats;
    List <Ptr32<Player> > players;
    char u60[64];
    Unk iface;
    char u128[48];
    int ready;
};
struct Ref { Ptr32<Unk> p; template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Unk *)w3d_p.get()); }
 Ref &operator=(Unk *q) { if (q) q->AddRef(); if (p) p->Release(); p = q; return *this; } };
extern "C" int w3d_d32e_play_named_clip_801dc9a8(Ptr32<Bank> self, Ptr32<const char> name, Ptr32<Ref> out)
{
    *out = &self->iface;
    if (!self->ready) return 0x80004005;
    int k = 0;
    for (unsigned i = 0; i < self->cats.count; i++) {
        Ptr32<Cat> c = self->cats[i];
        if (w3d_s21_has_name_801ddff4(c, name)) {
            int first = w3d_s21_index_of_name_801de080(c, name);
            int n = 1;
            while (first + n < c->count && !strcmp(w3d_s21_get_item_801de10c(c, first + n)->Name(), name)) n++;
            if (n > 1) k = rand() % n;
            Ptr32<Clip> it = w3d_s21_get_item_801de10c(c, first + k);
            int key = it->Key();
            for (Ptr32<Ptr32<Player>> p = self->players.begin(); p != self->players.begin() + self->players.count; p++) {
                if ((*p)->Id() == key) return (*p)->Play(it, &out->p);
            }
        }
    }
    return 0;
}


