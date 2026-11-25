// (Worms 3D GameCube PAL, 0x802092c8).
//
// Configures and opens a named heap: returns 1 if already open and E_FAIL
// without a name; reads <name>.ArenaSize, <name>.Debug (sets flag bits 3),
// then XOM.Arena.PassThrough or <name>.PassThrough (flag bit 16) from the
// config table into zero-initialised int slots, formatting each key into a
// 256-byte buffer, and calls the heap init with the size. Names are inferred.

struct Heap;
extern "C" void w3d_empty_802092c0(Heap *);
extern "C" void w3d_empty_802092c4(Heap *);
extern "C" unsigned w3d_get_802092b8(Heap *);
extern "C" char *w3d_format_into_8034cb64(char *, const char *, ...);
extern "C" int tsonnet_c26_lookup_int_80206920(const char *, int *);
extern "C" int w3d_d30e_heap_init_8020941c(Heap *, unsigned);
struct Heap { int base; char u4[16]; unsigned flags; char u24[28]; const char *name; };
extern const char lbl_803b2ee4[], lbl_803b2ef4[], lbl_803b2f00[], lbl_803b2f18[];
static inline int Lookup(const char *k, int *v) { return tsonnet_c26_lookup_int_80206920(k, v); }
extern "C" int w3d_d41e_heap_config_802092c8(Heap *self)
{
    w3d_empty_802092c0(self);
    if (self->base) return 1;
    if (!self->name) return 0x80004005;
    char buf[256];
    int size = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2ee4, self->name);
    Lookup(buf, &size);
    int debug = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2ef4, self->name);
    Lookup(buf, &debug);
    if (debug) self->flags = w3d_get_802092b8(self) | 3;
    w3d_empty_802092c4(self);
    int pass = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2f00, self->name);
    Lookup(buf, &pass);
    if (!pass) {
        w3d_format_into_8034cb64(buf, lbl_803b2f18, self->name);
        Lookup(buf, &pass);
    }
    if (pass) self->flags = w3d_get_802092b8(self) | 16;
    w3d_d30e_heap_init_8020941c(self, size);
    return 0;
}
