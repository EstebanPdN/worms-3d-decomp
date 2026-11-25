#include "w3d_ptr.h"
#line 1 "d25e_release_lists_801b4140.cpp"
// (Worms 3D GameCube PAL, 0x801b4140).
//
// Releases every interface in the vector at +44 (virtual slot 4) and empties
// it, then does the same for the counted array at +60 and resets that array
// with 0x80210afc.

struct Ref { Ptr32<Ptr32<void>> table; void release() { ((Ptr32<void (Ptr32<Ref>)>)table[4])(this); } };
struct RefArray;
extern "C" void fn_80210afc(Ptr32<RefArray>);
struct RefArray {
    unsigned count; unsigned short capacity, growth; Ptr32<Ptr32<Ref>> data;
    Ptr32<Ptr32<Ref>> begin() { return data; }
    Ptr32<Ptr32<Ref>> end() { return data + count; }
    void reset() { fn_80210afc(this); }
};
struct Vec { Ptr32<Ptr32<Ref>> b; Ptr32<Ptr32<Ref>> e; Ptr32<Ptr32<Ref>> c; };
struct Obj { char u[44]; Vec v; char u56[4]; RefArray list; };
extern "C" void w3d_d25e_release_lists_801b4140(Ptr32<Obj> self) {
    for (Ptr32<Ref> *p = self->v.b,*last = self->v.e; p != last; ) { (*p)->release(); ++p; }
    self->v.e = self->v.b;
    for (Ptr32<Ref> *p = self->list.begin(),*last = self->list.end(); p != last; ) { (*p)->release(); ++p; }
    self->list.reset();
}


