#include "w3d_ptr.h"
#line 1 "d31e_load_sound_bank_801dbeb4.cpp"
// (Worms 3D GameCube PAL, 0x801dbeb4).
//
// Loads a MusyX sound bank by base name: first walks the group definitions
// (56-byte records ending with a null first word): if a group with the
// record's id is not in the list at +36, calls the add slot and searches the
// same record again; once found, calls the attach slot and advances. If not
// already started, loads <name>.pool, .proj, .samp (from the audio heap) and
// .sdir through 0x801db7a8, returning 0 on the first failure; stops any
// running sound system, starts it with the four buffers, sets the master
// volume 127/0/255, frees the sample buffer and clears +196. Always returns
// 0. Names are inferred.

struct String;
extern "C" void w3d_string_default(Ptr32<String>);
extern "C" void w3d_string_format(Ptr32<String>, Ptr32<const char>, ...);
extern "C" void w3d_string_base_init(Ptr32<String>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<String>);
extern "C" void w3d_string_base_finish(Ptr32<String>);
extern "C" void w3d_string_release(Ptr32<String>);
struct String {
    Ptr32<char> p;
    String();
    String(const String &o) {
        w3d_string_base_init(this);
        p = o.p;
        ++*w3d_string_header(this);
    }
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
static inline void use(String) { }
struct Group { char pad[36]; int id; };
struct Def { Ptr32<void> ptr; int a; int id; char rest[44]; };
struct GroupList {
    unsigned count;
    int x4;
    Ptr32<Ptr32<Group>> data;
    unsigned size() const { return count; }
    Ptr32<Group> operator[](unsigned i) { return data[i]; }
    Ptr32<Group> & at(unsigned i) { return data[i]; }
};
struct BankBase {
    void w3d_r_a0() __asm__(W3D_SYM("_ZN8BankBase2a0Ev")),w3d_r_a1() __asm__(W3D_SYM("_ZN8BankBase2a1Ev")),w3d_r_a2() __asm__(W3D_SYM("_ZN8BankBase2a2Ev")),w3d_r_a3() __asm__(W3D_SYM("_ZN8BankBase2a3Ev")),w3d_r_a4() __asm__(W3D_SYM("_ZN8BankBase2a4Ev")),w3d_r_a5() __asm__(W3D_SYM("_ZN8BankBase2a5Ev")),w3d_r_a6() __asm__(W3D_SYM("_ZN8BankBase2a6Ev")),w3d_r_a7() __asm__(W3D_SYM("_ZN8BankBase2a7Ev")),w3d_r_a8() __asm__(W3D_SYM("_ZN8BankBase2a8Ev")),w3d_r_a9() __asm__(W3D_SYM("_ZN8BankBase2a9Ev")),w3d_r_a10() __asm__(W3D_SYM("_ZN8BankBase3a10Ev")),w3d_r_a11() __asm__(W3D_SYM("_ZN8BankBase3a11Ev")),w3d_r_a12() __asm__(W3D_SYM("_ZN8BankBase3a12Ev")),w3d_r_a13() __asm__(W3D_SYM("_ZN8BankBase3a13Ev")),w3d_r_a14() __asm__(W3D_SYM("_ZN8BankBase3a14Ev")),w3d_r_a15() __asm__(W3D_SYM("_ZN8BankBase3a15Ev")),w3d_r_a16() __asm__(W3D_SYM("_ZN8BankBase3a16Ev")),w3d_r_a17() __asm__(W3D_SYM("_ZN8BankBase3a17Ev")),w3d_r_a18() __asm__(W3D_SYM("_ZN8BankBase3a18Ev")),w3d_r_a19() __asm__(W3D_SYM("_ZN8BankBase3a19Ev")),w3d_r_a20() __asm__(W3D_SYM("_ZN8BankBase3a20Ev")),w3d_r_a21() __asm__(W3D_SYM("_ZN8BankBase3a21Ev")),w3d_r_a22() __asm__(W3D_SYM("_ZN8BankBase3a22Ev")),w3d_r_a23() __asm__(W3D_SYM("_ZN8BankBase3a23Ev")),w3d_r_a24() __asm__(W3D_SYM("_ZN8BankBase3a24Ev")),w3d_r_a25() __asm__(W3D_SYM("_ZN8BankBase3a25Ev")),w3d_r_a26() __asm__(W3D_SYM("_ZN8BankBase3a26Ev")),w3d_r_a27() __asm__(W3D_SYM("_ZN8BankBase3a27Ev")),w3d_r_a28() __asm__(W3D_SYM("_ZN8BankBase3a28Ev")),w3d_r_a29() __asm__(W3D_SYM("_ZN8BankBase3a29Ev")),w3d_r_a30() __asm__(W3D_SYM("_ZN8BankBase3a30Ev")),w3d_r_a31() __asm__(W3D_SYM("_ZN8BankBase3a31Ev")),w3d_r_a32() __asm__(W3D_SYM("_ZN8BankBase3a32Ev")),w3d_r_a33() __asm__(W3D_SYM("_ZN8BankBase3a33Ev"));
    void w3d_r_a33b() __asm__(W3D_SYM("_ZN8BankBase4a33bEv"));
    void w3d_r_missing(int) __asm__(W3D_SYM("_ZN8BankBase7missingEi"));
    void w3d_r_a35() __asm__(W3D_SYM("_ZN8BankBase3a35Ev")),w3d_r_a36() __asm__(W3D_SYM("_ZN8BankBase3a36Ev"));
    void w3d_r_found(Ptr32<Group>, Ptr32<Def>) __asm__(W3D_SYM("_ZN8BankBase5foundEP5GroupP3Def"));
 __attribute__((always_inline)) inline void a0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 22))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a21() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 23))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a22() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 24))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a23() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 25))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 26))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a25() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 27))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a26() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 28))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a27() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 29))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 30))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a29() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 31))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a30() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 32))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a31() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 33))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 34))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a33() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 35))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a33b() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 36))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void missing(int w3d_a0) { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_BankBase, 37))(w3d::h2g(this), w3d_a0); }  __attribute__((always_inline)) inline void a35() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 38))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_BankBase, 39))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void found(Ptr32<Group> w3d_a0, Ptr32<Def> w3d_a1) { ((void (*)(w3d_u32, Ptr32<Group>, Ptr32<Def>))w3d::vfn(this->w3d_vptr_BankBase, 40))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_BankBase; };
