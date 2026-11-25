// Serializes a counted word list through a stream object (Worms 3D GameCube PAL, 0x801de218).
//
// Exchanges the count through virtual slot 42, resizes the list at +20 through
// 0x80210b90, exchanges each element through slot 8 and the word at +32 through
// slot 37, and returns 0. Virtual slots are read from the original; their
// meanings are inferred. The begin() accessor makes the hoisted list pointer copy.
struct Stream { void **table; };
struct List { unsigned count; unsigned short capacity, growth; int *data; int *begin() { return data; } };
struct Obj { char u[20]; List list; int value; };
extern "C" void fn_80210b90(List *, unsigned);
inline int Call(Stream *s, int slot, void *p, int x) { return ((int (*)(Stream *, void *, int))s->table[slot])(s, p, x); }
extern "C" int w3d_d24e_serialize_list_801de218(Obj *self, Stream *s) {
    unsigned n;
    Call(s, 42, &n, 0);
    fn_80210b90(&self->list, n);
    for (unsigned i = 0; i < n; ++i) Call(s, 8, self->list.begin() + i, 0);
    Call(s, 37, &self->value, 0);
    return 0;
}
