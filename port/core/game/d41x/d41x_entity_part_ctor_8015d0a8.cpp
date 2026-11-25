#include "w3d_ptr.h"
#line 1 "d41x_entity_part_ctor_8015d0a8.cpp"
// d41x: 0x8015d0a8. Constructor of an object holding a vector, a retained
// entry from 0x80208aac and a colour. Names inferred. Flags: -mps-float.
#include "compat/stlport_sn_oom.h"
#include <vector>
struct Entry;
struct EntryVt { char u0[12]; Ptr32<void (Ptr32<Entry>)> retain; Ptr32<void (Ptr32<Entry>)> release; char u14[12]; Ptr32<int (Ptr32<Entry>, int)> flags; };
struct Entry { Ptr32<EntryVt> vt; };
struct Color { float r, g, b, a; Color(float x, float y, float z, float w) { r = x; g = y; b = z; a = w; } };
extern "C" Ptr32<Entry> create_80208aac(int);
// A real STLport vector member explains the words at 0, 4 and 12 (word 8 is the
// allocator proxy's empty base) and the 8 unwritten frame bytes: its default-argument
// allocator temporary. Element type is not visible here; int is a partial view.
struct EntityPart_8015d0a8 {
    _STL::vector<int> list; int f16; int f20; Ptr32<Entry> f24; float f28; float f32;
    Color f36; unsigned short f52;
    EntityPart_8015d0a8();
    void set(Ptr32<Entry> e) { if (e) e->vt->retain(e); if (f24) f24->vt->release(f24); f24 = e; }
};
EntityPart_8015d0a8::EntityPart_8015d0a8() : f16(0), f20(0), f24(0), f36(1.0f, 0.0f, 0.5f, 0.5f) {
    Ptr32<Entry> e = create_80208aac(0);
    set(e);
    e->vt->flags(e, 2048);
    f24->vt->flags(f24, 0);
    f28 = 0.0f;
    f32 = 0.0f;
    f52 = 12;
}


