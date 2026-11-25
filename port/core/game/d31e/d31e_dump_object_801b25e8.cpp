#include "w3d_ptr.h"
#line 1 "d31e_dump_object_801b25e8.cpp"
// (Worms 3D GameCube PAL, 0x801b25e8).
//
// Writes a readable dump of an object to the dumper's stream: a local
// formatting writer on the output at +40 prints the class name and address,
// then, walking the class chain from root to leaf, prints each property:
// array properties as name, count and elements (recursing for object
// elements, or through 0x801ef970 for plain ones), others as name = value
// (recursing for object values), with indent and closing lines. Takes the
// interface pointer (object at -4). Names are inferred.

struct Out { void w3d_r_v0() __asm__(W3D_SYM("_ZN3Out2v0Ev")); void w3d_r_AddRef() __asm__(W3D_SYM("_ZN3Out6AddRefEv")); void w3d_r_Release() __asm__(W3D_SYM("_ZN3Out7ReleaseEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Out, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void AddRef() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Out, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void Release() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Out, 4))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Out; };
struct String { Ptr32<char> p; };
struct Writer;
extern Writer &endl(Writer &);
struct Writer {
    Ptr32<Out> out;
    unsigned int rest:11; unsigned int width:5; unsigned int fill:8; unsigned int upper:1; unsigned int base:7;
    template <class W3dU> Writer(Ptr32<W3dU> w3d_p) : Writer((Out *)w3d_p.get()) {}
 Writer(Out *o) {
        out = o;
        if (out) out->AddRef();
        base = 10;
        upper = 0;
        fill = 0;
        width = 6;
    }
    ~Writer() { if (out) out->Release(); }
    Writer &operator<<(const String &s);
    Writer &operator<<(const char *s);
    Writer &operator<<(unsigned n);
    Writer &operator<<(Ptr32<Writer &(Writer &)> m) { return m(*this); }
};
extern "C" int w3d_format_into_80355a44(Ptr32<char>, Ptr32<const char>, ...);
struct Class;
struct Type;
extern "C" Ptr32<const char> w3d_auto_801ffea8(Ptr32<Class>);
extern "C" int w3d_auto_801fffc8(Ptr32<Type>);
struct Prop { Ptr32<const char> name; short offset; unsigned char b6, flags; Ptr32<Type> type; };
struct Item {
    Ptr32<Prop> prop;
    void w3d_r_v0() __asm__(W3D_SYM("_ZN4Item2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN4Item2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN4Item2v2Ev"));
    void w3d_r_print(Writer &, Ptr32<void>) __asm__(W3D_SYM("_ZN4Item5printER6WriterPv"));
    void w3d_r_v4() __asm__(W3D_SYM("_ZN4Item2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN4Item2v5Ev"));
    Ptr32<Ptr32<void>> w3d_r_get(Ptr32<void>, Ptr32<unsigned int>) __asm__(W3D_SYM("_ZN4Item3getEPvPj"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void print(Writer &w3d_a0, Ptr32<void> w3d_a1) { ((void (*)(w3d_u32, w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_Item, 5))(w3d::h2g(this), w3d::h2g(__builtin_addressof(w3d_a0)), w3d_a1); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Item, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Ptr32<void>> get(Ptr32<void> w3d_a0, Ptr32<unsigned int> w3d_a1) { return ((Ptr32<Ptr32<void>> (*)(w3d_u32, Ptr32<void>, Ptr32<unsigned int>))w3d::vfn(this->w3d_vptr_Item, 8))(w3d::h2g(this), w3d_a0, w3d_a1); }  Ptr32<void> w3d_vptr_Item; };
struct ObjectItem {
    Ptr32<Prop> prop;
    void w3d_r_v0() __asm__(W3D_SYM("_ZN10ObjectItem2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN10ObjectItem2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN10ObjectItem2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN10ObjectItem2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN10ObjectItem2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN10ObjectItem2v5Ev"));
    Ptr32<Ptr32<void>> w3d_r_get(Ptr32<void>) __asm__(W3D_SYM("_ZN10ObjectItem3getEPv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ObjectItem, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Ptr32<void>> get(Ptr32<void> w3d_a0) { return ((Ptr32<Ptr32<void>> (*)(w3d_u32, Ptr32<void>))w3d::vfn(this->w3d_vptr_ObjectItem, 8))(w3d::h2g(this), w3d_a0); }  Ptr32<void> w3d_vptr_ObjectItem; };
struct Object { void w3d_r_v0() __asm__(W3D_SYM("_ZN6Object2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN6Object2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN6Object2v2Ev")); Ptr32<Class> w3d_r_GetClass() __asm__(W3D_SYM("_ZN6Object8GetClassEv"));  __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline Ptr32<Class> GetClass() { return ((Ptr32<Class> (*)(w3d_u32))w3d::vfn(this->w3d_vptr_Object, 5))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_Object; };
struct ClassBase {
    void w3d_r_v0() __asm__(W3D_SYM("_ZN9ClassBase2v0Ev")); void w3d_r_v1() __asm__(W3D_SYM("_ZN9ClassBase2v1Ev")); void w3d_r_v2() __asm__(W3D_SYM("_ZN9ClassBase2v2Ev")); void w3d_r_v3() __asm__(W3D_SYM("_ZN9ClassBase2v3Ev")); void w3d_r_v4() __asm__(W3D_SYM("_ZN9ClassBase2v4Ev")); void w3d_r_v5() __asm__(W3D_SYM("_ZN9ClassBase2v5Ev"));
    unsigned w3d_r_Count() __asm__(W3D_SYM("_ZN9ClassBase5CountEv"));
 __attribute__((always_inline)) inline void v0() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 2))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v1() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 3))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v2() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 4))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v3() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 5))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v4() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 6))(w3d::h2g(this)); }  __attribute__((always_inline)) inline void v5() { ((void (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 7))(w3d::h2g(this)); }  __attribute__((always_inline)) inline unsigned int Count() { return ((unsigned int (*)(w3d_u32))w3d::vfn(this->w3d_vptr_ClassBase, 8))(w3d::h2g(this)); }  Ptr32<void> w3d_vptr_ClassBase; };
struct Class : ClassBase {
    char pad[16] __attribute__((aligned(__alignof__(ClassBase))));
    Ptr32<Class> parent;
    char pad24[24];
    struct Items { Ptr32<Ptr32<Item>> v; Ptr32<Item> operator[](unsigned i) { return *(Ptr32<Ptr32<Item>>)((Ptr32<char>)v + (i << 2)); } } items;
};
struct Dumper {
    char pad0[40];
    Ptr32<Out> out;
    char pad44[4];
    int limit;
    char pad52[8];
    String line;
};
extern "C" void w3d_k4b_writer_append_indent_801b2550(Ptr32<Dumper>);
extern "C" void w3d_s20_shrink_range_801b25ac(Ptr32<Dumper>);
extern "C" void w3d_d29e_print_array_801ef970(Ptr32<Item>, Ptr32<Writer>, Ptr32<void>, int, Ptr32<char>);

extern const char s_at[], s_fmt[], s_open[], s_count[], s_mid[], s_close[], s_eq[], s_end[];

extern "C" int w3d_d31e_dump_object_801b25e8(Ptr32<char> iface, Ptr32<Object> obj)
{
    if (obj) {
        Ptr32<Dumper> self = iface ? w3d::R((Ptr32<Dumper>)(iface - 4)) : 0;
        Writer w(self->out);
        Ptr32<Class> chain[32];
        char buf[16];
        Ptr32<Class> cls = obj->GetClass();
        int n = 0;
        Writer &a = w << self->line << (const char *)w3d_auto_801ffea8(cls) << s_at;
        w3d_format_into_80355a44(buf, s_fmt, w3d::VA(obj));
        a << buf << s_open << endl;
        w3d_k4b_writer_append_indent_801b2550(self);
        {
            Ptr32<Class> prev;
            do {
                chain[n] = cls;
                prev = cls;
                cls = cls->parent;
                n++;
            } while (cls != prev);
        }
        while (n != 0) {
            cls = chain[--n];
            unsigned count = cls->Count();
            for (unsigned i = 0; i < count; i++) {
                Ptr32<Item> item = cls->items[i];
                if (item->prop->flags & 1) {
                    unsigned total;
                    Ptr32<Ptr32<void>> values = item->get(obj, &total);
                    w << self->line << (const char *)item->prop->name << s_count << total << s_mid << endl;
                    if (w3d_auto_801fffc8(item->prop->type) == 24) {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        for (unsigned j = 0; j < total; j++) w3d_d31e_dump_object_801b25e8(iface, (Ptr32<Object>)values[j]);
                        w3d_s20_shrink_range_801b25ac(self);
                    } else {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        w << self->line;
                        w3d_d29e_print_array_801ef970(item, &w, obj, self->limit, self->line.p);
                        w3d_s20_shrink_range_801b25ac(self);
                        w << endl;
                    }
                    w << self->line << s_close << endl;
                } else {
                    w << self->line << (const char *)item->prop->name << s_eq;
                    item->print(w, obj);
                    w << endl;
                    if (w3d_auto_801fffc8(item->prop->type) == 24) {
                        w3d_k4b_writer_append_indent_801b2550(self);
                        Ptr32<Ptr32<void>> sub = ((Ptr32<ObjectItem>)item)->get(obj);
                        if (sub) w3d_d31e_dump_object_801b25e8(iface, (Ptr32<Object>)*sub);
                        w3d_s20_shrink_range_801b25ac(self);
                    }
                }
            }
        }
        w3d_s20_shrink_range_801b25ac(self);
        w << self->line << s_end << endl;
    }
    return 0;
}


