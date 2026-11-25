#include "w3d_ptr.h"
#line 1 "d26a_emitters_setup_800370cc.cpp"
// GWMP8P rev0 0x800370cc. Effect emitter setup: creates ten named emitters
// stored at +36, configures each and places them along a line, stepping the
// position by a fixed vector. Names are inferred from the original
// instructions.
struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) { x = a; y = b; z = c; }
    void operator+=(const Vec3 &o) { x += o.x; y += o.y; z += o.z; }
};
struct Emitter;
struct EmitterGroup { char unknown00[36]; Ptr32<Emitter> items[10]; };
extern "C" Ptr32<void> w3d_heap_alloc_801fe1d8(int);
extern "C" Ptr32<Emitter> w3d_emitter_create_8025dffc(Ptr32<void>, Ptr32<const char>, unsigned char);
extern "C" int w3d_emitter_setup_8025e128(Ptr32<Emitter>, float, float, float);
extern "C" void w3d_emitter_place_8025ee60(Ptr32<Emitter>, Ptr32<Vec3>);
inline void Setup(Ptr32<Emitter> &out, Ptr32<Emitter> e, float a, float b, float c)
{
    out = e;
    w3d_emitter_setup_8025e128(e, a, b, c);
}
extern "C" void w3d_d26a_emitters_setup_800370cc(Ptr32<EmitterGroup> self)
{
    Vec3 position(-150.0f, 150.0f, 0.0f);
    Vec3 unused(0.0f, 100.0f, 0.0f);
    Vec3 step(20.0f, -20.0f, 0.0f);
    Ptr32<Ptr32<Emitter>> slot = self->items;
    for (unsigned i = 0; i < 10; i++) {
        Setup(*slot, w3d_emitter_create_8025dffc(w3d_heap_alloc_801fe1d8(4), "FE.NewBox.Blue", i % 5 + 28), 20.0f, 100.0f, 50.0f);
        w3d_emitter_place_8025ee60(*slot, &position);
        slot++;
        position += step;
    }
}


