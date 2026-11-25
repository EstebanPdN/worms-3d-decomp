// (Worms 3D GameCube PAL, 0x801b4140).
//
// Releases every interface in the vector at +44 (virtual slot 4) and empties
// it, then does the same for the counted array at +60 and resets that array
// with 0x80210afc.

struct Ref { void **table; void release() { ((void (*)(Ref *))table[4])(this); } };
struct RefArray;
extern "C" void fn_80210afc(RefArray *);
struct RefArray {
    unsigned count; unsigned short capacity, growth; Ref **data;
    Ref **begin() { return data; }
    Ref **end() { return data + count; }
    void reset() { fn_80210afc(this); }
};
struct Vec { Ref **b, **e, **c; };
struct Obj { char u[44]; Vec v; char u56[4]; RefArray list; };
extern "C" void w3d_d25e_release_lists_801b4140(Obj *self) {
    for (Ref **p = self->v.b, **last = self->v.e; p != last; ) { (*p)->release(); ++p; }
    self->v.e = self->v.b;
    for (Ref **p = self->list.begin(), **last = self->list.end(); p != last; ) { (*p)->release(); ++p; }
    self->list.reset();
}
