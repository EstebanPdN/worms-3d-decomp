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

extern "C" void fn_8020c5c0(void *);
extern "C" void fn_8020c5c4(void *);
extern "C" void fn_80341588(void *);
extern "C" unsigned short *fn_80341884(void *);
extern "C" void fn_80197ce4(void *, int);
extern int building_804ab6f4;
struct Str {
    void *text;
    Str(const Str &o) { fn_8020c5c0(this); text = o.text; ++*fn_80341884(this); }
    ~Str() { fn_8020c5c4(this); fn_80341588(this); }
};
struct Body { char b[72]; ~Body() { fn_80197ce4(this, 2); } };
struct Record { Str name; float weight; Body body; unsigned char flag; };
extern "C" void fn_8034f190(void *);
struct Inner { Inner() { fn_8034f190(this); } int a, b; };
struct Elem {
    unsigned f0 : 1; unsigned f1 : 1; unsigned f2 : 1; unsigned f3 : 1; unsigned b : 3; unsigned c : 3; unsigned d : 6; unsigned short w;
    Inner inner;
    Elem() { }
};
#include <vector>
#include "compat/module_allocator.h"
template <class T> struct V { typedef std::vector<T, ModuleAllocator<T> > type; };
struct Self {
    char u[36];
    V<Record>::type records;
    V<V<Elem>::type>::type lists;
    char u68[4];
    int count;
    unsigned default_size;
};
extern "C" void d27j_add_record_8019217c(Self *self, const Record *rec, V<Elem>::type **out)
{
    building_804ab6f4 = 1;
    self->records.push_back(*rec);
    self->lists.push_back(V<Elem>::type());
    building_804ab6f4 = 0;
    *out = &self->lists.back();
    { Elem e; e.f0 = 0; e.f1 = 0; e.f2 = 0; e.f3 = 0; e.b = 5; e.c = 5; e.w = 0; (*out)->resize(self->default_size, e); }
    self->count++;
}
extern "C" void d27j_add_record_sized_801929c0(Self *self, const Record *rec, V<Elem>::type **out, unsigned size)
{
    building_804ab6f4 = 1;
    self->records.push_back(*rec);
    self->lists.push_back(V<Elem>::type());
    building_804ab6f4 = 0;
    *out = &self->lists.back();
    { Elem e; e.f0 = 0; e.f1 = 0; e.f2 = 0; e.f3 = 0; e.b = 5; e.c = 5; e.w = 0; (*out)->resize(size, e); }
    self->count++;
}
