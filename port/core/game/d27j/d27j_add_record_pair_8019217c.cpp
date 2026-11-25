#include "w3d_ptr.h"
#line 1 "d27j_add_record_pair_8019217c.cpp"
#include "compat/stlport_sn_oom.h"
// Add a record and a sized element list, GWMP8P rev0 0x8019217c and 0x801929c0
// (twins). With the global building flag set, pushes a copy of the record and
// an empty element vector (inlined STLport push_back with overflow and vector
// copy), clears the flag, returns the new list through out, resizes it with a
// default element (four cleared flag bits, two 3-bit fields of 5, zero word),
// and counts the record. The first twin uses the object's default size, the
// second takes the size as an argument. Real STLport 4.5.3 vectors over the
// inferred module allocator: the temporary's defaulted allocator argument and the
// copy constructor's get_allocator() give the two untouched slots at sp+24..40
// (d28r); this replaces the former v_convert stand-in.

extern "C" void fn_8020c5c0(Ptr32<void>);
extern "C" void fn_8020c5c4(Ptr32<void>);
extern "C" void fn_80341588(Ptr32<void>);
extern "C" Ptr32<unsigned short> fn_80341884(Ptr32<void>);
extern "C" void fn_80197ce4(Ptr32<void>, int);
extern int building_804ab6f4;
struct Str {
    Ptr32<void> text;
    Str(const Str &o) { fn_8020c5c0(this); text = o.text; ++*fn_80341884(this); }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Body { char b[72]; ~Body() { fn_80197ce4(this, 2); } };
struct Record { Str name; float weight; Body body; unsigned char flag; };
extern "C" void fn_8034f190(Ptr32<void>);
struct Inner { Inner() { fn_8034f190(this); } int a, b; };
struct Elem {
    unsigned short w; /* palabra PPC: bits y luego índice; el índice es la mitad baja del anfitrión */ unsigned short d:6; unsigned short c:3; unsigned short b:3; unsigned short f3:1; unsigned short f2:1; unsigned short f1:1; unsigned short f0:1;
    Inner inner;
    Elem() { }
};
#include <vector>
#include "compat/module_allocator.h"
template <class T> struct V { typedef std::vector<T, ModuleAllocator<T> > type;  char w3d_empty; };
struct Self {
    char u[36];
    V<Record>::type records;
    V<V<Elem>::type>::type lists;
    char u68[4];
    int count;
    unsigned default_size;
};
extern "C" void d27j_add_record_8019217c(Ptr32<Self> self, Ptr32<const Record> rec, Ptr32<Ptr32<V < Elem >::type>> out)
{
    building_804ab6f4 = 1;
    self->records.push_back(*rec);
    self->lists.push_back(V<Elem>::type());
    building_804ab6f4 = 0;
    *out = &self->lists.back();
    { Elem e; e.f0 = 0; e.f1 = 0; e.f2 = 0; e.f3 = 0; e.b = 5; e.c = 5; e.w = 0; (*out)->resize(self->default_size, e); }
    self->count++;
}
extern "C" void d27j_add_record_sized_801929c0(Ptr32<Self> self, Ptr32<const Record> rec, Ptr32<Ptr32<V < Elem >::type>> out, unsigned size)
{
    building_804ab6f4 = 1;
    self->records.push_back(*rec);
    self->lists.push_back(V<Elem>::type());
    building_804ab6f4 = 0;
    *out = &self->lists.back();
    { Elem e; e.f0 = 0; e.f1 = 0; e.f2 = 0; e.f3 = 0; e.b = 5; e.c = 5; e.w = 0; (*out)->resize(size, e); }
    self->count++;
}


