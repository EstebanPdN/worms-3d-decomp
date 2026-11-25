#include "w3d_ptr.h"
#line 1 "d41e_heap_config_802092c8.cpp"
// (Worms 3D GameCube PAL, 0x802092c8).
//
// Configures and opens a named heap: returns 1 if already open and E_FAIL
// without a name; reads <name>.ArenaSize, <name>.Debug (sets flag bits 3),
// then XOM.Arena.PassThrough or <name>.PassThrough (flag bit 16) from the
// config table into zero-initialised int slots, formatting each key into a
// 256-byte buffer, and calls the heap init with the size. Names are inferred.

struct Heap;
extern "C" void w3d_empty_802092c0(Ptr32<Heap>);
extern "C" void w3d_empty_802092c4(Ptr32<Heap>);
extern "C" unsigned w3d_get_802092b8(Ptr32<Heap>);
extern "C" Ptr32<char> w3d_format_into_8034cb64(Ptr32<char>, Ptr32<const char>, ...);
extern "C" int tsonnet_c26_lookup_int_80206920(Ptr32<const char>, Ptr32<int>);
extern "C" int w3d_d30e_heap_init_8020941c(Ptr32<Heap>, unsigned);
struct Heap { int base; char u4[16]; unsigned flags; char u24[28]; Ptr32<const char> name; };
extern const char lbl_803b2ee4[], lbl_803b2ef4[], lbl_803b2f00[], lbl_803b2f18[];
static inline int Lookup(Ptr32<const char> k, Ptr32<int> v) { return tsonnet_c26_lookup_int_80206920(k, v); }
/* Las arenas se dimensionaron para los 24 MB de GameCube. Con terreno, MField y XContainer se llenan en la carga; aquí sobra memoria. */
enum { W3D_ARENA_SCALE = 3 };
extern "C" int w3d_env_int(const char *, int *);
extern "C" int w3d_d41e_heap_config_802092c8(Ptr32<Heap> self)
{
    w3d_empty_802092c0(self);
    if (self->base) return 1;
    if (!self->name) return 0x80004005;
    char buf[256];
    int size = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2ee4, w3d::VA(self->name));
    Lookup(buf, &size);
    int debug = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2ef4, w3d::VA(self->name));
    Lookup(buf, &debug);
    if (debug) self->flags = w3d_get_802092b8(self) | 3;
    w3d_empty_802092c4(self);
    int pass = 0;
    w3d_format_into_8034cb64(buf, lbl_803b2f00, w3d::VA(self->name));
    Lookup(buf, &pass);
    if (!pass) {
        w3d_format_into_8034cb64(buf, lbl_803b2f18, w3d::VA(self->name));
        Lookup(buf, &pass);
    }
    if (pass) self->flags = w3d_get_802092b8(self) | 16;
#if defined(__3DS__)
    { int pct = 250; w3d_env_int("W3D_ARENA_PCT", &pct); size = (int)((long long)size * pct / 100); }
#else
    size *= W3D_ARENA_SCALE;
#endif
    w3d_d30e_heap_init_8020941c(self, size);
    return 0;
}


