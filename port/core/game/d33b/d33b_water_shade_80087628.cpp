#include "w3d_ptr.h"
#line 1 "d33b_water_shade_80087628.cpp"
// GWMP8P rev0 0x80087628. Water shade update.
/* Water shade update (0x80087628): reads the fade scale (+2780, 0x80342a74, 0x80178df0)
 * and for each of the vertices (+2478) sets the alpha of the colour lists +680 and +688
 * from how far the vertex height (+672, +4) lies below the water level (0x804b17e0 +108).
 * Field and type names are inferred from the original instructions. Owns its float
 * literal at 0x8037d0e0. */
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3 &o) { float ax = o.x, ay = o.y, az = o.z; x = ax; y = ay; z = az; } };
struct Object;
extern "C" Ptr32<Object> w3d_empty_80342a74(Ptr32<Object>);
extern "C" float w3d_auto_80178df0(Ptr32<Object>);
struct Bounds { char unknown00[372]; Vec3 box; };
struct World { char unknown00[108]; float level; };
struct Vertex { char unknown00[4]; float height; char unknown08[4]; };
extern Ptr32<World> w3d_world_804b17e0;
struct WaterMesh {
    char unknown00[532];
    Ptr32<Bounds> bounds;       /* +532 */
    char unknown536[136];
    Ptr32<Vertex> vertices;     /* +672 */
    char unknown676[4];
    Ptr32<unsigned int> colours;    /* +680 */
    char unknown684[4];
    Ptr32<unsigned int> shades;     /* +688 */
    char unknown692[1786];
    unsigned short count; /* +2478 */
    char unknown2480[8];
    unsigned colour;      /* +2488 */
    char unknown2492[288];
    Ptr32<Object> fade;         /* +2780 */
};
extern "C" int d33b_water_shade_80087628(Ptr32<WaterMesh> self)
{
    float scale = w3d_auto_80178df0(w3d_empty_80342a74(self->fade));
    Vec3 box(self->bounds->box);
    float level;
    level = box.z;
    float wy = box.y, wx = box.x;
    if (wx > wy) level = wy;
    if (level > wx) level = wy;
    level = w3d_world_804b17e0->level;
    for (unsigned i = 0; i < self->count; i++) {
        float depth = self->vertices[i].height - level;
        unsigned shade = 0;
        if (depth < 0.0f) {
            shade = self->colour;
            unsigned alpha = (int)(-depth * scale);
            if (alpha > 255) alpha = 255;
            shade |= alpha << 24;
            self->colours[i] &= 0x00ffffff;
        }
        self->shades[i] = shade;
    }
    return 0;
}


