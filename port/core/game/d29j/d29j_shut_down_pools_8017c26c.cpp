#include "w3d_ptr.h"
// Port (v29): los huecos viven en core/native/tabla_recursos.cpp (4096 en vez de 1920).
extern "C" Ptr32<void> *w3d_restab_slots(void);
extern "C" unsigned w3d_restab_cap(void);
#line 1 "d29j_shut_down_pools_8017c26c.cpp"
// Shut down the resource pools, GWMP8P rev0 0x8017c26c. If the owner is active:
// pumps 128 channels through its virtual slot, flushes, and when any of the six
// pools reports entries in use, walks the 1920 slots; a busy slot's name string
// is copied and its use count raised, then the copy is released. Flushes again.
// Then clears the active bit, stops the owner and resizes every pool to zero.
// Virtual slot meanings are inferred; offsets come from the original.
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
struct Slot {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN4Slot2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN4Slot3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN4Slot3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN4Slot3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN4Slot3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN4Slot3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN4Slot3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN4Slot3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN4Slot3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN4Slot3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN4Slot3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN4Slot3s52Ev")); void w3d_r_s56() __asm__(W3D_SYM("_ZN4Slot3s56Ev")); void w3d_r_s60() __asm__(W3D_SYM("_ZN4Slot3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN4Slot3s64Ev"));
    Ptr32<const Str> w3d_r_s68() __asm__(W3D_SYM("_ZN4Slot3s68Ev"));
    void w3d_r_s72() __asm__(W3D_SYM("_ZN4Slot3s72Ev")); void w3d_r_s76() __asm__(W3D_SYM("_ZN4Slot3s76Ev"));
    int w3d_r_busy() __asm__(W3D_SYM("_ZN4Slot4busyEv"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s56() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<const Str> s68() { return ((Ptr32<const Str> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s72() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s76() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline int busy() { return ((int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Slot, 20))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Slot; };
struct H { Ptr32<Slot> p; Ptr32<Slot> operator->() const { return p; } Ptr32<Slot> get() const { return p; } };
struct OwnerBase {
    void w3d_r_s8() __asm__(W3D_SYM("_ZN9OwnerBase2s8Ev")); void w3d_r_s12() __asm__(W3D_SYM("_ZN9OwnerBase3s12Ev")); void w3d_r_s16() __asm__(W3D_SYM("_ZN9OwnerBase3s16Ev")); void w3d_r_s20() __asm__(W3D_SYM("_ZN9OwnerBase3s20Ev")); void w3d_r_s24() __asm__(W3D_SYM("_ZN9OwnerBase3s24Ev")); void w3d_r_s28() __asm__(W3D_SYM("_ZN9OwnerBase3s28Ev")); void w3d_r_s32() __asm__(W3D_SYM("_ZN9OwnerBase3s32Ev")); void w3d_r_s36() __asm__(W3D_SYM("_ZN9OwnerBase3s36Ev")); void w3d_r_s40() __asm__(W3D_SYM("_ZN9OwnerBase3s40Ev")); void w3d_r_s44() __asm__(W3D_SYM("_ZN9OwnerBase3s44Ev")); void w3d_r_s48() __asm__(W3D_SYM("_ZN9OwnerBase3s48Ev")); void w3d_r_s52() __asm__(W3D_SYM("_ZN9OwnerBase3s52Ev"));
    void w3d_r_stop() __asm__(W3D_SYM("_ZN9OwnerBase4stopEv"));
    void w3d_r_s60() __asm__(W3D_SYM("_ZN9OwnerBase3s60Ev")); void w3d_r_s64() __asm__(W3D_SYM("_ZN9OwnerBase3s64Ev"));
    void w3d_r_flush() __asm__(W3D_SYM("_ZN9OwnerBase5flushEv"));
    void w3d_r_pump(Ptr32<unsigned char> counter, int n) __asm__(W3D_SYM("_ZN9OwnerBase4pumpEPhi"));
 __attribute__((always_inline)) inline void s8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s20() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s24() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s28() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s32() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s36() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s40() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s44() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s48() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s52() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void stop() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s60() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s64() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void flush() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_OwnerBase, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void pump(Ptr32<unsigned char> w3d_a0, int w3d_a1) { ((void (*)(w3d_u32, Ptr32<unsigned char>, int))w3d::vfn(this->w3d_vptr_OwnerBase, 18))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_OwnerBase; };
struct Owner : OwnerBase {
    char u4[16] __attribute__((aligned(__alignof__(OwnerBase))));
    int :31; int active:1;
    H slots[1920];
};
extern "C" int fn_80170b18();
extern "C" int fn_8017f52c();
extern "C" int fn_80174528();
extern "C" int fn_80187754();
extern "C" int fn_8018a7ec();
extern "C" int fn_801829c4();
extern "C" int fn_801709b0(int);
extern "C" int fn_8017f3b8(int);
extern "C" int fn_801743b4(int);
extern "C" int fn_801875e0(int);
extern "C" int fn_8018a678(int);
extern "C" int fn_80182850(int);
extern "C" int fn_80183d48(int);

extern "C" int d29j_shut_down_pools_8017c26c(Ptr32<Owner> self)
{
    if (self->active) {
        unsigned char i = 0;
        do {
            self->pump(&i, 1);
            i++;
        } while (!(i & 128));
        self->flush();
        int a = fn_80170b18();
        int b = fn_8017f52c();
        int c = fn_80174528();
        int d = fn_80187754();
        int e = fn_8018a7ec();
        if (a + b + c + d + e + fn_801829c4()) {
            H *slots = (H *)w3d_restab_slots();   // port (v29): tabla nativa
            for (unsigned short k = 0; k < w3d_restab_cap(); k++) {
                if (slots[k].get() && slots[k]->busy()) {
                    slots[k]->busy();
                    Str s(*slots[k]->s68());
                }
            }
            self->flush();
        }
        unsigned char j = 0;
        do { j++; } while (!(j & 128));
        }
    self->active = 0;
    self->stop();
    fn_801709b0(0);
    fn_8017f3b8(0);
    fn_801743b4(0);
    fn_801875e0(0);
    fn_8018a678(0);
    fn_80182850(0);
    fn_80183d48(0);
    return 0;
}



