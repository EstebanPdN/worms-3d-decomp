#include "w3d_ptr.h"
#line 1 "d31e_read_object_file_80202714.cpp"
// (Worms 3D GameCube PAL, 0x80202714).
//
// Reads an object file into a table of objects: runs the header reader
// (tracing and returning on failure) and the section readers, allocates the
// object table at +28, creates the objects of each class record at +124
// through the factory from 0x8020b648 and each class's maker, stores the
// root object in the result with a reference, lets each object read itself
// and reports it to the optional listener at +36, frees the table, and runs
// the sort pass with state 2. Returns 0, or E_FAIL when a class has no
// maker. Names are inferred.

struct Reader;
struct Item {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN4Item6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN4Item7ReleaseEv"));
    Ptr32<Item> w3d_r_Create() __asm__(W3D_SYM("_ZN4Item6CreateEv"));
    void w3d_r_v5() __asm__(W3D_SYM("_ZN4Item2v5Ev"));
    void w3d_r_Read(Ptr32<Reader>) __asm__(W3D_SYM("_ZN4Item4ReadEP6Reader"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Item> Create() { return ((Ptr32<Item> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Read(Ptr32<Reader> w3d_a0) { ((void (*)(w3d_u32, Ptr32<Reader>))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Item; };
struct ClassItem : Item { };
struct Factory {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN7Factory2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN7Factory6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN7Factory7ReleaseEv")); void w3d_r_v3() __asm__(W3D_SYM("_ZN7Factory2v3Ev"));
    void w3d_r_a4() __asm__(W3D_SYM("_ZN7Factory2a4Ev")), w3d_r_a5() __asm__(W3D_SYM("_ZN7Factory2a5Ev")), w3d_r_a6() __asm__(W3D_SYM("_ZN7Factory2a6Ev")), w3d_r_a7() __asm__(W3D_SYM("_ZN7Factory2a7Ev")), w3d_r_a8() __asm__(W3D_SYM("_ZN7Factory2a8Ev")), w3d_r_a9() __asm__(W3D_SYM("_ZN7Factory2a9Ev")), w3d_r_a10() __asm__(W3D_SYM("_ZN7Factory3a10Ev")), w3d_r_a11() __asm__(W3D_SYM("_ZN7Factory3a11Ev")), w3d_r_a12() __asm__(W3D_SYM("_ZN7Factory3a12Ev")), w3d_r_a13() __asm__(W3D_SYM("_ZN7Factory3a13Ev")), w3d_r_a14() __asm__(W3D_SYM("_ZN7Factory3a14Ev")), w3d_r_a15() __asm__(W3D_SYM("_ZN7Factory3a15Ev")), w3d_r_a16() __asm__(W3D_SYM("_ZN7Factory3a16Ev")), w3d_r_a17() __asm__(W3D_SYM("_ZN7Factory3a17Ev")), w3d_r_a18() __asm__(W3D_SYM("_ZN7Factory3a18Ev"));
    Ptr32<Item> w3d_r_Find(Ptr32<void>) __asm__(W3D_SYM("_ZN7Factory4FindEPv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void a18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Factory, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Item> Find(Ptr32<void> w3d_a0) { return ((Ptr32<Item> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Factory, 21))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_Factory; };
struct Maker { void w3d_r_v0() __asm__(W3D_SYM("_ZN5Maker2v0Ev")),w3d_r_v1() __asm__(W3D_SYM("_ZN5Maker2v1Ev")),w3d_r_v2() __asm__(W3D_SYM("_ZN5Maker2v2Ev")),w3d_r_v3() __asm__(W3D_SYM("_ZN5Maker2v3Ev")),w3d_r_v4() __asm__(W3D_SYM("_ZN5Maker2v4Ev")),w3d_r_v5() __asm__(W3D_SYM("_ZN5Maker2v5Ev")),w3d_r_v6() __asm__(W3D_SYM("_ZN5Maker2v6Ev")),w3d_r_v7() __asm__(W3D_SYM("_ZN5Maker2v7Ev")),w3d_r_v8() __asm__(W3D_SYM("_ZN5Maker2v8Ev")),w3d_r_v9() __asm__(W3D_SYM("_ZN5Maker2v9Ev")),w3d_r_v10() __asm__(W3D_SYM("_ZN5Maker3v10Ev")),w3d_r_v11() __asm__(W3D_SYM("_ZN5Maker3v11Ev")),w3d_r_v12() __asm__(W3D_SYM("_ZN5Maker3v12Ev")),w3d_r_v13() __asm__(W3D_SYM("_ZN5Maker3v13Ev")),w3d_r_v14() __asm__(W3D_SYM("_ZN5Maker3v14Ev")),w3d_r_v15() __asm__(W3D_SYM("_ZN5Maker3v15Ev")),w3d_r_v16() __asm__(W3D_SYM("_ZN5Maker3v16Ev")),w3d_r_v17() __asm__(W3D_SYM("_ZN5Maker3v17Ev")),w3d_r_v18() __asm__(W3D_SYM("_ZN5Maker3v18Ev")),w3d_r_v19() __asm__(W3D_SYM("_ZN5Maker3v19Ev"));
    Ptr32<Item> w3d_r_Make() __asm__(W3D_SYM("_ZN5Maker4MakeEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v6() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 8))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v7() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 9))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v8() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 10))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v9() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 11))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v10() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 12))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v11() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 13))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v12() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 14))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v13() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 15))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v14() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 16))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v15() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 17))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v16() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 18))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v17() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 19))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v18() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 20))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v19() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 21))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Item> Make() { return ((Ptr32<Item> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Maker, 22))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Maker; };
struct Ref {
    Ptr32<Factory> p;
    template <class W3dU> Ref(Ptr32<W3dU> w3d_p) : Ref((Factory *)w3d_p.get()) {}
 Ref(Factory *o) { p = o; if (p) p->AddRef(); }
    Ref(const Ref &);
    ~Ref() { if (p) p->Release(); }
};
struct Record { char u[8]; unsigned count; char u12[4]; char name[48]; };
struct Listener { void w3d_r_Add(unsigned, Ptr32<Item>) __asm__(W3D_SYM("_ZN8Listener3AddEjP4Item"));  __attribute__((always_inline)) inline void Add(unsigned int w3d_a0, Ptr32<Item> w3d_a1) { ((void (*)(w3d_u32, unsigned int, Ptr32<Item>))w3d::vfn(this->w3d_vptr_Listener, 2))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Listener; };
struct Reader {
    char u0[24];
    int state;
    Ptr32<Ptr32<Item>> items;
    unsigned total;
    Ptr32<Listener> listener;
    char u40[44];
    unsigned records;
    unsigned nitems;
    unsigned root;
    char u96[28];
    Ptr32<Record> table;
};
extern int g_trace;
extern const char s_bad[];
extern "C" void w3d_trace_stub_80347324(Ptr32<int>, Ptr32<const char>, ...);
extern "C" int fn_80202f34(Ptr32<Reader>);
extern "C" int w3d_d26e_read_records_802029b8(Ptr32<Reader>);
extern "C" int tsonnet_c26_skip_records_80202b18(Ptr32<Reader>);
extern "C" int tsonnet_c26_read_swap_80202bb4(Ptr32<Reader>);
extern "C" int fn_80202c5c(Ptr32<Reader>);
extern "C" int w3d_auto_80202f28(Ptr32<Reader>);
extern "C" Ptr32<Factory> w3d_auto_8020b648();
extern "C" int cc42b_sort_dispatch_802025dc(Ptr32<Reader>);
extern "C" int w3d_d31e_read_object_file_80202714(Ptr32<Reader> self, Ptr32<Ptr32<Item>> out)
{
    *out = 0;
    self->state = 1;
    int hr = fn_80202f34(self);
    if (hr < 0) {
        w3d_trace_stub_80347324(&g_trace, s_bad);
        return hr;
    }
    w3d_d26e_read_records_802029b8(self);
    tsonnet_c26_skip_records_80202b18(self);
    tsonnet_c26_read_swap_80202bb4(self);
    fn_80202c5c(self);
    w3d_auto_80202f28(self);
    Ref factory(w3d_auto_8020b648());
    unsigned n = 1;
    self->items = w3d::new_array<Item *>(self->nitems + 1);
    self->items[0] = 0;
    for (unsigned i = 0; i < self->records; i++) {
        Ptr32<Record> r = &self->table[i];
        unsigned count = r->count;
        if (count) {
            Ptr32<Item> maker = factory.p->Find(r->name);
            self->items[n++] = maker;
            Ptr32<Item> m = 0;
            if (maker) m = maker->Create();
            if (!m) return 0x80004005;
            for (unsigned j = 1; j < count; j++) {
                self->items[n] = ((Ptr32<Maker>)m)->Make();
                n++;
            }
        }
    }
    self->total = n;
    Ptr32<Item> top = self->items[self->root];
    *out = top;
    top->AddRef();
    for (unsigned k = 1; k <= self->nitems; k++) {
        Ptr32<Item> o = self->items[k];
        o->Read(self);
        if (self->listener) self->listener->Add(k, o);
    }
    w3d::delete_array(self->items);
    self->state = 2;
    cc42b_sort_dispatch_802025dc(self);
    self->state = 0;
    return 0;
}


