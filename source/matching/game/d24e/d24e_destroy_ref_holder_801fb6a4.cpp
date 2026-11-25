// Destructor of an object holding a vector of references (Worms 3D GameCube PAL, 0x801fb6a4).
//
// Sets the vtable, releases each non-null reference of the vector at +36
// (virtual slot 4), frees the block at +52 and the vector storage through
// 0x802134fc, sets the base vtable and destroys the base part at +8 through
// 0x80210990. Bit 0 of flags deletes self through 0x801fe1f8. Vtables stay
// external. The begin() and end() accessors in the loop make the original's
// hoisted copy of the vector pointer.
extern "C" void fn_802134fc(void *);
extern "C" void fn_80210990(void *, int);
extern "C" void fn_801fe1f8(void *);
extern char vt_80418210[], vt_804182d0[];
struct Ref { void **table; void release() { ((void (*)(Ref *))table[4])(this); } };
struct RefVector {
    Ref **b, **e, **c;
    Ref **begin() { return b; }
    Ref **end() { return e; }
};
struct Obj {
    char *vtable;
    char u04[4];
    char u08[28];
    RefVector refs;
    char u30[4];
    void *data;
};
extern "C" void w3d_d24e_destroy_ref_holder_801fb6a4(Obj *self, unsigned flags) {
    self->vtable = vt_80418210;
    for (Ref **p = self->refs.begin(); p != self->refs.end(); ++p) { if (*p) (*p)->release(); }
    if (self->data) fn_802134fc(self->data);
    if (self->refs.b) fn_802134fc(self->refs.b);
    self->vtable = vt_804182d0;
    fn_80210990(self->u08, 0);
    if (flags & 1) fn_801fe1f8(self);
}
