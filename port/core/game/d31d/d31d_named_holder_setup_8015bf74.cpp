#include "w3d_ptr.h"
#line 1 "d31d_named_holder_setup_8015bf74.cpp"
// GWMP8P rev0 0x8015bf74. Setup of a named resource holder. Names are inferred;
// virtual slots are reference-ABI observations.
#pragma interface
extern "C" { struct String; void string_finish_8020c5c4(Ptr32<String>); void string_release_80341588(Ptr32<String>); }
struct String { Ptr32<void> rep; template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *); String(const String &); ~String() { string_finish_8020c5c4(this); string_release_80341588(this); } };
String make_80210958();
struct Service {
    void w3d_r_s2() __asm__(W3D_SYM("_ZN7Service2s2Ev"));
    void w3d_r_s3() __asm__(W3D_SYM("_ZN7Service2s3Ev"));
    void w3d_r_s4() __asm__(W3D_SYM("_ZN7Service2s4Ev"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN7Service2s5Ev"));
    void w3d_r_s6() __asm__(W3D_SYM("_ZN7Service2s6Ev"));
    void w3d_r_s7() __asm__(W3D_SYM("_ZN7Service2s7Ev"));
    void w3d_r_s8() __asm__(W3D_SYM("_ZN7Service2s8Ev"));
    void w3d_r_s9() __asm__(W3D_SYM("_ZN7Service2s9Ev"));
    void w3d_r_s10() __asm__(W3D_SYM("_ZN7Service3s10Ev"));
    void w3d_r_s11() __asm__(W3D_SYM("_ZN7Service3s11Ev"));
    void w3d_r_s12() __asm__(W3D_SYM("_ZN7Service3s12Ev"));
    void w3d_r_s13() __asm__(W3D_SYM("_ZN7Service3s13Ev"));
    void w3d_r_s14() __asm__(W3D_SYM("_ZN7Service3s14Ev"));
    void w3d_r_s15() __asm__(W3D_SYM("_ZN7Service3s15Ev"));
    void w3d_r_s16() __asm__(W3D_SYM("_ZN7Service3s16Ev"));
    void w3d_r_s17() __asm__(W3D_SYM("_ZN7Service3s17Ev"));
    void w3d_r_s18() __asm__(W3D_SYM("_ZN7Service3s18Ev"));
    int w3d_r_set(const String &) __asm__(W3D_SYM("_ZN7Service3setERK6String"));
 __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Service, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int set(const String &w3d_a0) { return ((int (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Service, 19))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); }  Ptr32<void> w3d_vptr_Service; };
struct Entry {
    void w3d_r_s2() __asm__(W3D_SYM("_ZN5Entry2s2Ev"));
    void w3d_r_retain() __asm__(W3D_SYM("_ZN5Entry6retainEv"));
    void w3d_r_release() __asm__(W3D_SYM("_ZN5Entry7releaseEv"));
    void w3d_r_s5() __asm__(W3D_SYM("_ZN5Entry2s5Ev"));
    void w3d_r_s6() __asm__(W3D_SYM("_ZN5Entry2s6Ev"));
    void w3d_r_s7() __asm__(W3D_SYM("_ZN5Entry2s7Ev"));
    void w3d_r_s8() __asm__(W3D_SYM("_ZN5Entry2s8Ev"));
    void w3d_r_s9() __asm__(W3D_SYM("_ZN5Entry2s9Ev"));
    void w3d_r_s10() __asm__(W3D_SYM("_ZN5Entry3s10Ev"));
    void w3d_r_s11() __asm__(W3D_SYM("_ZN5Entry3s11Ev"));
    void w3d_r_s12() __asm__(W3D_SYM("_ZN5Entry3s12Ev"));
    void w3d_r_put(int) __asm__(W3D_SYM("_ZN5Entry3putEi"));
    void w3d_r_s14() __asm__(W3D_SYM("_ZN5Entry3s14Ev"));
    int w3d_r_get(int) __asm__(W3D_SYM("_ZN5Entry3getEi"));
 __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void retain() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void put(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Entry, 13))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void s14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Entry, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int get(int w3d_a0) { return ((int (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_Entry, 15))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Entry; };
struct Base {
    void w3d_r_s2() __asm__(W3D_SYM("_ZN4Base2s2Ev"));
    void w3d_r_s3() __asm__(W3D_SYM("_ZN4Base2s3Ev"));
    void w3d_r_s4() __asm__(W3D_SYM("_ZN4Base2s4Ev"));
    int w3d_r_apply(const String &) __asm__(W3D_SYM("_ZN4Base5applyERK6String"));
    void w3d_r_s6() __asm__(W3D_SYM("_ZN4Base2s6Ev"));
    void w3d_r_s7() __asm__(W3D_SYM("_ZN4Base2s7Ev"));
    void w3d_r_s8() __asm__(W3D_SYM("_ZN4Base2s8Ev"));
    void w3d_r_s9() __asm__(W3D_SYM("_ZN4Base2s9Ev"));
    int w3d_r_finish() __asm__(W3D_SYM("_ZN4Base6finishEv"));
 __attribute__((always_inline)) inline void s2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int apply(const String &w3d_a0) { return ((int (*)(w3d_u32, w3d_u32))w3d::vfn(this->w3d_vptr_Base, 5))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0))); }  __attribute__((always_inline)) inline void s6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int finish() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Base, 10))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Base; };
struct Ref { Ptr32<Entry> p; void set(Ptr32<Entry> e) { if (e) e->retain(); if (p) p->release(); p = e; } };
extern "C" Ptr32<Service> service_8020b648();
extern "C" Ptr32<Entry> forward_8020b680(Ptr32<void>);
extern "C" Ptr32<Entry> singleton_8020b884();
extern "C" void set_singleton_8020b960(Ptr32<Entry>);
extern "C" Ptr32<String> string_assign_8020bd38(Ptr32<String>, Ptr32<const char>);
extern unsigned char desc_80419378[];
struct Self : Base { Ptr32<void> u4 __attribute__((aligned(__alignof__(Base)))); Ptr32<void> u8; String name; Ref a; Ref b; };
extern "C" void w3d_d31d_named_holder_setup_8015bf74(Ptr32<Self> self, Ptr32<const char> text) {
    service_8020b648()->set(String(text));
    string_assign_8020bd38(&self->name, text);
    self->a.set(forward_8020b680(desc_80419378));
    self->b.set(singleton_8020b884());
    String m = make_80210958();
    set_singleton_8020b960(self->a.p);
    self->apply(String(""));
    Ptr32<Entry> e = self->a.p;
    e->put(e->get(0));
    self->finish();
}


