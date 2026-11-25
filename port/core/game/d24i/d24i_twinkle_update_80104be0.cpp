#include "w3d_ptr.h"
#line 1 "d24i_twinkle_update_80104be0.cpp"
// d24i: 0x80104be0 (408 bytes). Update 30 twinkling mesh colours (records at +80,
// when the mesh object +48 exists). An idle record picks a random colour index
// below +60 (0x8015ff5c), remembers its current brightness and a random target
// below 255. An active record advances its timer by the elapsed time; while the
// scaled time is at most 1.0f it writes the interpolated brightness as an opaque
// grey into the mesh colours (0x80189760); afterwards it goes idle.
struct d24i_Colour {
    unsigned char r, g, b;
    signed char a;
};
static inline void d24i_grey(Ptr32<d24i_Colour> colour, unsigned char grey) {
    colour->r = grey;
    colour->g = grey;
    colour->b = grey;
    colour->a = -1;
}
struct d24i_Twinkle {
    int index;                           // +0, 0 when idle
    float from;                          // +4
    float to;                            // +8
    unsigned timer;                      // +12
};
struct d24i_Field {
    unsigned char unknown00[48];
    Ptr32<void> mesh;                          // +48
    unsigned char unknown34[8];
    unsigned colour_count;               // +60
    unsigned char unknown40[16];
    d24i_Twinkle twinkles[30];           // +80
};
extern "C" Ptr32<void> d24i_as_mesh_8034380c(Ptr32<void>);
extern "C" Ptr32<d24i_Colour> d24i_mesh_colours_80189760(Ptr32<void>);
extern "C" unsigned d24i_random_8015ff5c(Ptr32<d24i_Field>);
extern const float d24i_rate_80399820[], d24i_one_80399824[];

extern "C" void d24i_twinkle_update_80104be0(Ptr32<d24i_Field> self, unsigned elapsed) {
    if (self->mesh) {
        Ptr32<void> mesh = d24i_as_mesh_8034380c(self->mesh);
        for (unsigned i = 0; i < 30; ++i) {
            Ptr32<d24i_Twinkle> twinkle = &self->twinkles[i];
            if (twinkle->index) {
                float one = d24i_one_80399824[0];
                unsigned timer = twinkle->timer + elapsed;
                twinkle->timer = timer;
                float t = (float)timer * d24i_rate_80399820[0];
                if (t <= one) {
                    unsigned char grey = (unsigned char)((one - t) * twinkle->from + t * twinkle->to);
                    Ptr32<d24i_Colour> colours = d24i_mesh_colours_80189760(mesh);
                    d24i_grey(&colours[twinkle->index], grey);
                } else {
                    twinkle->index = 0;
                }
            } else {
                twinkle->index = d24i_random_8015ff5c(self) % self->colour_count;
                Ptr32<d24i_Colour> colours = d24i_mesh_colours_80189760(mesh);
                twinkle->from = (float)colours[twinkle->index].r;
                unsigned target = d24i_random_8015ff5c(self);
                twinkle->timer = 0;
                twinkle->to = (float)(target % 255);
            }
        }
    }
}


