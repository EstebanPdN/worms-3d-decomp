#include "w3d_ptr.h"
#line 1 "d29g_sky_start_8004f564.cpp"
/* Worms 3D GameCube PAL 0x8004f564. Sky start: stores the service for one name at +68, registers two more services for the object id, starts the geyser particle at (0, 0, -10), binds a global with the sound service, then loads a 3 by 3 checkerboard of sprites into the grid at +28 from the Shotgun and Uzi resources, placing each at 130-unit spacing centred on the origin and sized 4.6. Field and type names are inferred from the original instructions; strings and globals are external views of original data. */
extern "C" void w3d_string_base_finish(Ptr32<void>), w3d_string_release(Ptr32<void>);
struct String {
    Ptr32<char> text;
    template <class W3dU> String(Ptr32<W3dU> w3d_p) : String((const char *)w3d_p.get()) {}
 String(const char *);
    String(const String &);
    ~String() { w3d_string_base_finish(this); w3d_string_release(this); }
};
struct Vec {
    float x, y, z;
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
};
struct Sprite;
struct SpriteVt { char u[76]; Ptr32<void (Ptr32<Sprite>, const Vec &, int)> place; char u80[84 - 80]; Ptr32<void (Ptr32<Sprite>, const Vec &, int)> size; };
struct Sprite { Ptr32<SpriteVt> vt; };
struct Sky { char u0[20]; int id; char u24[28 - 24]; Ptr32<Sprite> grid[9]; char u64[68 - 64]; int service; };
struct Sound { struct Vt { char u[92]; Ptr32<void (Ptr32<Sound>, Ptr32<void>)> bind; }; Ptr32<struct Vt> vt; };
extern "C" {
int w3d_s10_service_forward_8020b680(Ptr32<void>);
int w3d_register_80164514(Ptr32<void>, Ptr32<void>, int);
int w3d_s20_forward_global_800e5ca4(const Vec &, Ptr32<const char>, int, float);
Ptr32<Sound> w3d_auto_8020b648();
int w3d_load_8015adf4(const String &, Ptr32<Ptr32<Sprite>>, int);
}
extern char name_80417120[], name_80410680[], name_804100a8[], effect_803778fc[];
extern char bind_804143e0[];
extern Ptr32<void> registry_804b178c;
extern "C" void w3d_d29g_sky_start_8004f564(Ptr32<Sky> self)
{
    Ptr32<Ptr32<Sprite>> grid = self->grid;
    self->service = w3d_s10_service_forward_8020b680(name_80417120);
    int h1 = w3d_s10_service_forward_8020b680(name_80410680);
    w3d_register_80164514(registry_804b178c, (Ptr32<void>)w3d::G(h1), self->id);
    int h2 = w3d_s10_service_forward_8020b680(name_804100a8);
    w3d_register_80164514(registry_804b178c, (Ptr32<void>)w3d::G(h2), self->id);
    Vec pos(0.0f, 0.0f, -10.0f);
    w3d_s20_forward_global_800e5ca4(pos, effect_803778fc, 0, 0.0f);
    Ptr32<void> binding = bind_804143e0;
    Ptr32<Sound> s = w3d_auto_8020b648();
    s->vt->bind(s, binding);
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            Ptr32<Sprite> &g = grid[i + j * 3];
            if ((i + j) & 1) {
                w3d_load_8015adf4(String("Shotgun"), &g, 255);
                g->vt->place(g, Vec((float)i * 130.0f + -130.0f, (float)j * 130.0f + -130.0f, 0.0f), 0);
                g->vt->size(g, Vec(4.6f, 4.6f, 4.6f), 0);
            } else {
                w3d_load_8015adf4(String("Uzi"), &g, 255);
                g->vt->place(g, Vec((float)i * 130.0f + -130.0f, (float)j * 130.0f + -130.0f, 0.0f), 0);
                g->vt->size(g, Vec(4.6f, 4.6f, 4.6f), 0);
            }
        }
    }
}


