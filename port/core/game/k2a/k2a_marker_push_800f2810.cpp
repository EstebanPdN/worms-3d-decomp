#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "k2a_marker_push_800f2810.c"
typedef struct K2aVec3Words { int x, y, z; } K2aVec3Words;
typedef struct K2aMarker { K2aVec3Words position; float lifetime; unsigned char alpha; unsigned char pad[3]; } K2aMarker;
typedef struct K2aMarkerList { char pad0[32]; K2aMarker markers[50]; unsigned int count; } K2aMarkerList;
extern const float w3d_f32_8038c4a4[];

void k2a_marker_push_800f2810(Ptr32<K2aMarkerList> self, Ptr32<K2aVec3Words> position)
{
    if (self->count > 48)
        return;
    ((Ptr32<K2aMarker>)(self->count * 20 + (Ptr32<char>)self->markers))->position = *position;
    self->markers[self->count].lifetime = w3d_f32_8038c4a4[0];
    self->markers[self->count].alpha = 200;
    self->count++;
}

}
