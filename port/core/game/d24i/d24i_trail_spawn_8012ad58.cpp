#include "w3d_ptr.h"
#line 1 "d24i_trail_spawn_8012ad58.cpp"
// d24i: 0x8012ad58 (360 bytes). Emit one trail particle when at least 2048 time
// units passed since the slot's stamp (table +328 indexed by cursor +936). Stamps
// the slot with now - 200, opens the particle arrays of the buffer +928 and writes
// the slot's random rotation (angle below 360 in radians), position (source x and
// z with height -0.5f, copied as three words) and colour 0x00ffffff. The cursor
// wraps after 50 slots.
struct d24i_Vec3 { float x, y, z; };
struct d24i_Emitter {
    unsigned char unknown00[328];
    unsigned table[150];                 // +328
    Ptr32<void> buffer;                        // +928
    unsigned char unknown3a4[4];
    unsigned cursor;                     // +936
    unsigned now;                        // +940
};
struct d24i_Copy { unsigned a, b, c; };
extern "C" Ptr32<d24i_Copy> d24i_positions_80189518(Ptr32<void>);
extern "C" Ptr32<unsigned int> d24i_colours_80189760(Ptr32<void>);
extern "C" Ptr32<float> d24i_rotations_80189574(Ptr32<void>);
extern "C" unsigned d24i_random_8015ff5c(Ptr32<d24i_Emitter>);
extern const float d24i_pi_8039d2a0[], d24i_half_turn_8039d2a4[], d24i_height_8039d2a8[];

extern "C" void d24i_trail_spawn_8012ad58(Ptr32<d24i_Emitter> self, Ptr32<d24i_Vec3> source) {
    Ptr32<unsigned int> stamps = self->table;
    unsigned index = (self->cursor + 100) << 2;
    unsigned now = self->now;
    if (*(Ptr32<unsigned int>)((Ptr32<char>)stamps + index) <= now - 2048) {
        *(Ptr32<unsigned int>)((Ptr32<char>)stamps + index) = now - 200;
        Ptr32<void> buffer = self->buffer;
        Ptr32<d24i_Copy> positions = d24i_positions_80189518(buffer);
        Ptr32<unsigned int> colours = d24i_colours_80189760(buffer);
        Ptr32<float> rotations = d24i_rotations_80189574(buffer);
        (rotations + self->cursor)[100] =
            (float)(d24i_random_8015ff5c(self) % 360) * d24i_pi_8039d2a0[0] / d24i_half_turn_8039d2a4[0];
        d24i_Vec3 position;
        position.x = source->x;
        Ptr32<d24i_Vec3> p = &position;
        p->y = source->z;
        p->z = d24i_height_8039d2a8[0];
        (positions + self->cursor)[100] = *(Ptr32<d24i_Copy>)&position;
        (colours + self->cursor)[100] = 0x00ffffff;
        if (++self->cursor > 49)
            self->cursor = 0;
    }
}


