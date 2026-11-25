#include "w3d_ptr.h"
#line 1 "d29j_copy_shared_ref_80182498.cpp"
// Copy a shared reference from another node, GWMP8P rev0 0x80182498. Checks flag
// 8 of the object's type; without it the type's name string is copied and
// released and the call returns E_FAIL (0x80004005). Otherwise item 11's data
// takes the other object's counted reference, retaining the new value and
// releasing the old one. Virtual slot meanings and field names are inferred.
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
struct TypeBase {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN8TypeBase2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN8TypeBase3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN8TypeBase3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN8TypeBase3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN8TypeBase3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN8TypeBase3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN8TypeBase3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN8TypeBase3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN8TypeBase3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN8TypeBase3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN8TypeBase3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN8TypeBase3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN8TypeBase3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN8TypeBase3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN8TypeBase3s64Ev"));
    Ptr32<const Str> w3d_r_name() __asm__(W3D_SYM("_ZN8TypeBase4nameEv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const Str> name() { return ((Ptr32<const Str> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_TypeBase, 17))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_TypeBase; };
struct Type : TypeBase { char u[32] __attribute__((aligned(__alignof__(TypeBase)))); unsigned short flags; };
struct Info;
extern "C" Ptr32<Type> fn_80341348(Ptr32<Info>);
struct Counted { void w3d_r_s8() __asm__(W3D_SYM("_ZN7Counted2s8Ev")); void w3d_r_retain() __asm__(W3D_SYM("_ZN7Counted6retainEv")); void w3d_r_release() __asm__(W3D_SYM("_ZN7Counted7releaseEv"));  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Counted, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Counted; };
struct Ref { Ptr32<Counted> p;
    Ref &operator=(const Ref &o) { Ptr32<Counted> old = p; p = o.p; if (p) p->retain(); if (old) old->release(); return *this; }
};
struct Data { char u[48]; Ref ref; };
struct Item { char u[32]; Ptr32<Data> data; };
struct Node { Ptr32<Item> slot[12]; };
struct ObjBase {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN7ObjBase2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN7ObjBase3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN7ObjBase3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN7ObjBase3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN7ObjBase3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN7ObjBase3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN7ObjBase3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN7ObjBase3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN7ObjBase3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN7ObjBase3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN7ObjBase3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN7ObjBase3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN7ObjBase3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN7ObjBase3s60Ev"));
    Ptr32<Info> w3d_r_info() __asm__(W3D_SYM("_ZN7ObjBase4infoEv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Info> info() { return ((Ptr32<Info> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjBase, 16))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ObjBase; };
struct Obj : ObjBase {
    char u[116] __attribute__((aligned(__alignof__(ObjBase))));
    Ptr32<Node> items;
};
extern "C" int d29j_copy_shared_ref_80182498(Ptr32<Obj> self, Ptr32<Obj> o)
{
    if (!(fn_80341348(self->info())->flags & 8)) {
        Str s(*fn_80341348(self->info())->name());
        return 0x80004005;
    }
    int k = 11; Node &x = *o->items; Node &y = *self->items; Item &b = *x.slot[k]; Item &a = *y.slot[k];
    a.data->ref = b.data->ref;
    return 0;
}


