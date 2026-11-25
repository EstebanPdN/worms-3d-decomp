#include "w3d_ptr.h"
#line 1 "k10a_overlay_ctor_80106bd0.cpp"
// Appears to construct a derived scene object: runs the base constructor,
// installs the two vtables and sets default colour, extent and timing fields.
inline void *operator new(__SIZE_TYPE__, void *place) { return place; }

struct K10aVec3
{
    float x, y, z;
    K10aVec3(float v) { x = v; y = v; z = v; }
};

struct K10aOverlay
{
    Ptr32<void> vtable;          // +0
    char pad4[32];
    int link;              // +36
    char pad40[216];
    Ptr32<void> vtable2;         // +256
    char pad260[44];
    int cursor;            // +304
    char pad308[24];
    K10aVec3 origin;       // +332
    unsigned char red;     // +344
    unsigned char green;   // +345
    char pad346[2];
    K10aVec3 extent;       // +348
    int slot;              // +360
    int target;            // +364
    int limit_a;           // +368
    int limit_b;           // +372
    int limit_c;           // +376
    float duration;        // +380
    int mode;              // +384
};

extern char w3d_vtable_804106d0[];
extern char w3d_vtable_8040ffb8[];
extern "C" int w3d_auto_800e0678(Ptr32<K10aOverlay> self);

extern "C" Ptr32<K10aOverlay> w3d_k10a_overlay_ctor_80106bd0(Ptr32<K10aOverlay> self)
{
    w3d_auto_800e0678(self);
    self->vtable2 = w3d_vtable_8040ffb8;
    self->vtable = w3d_vtable_804106d0;
    self->target = 0;
    self->cursor = 0;
    self->green = 255;
    self->link = 0;
    self->red = 255;
    new (&self->extent) K10aVec3(0.0f);
    self->slot = -1;
    new (&self->origin) K10aVec3(0.0f);
    self->limit_a = 200;
    self->limit_b = 200;
    self->limit_c = 200;
    self->duration = 60.0f;
    self->mode = 2;
    return self;
}


