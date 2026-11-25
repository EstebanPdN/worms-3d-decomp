#include "w3d_ptr.h"
#line 1 "d30f_wormopaedia_scan_range_8027ffe0.cpp"
// GWMP8P rev0 0x8027ffe0. Scans the Wormopaedia entry list and records the
// first and last index accepted by 0x8028496c, plus how many were accepted.
// The count is read directly through the embedded list holder and the items
// through its inline member.
struct D25fHeldTable { char pad[16]; Ptr32<void (Ptr32<void>)> release; };
struct D25fHeld { Ptr32<D25fHeldTable> vt; };
struct D25fRef {
    Ptr32<D25fHeld> p;
    D25fRef() : p(0) {}
    ~D25fRef() { if (p) p->vt->release(p); }
};
extern "C" void w3d_string_base_init(Ptr32<void>);
extern "C" Ptr32<unsigned short> w3d_string_header(Ptr32<const void>);
struct D25fString {
    Ptr32<char> text;
    D25fString(const D25fString &o) {
        w3d_string_base_init(this);
        text = o.text;
        ++*w3d_string_header(this);
    }
};
struct D25fName { Ptr32<const char> text; template <class W3dU> D25fName(Ptr32<W3dU> w3d_p) : D25fName((const char *)w3d_p.get()) {}
 D25fName(const char *t) : text(t) {} };
extern char lbl_803cee10[];
extern char lbl_803cee1c[];
struct D25fEntry { char pad[24]; D25fString name; };
struct D25fList { char pad[24]; unsigned count; char pad28[4]; Ptr32<D25fEntry> entries[1]; };
struct D25fSub { int a; Ptr32<D25fList> list; Ptr32<Ptr32<D25fEntry>> Items() { return list->entries; } };
struct D25fData { char pad[16]; D25fSub sub; };
extern "C" int w3d_auto_800fc230(const D25fName &, Ptr32<unsigned int>);
extern "C" int s8_property_write_800fc43c(const D25fName &, unsigned);
extern "C" int w3d_constructor_lookup_name(const D25fName &, Ptr32<D25fRef>);
extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<D25fHeld>);
extern "C" Ptr32<D25fData> w3d_auto_801797b4(Ptr32<void>);
struct D25fSelf;
extern "C" int f_8028496c(Ptr32<D25fSelf> self, D25fString name);
extern "C" void f_8027fca8(Ptr32<D25fSelf> self);
struct D25fSelf { char pad[160]; unsigned first, last, total; };
inline bool InRange(Ptr32<D25fData> d, unsigned n) { return d->sub.list->count > n; }
inline Ptr32<Ptr32<D25fEntry>> Items(Ptr32<D25fData> d) { return d->sub.Items(); }
extern "C" void d30f_wormopaedia_scan_range_8027ffe0(Ptr32<D25fSelf> self) {
    self->first = 99;
    self->last = 0;
    self->total = 0;
    D25fRef ref;
    if (w3d_constructor_lookup_name(D25fName(lbl_803cee1c), &ref) < 0)
        return;
    Ptr32<D25fData> data = w3d_auto_801797b4(w3d_empty_80341584(ref.p));
    unsigned count = data->sub.list->count;
    Ptr32<Ptr32<D25fEntry>> entries = Items(data);
    for (unsigned i = 0; i < count; i++) {
        if (f_8028496c(self, entries[i]->name) == 0) {
            if (i < self->first)
                self->first = i;
            if (i > self->last)
                self->last = i;
            self->total++;
        }
    }
}


