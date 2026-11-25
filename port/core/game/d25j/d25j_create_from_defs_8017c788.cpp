#include "w3d_ptr.h"
#line 1 "d25j_create_from_defs_8017c788.cpp"
// Create objects from an array of definitions (Worms 3D GameCube PAL, 0x8017c788).
//
// For each 20-byte definition, gets an object from the service lookup 0x8020b680
// under one of two keys chosen by flag 8 at +16, holds it in a one-word handle,
// initializes it from the definition (0x80187158 or 0x801702b8) and passes it to
// 0x8017c464; a zero result there marks the batch as failed. Then raises the
// global counter 0x804ab5e8 to the owner's value at +9752 if that is larger.
// Returns 0, or 0x80004005 after any failure. An inline lookup keeps the key's
// high half movable by the loop pass. Real virtual calls: -fvtable-thunks.

struct Thing { void w3d_r_s8() __asm__(W3D_SYM("_ZN5Thing2s8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN5Thing6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN5Thing7releaseEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Thing, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Thing, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Thing, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Thing; };
extern "C" Ptr32<Thing> fn_8020b680(Ptr32<const char> key);
extern "C" int fn_80187158(Ptr32<Thing>, Ptr32<const void>);
extern "C" int fn_801702b8(Ptr32<Thing>, Ptr32<const void>);
extern const char key_80412d98[];
extern const char key_80411ff8[];
struct Handle {
    Ptr32<Thing> p;
    Handle() { p = 0; }
    Handle(const Handle &);
    ~Handle() { if (p) p->release(); }
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Thing *)w3d_p.get()); }
 Handle &operator=(Thing *v) {
        if (v) v->retain();
        if (p) p->release();
        p = v;
        return *this;
    }
};
struct Def { char u[16]; unsigned short flags; char u18[2]; };
struct Self { char u[9752]; unsigned stamp; };
extern unsigned stamp_804ab5e8;
extern "C" int fn_8017c464(Ptr32<Self>, Ptr32<Thing>);
inline Ptr32<Thing> lookup(Ptr32<const char> key) { return fn_8020b680(key); }
template<class T> inline const T &v_max(const T &a, const T &b) { return a < b ? b : a; }
extern "C" int d25j_create_from_defs_8017c788(Ptr32<Self> self, Ptr32<const Def> defs, unsigned count)
{
    int failed = 0;
    for (unsigned i = 0; i < count; i++) {
        Handle h;
        if (defs[i].flags & 8) {
            h = lookup(key_80412d98);
            fn_80187158(h.p, &defs[i]);
        } else {
            h = lookup(key_80411ff8);
            fn_801702b8(h.p, &defs[i]);
        }
        if (fn_8017c464(self, h.p) == 0) failed = 1;
    }
    stamp_804ab5e8 = v_max(stamp_804ab5e8, self->stamp);
    int result = (int)0x80004005;
    if (!failed) result = 0;
    return result;
}


