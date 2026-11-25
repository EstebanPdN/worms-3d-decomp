#include "w3d_ptr.h"
#line 1 "d33s_name_table_ctor_80069c8c.cpp"
/* GWMP8P rev0 0x80069c8c. Constructor of a game service with 44 held references, a name list, a table of
 * 128 rows of 6 names and two more names; publishes itself in a global and fills a table of 11 default flags.
 * Names are inferred. Each flag clear is written separately because the original merges 1-bit fields only. */
extern "C" Ptr32<void> memset(Ptr32<void>, int, unsigned int);
struct Obj { void w3d_r_s0() __asm__(W3D_SYM("_ZN3Obj2s0Ev")); void w3d_r_s1() __asm__(W3D_SYM("_ZN3Obj2s1Ev")); void w3d_r_release() __asm__(W3D_SYM("_ZN3Obj7releaseEv"));  __attribute__((always_inline)) inline void s0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void s1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Obj, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Obj; };
struct Ref {
    Ptr32<Obj> p;
    Ref() : p(0) {}
    template <class W3dU> decltype(auto) operator=(Ptr32<W3dU> w3d_p) { return this->operator=((Obj *)w3d_p.get()); }
 Ref &operator=(Obj *q) { if (p) p->release(); p = q; return *this; }
};
struct D33sName { Ptr32<char> text; D33sName(); D33sName(const D33sName &); };
struct D33sNameList { D33sNameList(); int u[5]; };
struct D33sList { D33sNameList names; int a, b, u28, c, d, e, u40, u44; unsigned int u12:20; unsigned int f11:1; unsigned int f10:1; unsigned int f9:1; unsigned int u8:1; unsigned int f7:1; unsigned int f6:1; unsigned int f5:1; unsigned int f4:1; unsigned int f3:1; unsigned int f2:1; unsigned int f1:1; unsigned int f0:1; };
struct D33sRoot { ~D33sRoot();  __attribute__((always_inline)) inline void w3d_vdt(int w3d_in) const { ((void (*)(w3d_u32, int))w3d::vfn(this->w3d_vptr_D33sRoot, 2))(w3d::h2g(this), w3d_in); }  Ptr32<void> w3d_vptr_D33sRoot; };
struct D33sBase : D33sRoot { D33sBase(); char u4[24] __attribute__((aligned(__alignof__(D33sRoot)))); };
struct D33sNameTable : D33sBase {
    D33sNameTable();
    ~D33sNameTable();
    Ref r28 __attribute__((aligned(__alignof__(D33sBase)))); Ref r32; Ref r36; Ref r40; Ref r44; Ref r48; Ref r52; Ref r56; Ref r60; Ref r64; Ref r68; Ref r72; Ref r76; Ref r80; Ref r84; Ref r88; Ref r92; Ref r96; Ref r100; Ref r104; Ref r108; Ref r112; Ref r116; Ref r120; Ref r124; Ref r128; Ref r132; Ref r136; Ref r140; Ref r144; Ref r148; Ref r152; Ref r156; Ref r160; Ref r164; Ref r168; Ref r172; Ref r176; Ref r180; Ref r184;
    D33sList list;
    Ref z244, z248, z252, z256; int u260;
    D33sName names[128][6];
    int count;
    D33sName a, b;
};
extern Ptr32<D33sNameTable> d33s_name_table_804aaabc;
extern int d33s_name_defaults_8042e700[11];
D33sNameTable::D33sNameTable()  { W3D_SET_VPTR(this->D33sBase::w3d_vptr_D33sRoot, w3d_vt___vt_13D33sNameTable, "__vt_13D33sNameTable"); 
    d33s_name_table_804aaabc = this;
    list.a = 10;
    list.b = 10;
    list.c = -1;
    list.d = -1;
    list.e = -1;
    list.f0 = 1;
    r184 = 0;
    list.f1 = 1;
    count = 5;
    list.f2 = 0;
    list.f3 = 0;
    list.f4 = 0;
    list.f5 = 0;
    list.f6 = 0;
    list.f7 = 0;
    list.f10 = 0;
    list.f11 = 0;
    memset(d33s_name_defaults_8042e700, 1, 44);
    d33s_name_defaults_8042e700[0] = 0;
    d33s_name_defaults_8042e700[1] = 0;
    d33s_name_defaults_8042e700[2] = 0;
    d33s_name_defaults_8042e700[3] = 0;
    d33s_name_defaults_8042e700[4] = 0;
    d33s_name_defaults_8042e700[5] = 1;
    d33s_name_defaults_8042e700[6] = 1;
    d33s_name_defaults_8042e700[7] = 1;
    d33s_name_defaults_8042e700[8] = 0;
    d33s_name_defaults_8042e700[9] = 0;
    d33s_name_defaults_8042e700[10] = 0;
    list.f9 = 0;
}

W3D_DT_THUNK("_ZN8D33sRootD1Ev", 2, "_._8D33sRoot");
W3D_DT_THUNK("_ZN8D33sRootD2Ev", 0, "_._8D33sRoot");
