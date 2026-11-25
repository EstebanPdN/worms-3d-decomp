typedef struct K2aVec3Words { int x, y, z; } K2aVec3Words;
typedef struct K2aMarker { K2aVec3Words position; float lifetime; unsigned char alpha; unsigned char pad[3]; } K2aMarker;
typedef struct K2aMarkerList { char pad0[32]; K2aMarker markers[50]; unsigned int count; } K2aMarkerList;
extern const float w3d_f32_8038c4a4[];

void k2a_marker_push_800f2810(K2aMarkerList *self, K2aVec3Words *position)
{
    if (self->count > 48)
        return;
    ((K2aMarker *)(self->count * 20 + (char *)self->markers))->position = *position;
    self->markers[self->count].lifetime = w3d_f32_8038c4a4[0];
    self->markers[self->count].alpha = 200;
    self->count++;
}
