// GWMP8P rev0 0x8019ce60. Resets an object's state stacks: clears the real
// STLport 4.5.3 vector of 28-byte elements (three retained references, a
// flag and a list) and the byte vector, then pushes one default element and
// a zero byte. Class and field names are inferred.
#include "compat/stlport_sn_oom.h"
#include <vector>
/* Ref-counted COM-style interface: slots 12 and 16 are retain and release. */
struct Obj { virtual void s0(); virtual void retain(); virtual void release(); };
struct Ref {
    Obj *p;
    Ref() : p(0) {}
    Ref(const Ref &o) { p = o.p; if (p) p->retain(); }
    ~Ref() { if (p) p->release(); }
};
struct List { int body[3]; List(); List(const List &); ~List(); };
extern "C" void fn_801f2678(List *);
extern "C" void * fn_801f2698(List *, const List *);
extern "C" void fn_801f2758(List *, int);
inline List::List() { fn_801f2678(this); }
inline List::List(const List &o) { fn_801f2698(this, &o); }
inline List::~List() { fn_801f2758(this, 2); }
struct Elem { Ref a, b, c; unsigned char flag; List list; };
struct Self {
    char u0[44];
    int f44, f48;
    _STL::vector<Elem> elems;
    _STL::vector<unsigned char> bytes;
};
extern "C" int w3d_d40n_reset_state_lists_8019ce60(Self *self) {
    self->f44 = 0;
    self->f48 = 0;
    self->elems.clear();
    self->bytes.clear();
    Elem e;
    self->elems.push_back(e);
    self->bytes.push_back(0);
    return 0;
}