struct Bank : BankBase {
    char pad4[32] __attribute__((aligned(__alignof__(BankBase))));
    GroupList list;
    char pad48[132];
    int started;
    Ptr32<void> pool; Ptr32<void> proj; Ptr32<void> sdir; Ptr32<void> samp;
};
struct Heap;
extern Ptr32<Heap> g_audioHeap;
extern int g_trace;
extern const char s_pool[], s_proj[], s_samp[], s_sdir[], s_freeing[];
extern "C" Ptr32<void> fn_801db7a8(Ptr32<Bank>, Ptr32<const char>, int);
extern "C" void fn_8032fb54();
extern "C" void fn_8032f828(Ptr32<void>, int, Ptr32<void>, Ptr32<void>, Ptr32<void>);
extern "C" void fn_803229fc(int, int, int);
extern "C" void w3d_trace_stub_80347324(Ptr32<int>, Ptr32<const char>, ...);
extern "C" void w3d_heap_release(Ptr32<Heap>, Ptr32<void>);
extern "C" void w3d_auto_80209968(Ptr32<Heap>);

extern "C" int w3d_d31e_load_sound_bank_801dbeb4(Ptr32<Bank> self, Ptr32<const char> name, Ptr32<Def> defs)
{
    int i = 0;
    Ptr32<Group> item = 0;
    while (defs[i].ptr) {
        bool found = false;
        for (unsigned j = 0; j < self->list.size(); j++) {
            Ptr32<Group> g = self->list[j];
            item = g;
            if (self->list[j]->id == defs[i].id) { found = true; break; }
        }
        if (!found) self->missing(defs[i].id);
        else {
            self->found(item, &defs[i]);
            i++;
        }
    }
    String s;
    if (self->started) return 0;
    w3d_string_format(&s, s_pool, w3d::VA(name));
    use(s);
    self->pool = fn_801db7a8(self, s.p, 0);
    if (!self->pool) return 0;
    w3d_string_format(&s, s_proj, w3d::VA(name));
    use(s);
    self->proj = fn_801db7a8(self, s.p, 0);
    if (!self->proj) return 0;
    w3d_string_format(&s, s_samp, w3d::VA(name));
    use(s);
    self->samp = fn_801db7a8(self, s.p, 1);
    if (!self->samp) return 0;
    w3d_string_format(&s, s_sdir, w3d::VA(name));
    use(s);
    self->sdir = fn_801db7a8(self, s.p, 0);
    if (!self->sdir) return 0;
    if (self->started) {
        fn_8032fb54();
        self->started = 0;
    }
    if (self->proj && self->samp && self->sdir && self->pool) {
        fn_8032f828(self->proj, 0, self->samp, self->sdir, self->pool);
        self->started = 1;
        fn_803229fc(127, 0, 255);
    }
    if (self->samp) w3d_trace_stub_80347324(&g_trace, s_freeing, w3d::VA(self->samp), w3d::VA(g_audioHeap));
    w3d_heap_release(g_audioHeap, self->samp);
    w3d_auto_80209968(g_audioHeap);
    self->samp = 0;
    return 0;
}


