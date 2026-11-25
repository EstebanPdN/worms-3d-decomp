#include "w3d_ptr.h"
#line 1 "k10a_object_reset_8012a618.cpp"
// Appears to reset a scene object: stamps its current position as the anchor,
// zeroes the anchor height, then refreshes its placement and events.
struct K10aVec3
{
    float x, y, z;
    K10aVec3() {}
    K10aVec3(const K10aVec3 &o) : x(o.x), y(o.y), z(o.z) {}
};

// Partial view of a 20-byte point payload built on the stack: only the
// position is initialised here.
struct K10aPointPayload
{
    float x, y, z;
    float extra[2];
    K10aPointPayload(float v) { x = v; y = v; z = v; }
};

struct K10aObject
{
    char pad0[36];
    K10aVec3 attach;      // +36
    K10aVec3 position;    // +48
    char pad60[132];
    Ptr32<void> context;        // +192
    char pad196[112];
    int anchored;         // +308
    K10aVec3 anchor;      // +312
};

extern "C" Ptr32<void> w3d_empty_80341584(Ptr32<void>);
extern "C" Ptr32<void> w3d_auto_801797b4(Ptr32<void>);
extern "C" void fn_800eac84(Ptr32<K10aObject>, Ptr32<K10aVec3>);
extern "C" void fn_800eb6e4(Ptr32<K10aObject>);
extern "C" void s8_post_object_events_800ed090(Ptr32<K10aObject>);
extern "C" void w3d_s20_play_sound_pair_800edca0(Ptr32<K10aObject>);

extern "C" void w3d_k10a_object_reset_8012a618(Ptr32<K10aObject> self)
{w3d_auto_801797b4((Ptr32<void>)w3d_empty_80341584(self->context));
    self->anchored = 1;
    self->anchor = self->position;
    self->anchor.y = 0.0f;
    fn_800eac84(self, &self->attach);
    fn_800eb6e4(self);
    K10aPointPayload zero(0.0f);
    s8_post_object_events_800ed090(self);
    w3d_s20_play_sound_pair_800edca0(self);
}


