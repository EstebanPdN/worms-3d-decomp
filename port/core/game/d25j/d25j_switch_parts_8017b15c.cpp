#include "w3d_ptr.h"
#line 1 "d25j_switch_parts_8017b15c.cpp"
// Switch a node between its two parts (Worms 3D GameCube PAL, 0x8017b15c).
//
// Holds the shape found under the key at +4 in a one-word handle and calls
// 0x8017b6dc. With the flag set it looks for part +124 in the shape's list; on a
// hit it tells the shape (0x801ef380, 0x801ef174 with part +120) and clears the
// reference at +20 of part +124. With the flag clear it looks for part +120; on
// a hit it tells the shape, with part +124, and stores part +120 in that
// reference with retain and release. Returns 0, or 0x80004005 on a miss. Same
// classes as d25j_release_parts_8017b348. Real virtual calls: -fvtable-thunks.

extern "C" void fn_8020c5c0(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
struct Str {
    Ptr32<char> text;
    Str(const Str &o) { fn_8020c5c0(this); text = o.text; ++*fn_80341884(this); }
    ~Str();
};
extern "C" void fn_8020c5c4(Ptr32<Str>);
extern "C" void fn_80341588(Ptr32<Str>);
inline Str::~Str() { fn_8020c5c4(this); fn_80341588(this); }
struct List { char u[24]; unsigned count; char u28[4]; Ptr32<void> items[1]; };
struct Counted { void w3d_r_s8() __asm__(W3D_SYM("_ZN7Counted2s8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN7Counted6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN7Counted7releaseEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Counted; };
struct Shape : Counted {
    char u4[40] __attribute__((aligned(__alignof__(Counted))));
    Ptr32<List> list;
};
struct Part : Counted {
    char u4[16] __attribute__((aligned(__alignof__(Counted))));
    Ptr32<Part> ref;
    void set(Ptr32<Part> v) { Ptr32<Part> o = ref; ref = v; if (v) v->retain(); if (o) o->release(); }
};
struct Handle {
    Ptr32<Shape> p;
    template <class W3dU> Handle(Ptr32<W3dU> w3d_p) : Handle((Shape *)w3d_p.get()) {}
 Handle(Shape *v) { p = v; if (p) p->retain(); }
    Handle(const Handle &);
    ~Handle() { if (p) p->release(); }
};
struct Found { char u[20]; Ptr32<Shape> shape; };
struct Service {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN7Service2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN7Service3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN7Service3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN7Service3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN7Service3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN7Service3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN7Service3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN7Service3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN7Service3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN7Service3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN7Service3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN7Service3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN7Service3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN7Service3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN7Service3s64Ev")); void w3d_r_s68() __asm__(W3D_SYM("_ZN7Service3s68Ev")); void w3d_r_s72() __asm__(W3D_SYM("_ZN7Service3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN7Service3s76Ev")); void w3d_r_s80() __asm__(W3D_SYM("_ZN7Service3s80Ev")); void w3d_r_s84() __asm__(W3D_SYM("_ZN7Service3s84Ev")); void w3d_r_s88() __asm__(W3D_SYM("_ZN7Service3s88Ev")); void w3d_r_s92() __asm__(W3D_SYM("_ZN7Service3s92Ev")); void w3d_r_s96() __asm__(W3D_SYM("_ZN7Service3s96Ev")); void w3d_r_s100() __asm__(W3D_SYM("_ZN7Service4s100Ev")); void w3d_r_s104() __asm__(W3D_SYM("_ZN7Service4s104Ev")); void w3d_r_s108() __asm__(W3D_SYM("_ZN7Service4s108Ev")); void w3d_r_s112() __asm__(W3D_SYM("_ZN7Service4s112Ev"));
    Ptr32<Found> w3d_r_find(Ptr32<void> key) __asm__(W3D_SYM("_ZN7Service4findEPv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s68() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s80() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s84() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s88() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s92() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s96() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s100() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s104() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s108() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s112() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Found> find(Ptr32<void> w3d_a0) { return ((Ptr32<Found> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Service, 29))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Service; };
extern Ptr32<Service> service_804ab5fc;
struct Named { void w3d_r_s8() __asm__(W3D_SYM("_ZN5Named2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN5Named3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN5Named3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN5Named3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN5Named3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN5Named3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN5Named3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN5Named3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN5Named3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN5Named3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN5Named3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN5Named3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN5Named3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN5Named3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN5Named3s64Ev")); Ptr32<const Str> w3d_r_name() __asm__(W3D_SYM("_ZN5Named4nameEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const Str> name() { return ((Ptr32<const Str> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Named, 17))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Named; };
struct SelfBase {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN8SelfBase2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN8SelfBase3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN8SelfBase3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN8SelfBase3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN8SelfBase3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN8SelfBase3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN8SelfBase3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN8SelfBase3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN8SelfBase3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN8SelfBase3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN8SelfBase3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN8SelfBase3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN8SelfBase3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN8SelfBase3s60Ev"));
    Ptr32<Named> w3d_r_named() __asm__(W3D_SYM("_ZN8SelfBase5namedEv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Named> named() { return ((Ptr32<Named> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_SelfBase, 16))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_SelfBase; };
struct Self : SelfBase {
    char key[116] __attribute__((aligned(__alignof__(SelfBase))));
    Ptr32<Part> a;
    Ptr32<Part> b;
};
extern "C" void fn_8017b6dc(Ptr32<Self>);
extern "C" void fn_801ef380(Ptr32<Shape>, int, int, unsigned, int);
extern "C" void fn_801ef174(Ptr32<Shape>, int, int, Ptr32<Part>);
extern "C" int d25j_switch_parts_8017b15c(Ptr32<Self> self, int on)
{
    Handle h(service_804ab5fc->find(self->key)->shape);
    Ptr32<List> list = h.p->list;
    unsigned count = list->count;
    Ptr32<Ptr32<void>> items = list->items;
    fn_8017b6dc(self);
    if (on) {
        for (unsigned i = 0; i < count; i++) {
            if (items[i] == self->b) {
                fn_801ef380(h.p, 44, 3, i, 1);
                fn_801ef174(h.p, 44, 3, self->a);
                Ptr32<Part> b = self->b;
                Ptr32<Part> none = 0;
                Ptr32<Part> o = b->ref;
                b->ref = none;
                if (o) o->release();
                return 0;
            }
        }
    } else {
        for (unsigned i = 0; i < count; i++) {
            if (items[i] == self->a) {
                fn_801ef380(h.p, 44, 3, i, 1);
                fn_801ef174(h.p, 44, 3, self->b);
                self->b->set(self->a);
                return 0;
            }
        }
    }
    return (int)0x80004005;
}


