#include "w3d_ptr.h"
#line 1 "d32e_remove_nth_by_guid_801af59c.cpp"
// (Worms 3D GameCube PAL, 0x801af59c).
//
// Removes the index-th record whose 16-byte id equals the key from a vector
// of 24-byte records (interface, id, name): returns E_FAIL if there are too
// few, releases the interface, copies later records down one place and
// destroys the last name.

extern "C" int memcmp(Ptr32<const void>, Ptr32<const void>, unsigned);
struct Unk { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Unk2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Unk6AddRefEv")); int w3d_r_Release() __asm__(W3D_SYM("_ZN3Unk7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int Release() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Unk, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Unk; };
struct Guid { int w[4]; };
extern "C" void w3d_string_release_header(Ptr32<void>);
struct Str;
extern "C" void w3d_string_base_finish(Ptr32<Str>);
extern "C" void w3d_string_release(Ptr32<Str>);
struct Str {
    Ptr32<char> p;
    ~Str() { w3d_string_base_finish(this); w3d_string_release(this); }
    Str &operator=(const Str &o) {
        ++*(Ptr32<unsigned short>)(o.p - 6);
        Ptr32<unsigned short> h = (Ptr32<unsigned short>)(p - 6);
        if (--*h == 0) w3d_string_release_header(h);
        p = o.p;
        return *this;
    }
};
struct Rec { Ptr32<Unk> obj; Guid id; Str name; };
static inline Ptr32<Rec> Copy(Ptr32<Rec> f, Ptr32<Rec> l, Ptr32<Rec> d) {
    for (int n = l - f; n > 0; --n) { *d = *f; ++f; ++d; }
    return d;
}
struct Vec {
    Ptr32<Rec> first; Ptr32<Rec> last;
    Ptr32<Rec> end() { return last; }
    void erase(Ptr32<Rec> pos) {
        if (pos + 1 != last) Copy(pos + 1, last, pos);
        --last;
        last->~Rec();
    }
};
struct Owner { char u0[20]; Vec list; };
extern "C" int w3d_d32e_remove_nth_by_guid_801af59c(Ptr32<Owner> self, Ptr32<const void> key, unsigned index)
{
    Ptr32<Rec> it = self->list.first;
    for (unsigned i = 0; i <= index; i++) {
        for (; it != self->list.end(); it++)
            if (memcmp(it->id.w, key, 16) == 0) break;
        if (it == self->list.end()) return 0x80004005;
        if (i != index) it++;
    }
    it->obj->Release();
    self->list.erase(it);
    return 0;
}


