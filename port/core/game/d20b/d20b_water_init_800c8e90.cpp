#include "w3d_ptr.h"
#line 1 "d20b_water_init_800c8e90.cpp"
// d20b: 0x800c8e90 (976 bytes). Initialise the water plane: publish the
// instance (0x804b1794), clear the offset (+360) and build a 20-point unit
// ring (+88, step 2*pi/20 starting at one step); load the plane resource
// ("WaterPlane" in game mode 7, otherwise "FE.WaterPlane") into +28; read the
// Water.Level setting (+356); build the plane and its waves; scale the plane
// by 8700 and place it at the level height (whole sixteenths, odd); read the
// GlobalLight.Diffuse setting (+372); look up the Water.TweakName object, load
// its mesh (+36) by the tweak's mesh name, tint it with the tweak's colour,
// place it like the plane, scale it by (0.5, 0.8, 0.5) and show it.
// 0x8015adf4 forwards the resource manager's virtual load result, so it is
// declared with a status return. The red channel is read straight from the
// colour copy and the other channels through a reference to it (the copy is
// kept in a register for the first read and lives on the stack for the
// rest). Built with -mfast-cast (byte to float conversions through psq_l)
// and -mps-float: without -mps-float the build differs only by the 48-byte
// frame gap below the six saved FPRs. The strings and float literals form
// this function's .rodata at 0x80387b68 in first-use order; Water.TweakName
// is shared with an earlier function and stays an external object.
struct d20b_String_8020bb54 {
 d20b_String_8020bb54(const d20b_String_8020bb54 &);
    Ptr32<char> text;
    template <class W3dU> d20b_String_8020bb54(Ptr32<W3dU> w3d_p) : d20b_String_8020bb54((const char *)w3d_p.get()) {}
 d20b_String_8020bb54(const char *);
    ~d20b_String_8020bb54();
};
extern "C" void d20b_string_finish_8020c5c4(Ptr32<d20b_String_8020bb54>);
extern "C" void d20b_string_release_80341588(Ptr32<d20b_String_8020bb54>);
inline d20b_String_8020bb54::~d20b_String_8020bb54() {
    d20b_string_finish_8020c5c4(this);
    d20b_string_release_80341588(this);
}
struct d20b_Vec2 { float x, y; };
struct d20b_Vec3 { float x, y, z; };
struct d20b_Colour { unsigned char r, g, b, a; };
struct d20b_Tint { float r, g, b, a; };
struct d20b_Node;
struct d20b_NodeVtable {
    Ptr32<void> unknown00[19];
    Ptr32<int (Ptr32<d20b_Node>, Ptr32<const d20b_Vec3>, int)> set_position;  // +76
    Ptr32<void> unknown80;
    Ptr32<int (Ptr32<d20b_Node>, Ptr32<const d20b_Vec3>, int)> set_scale;     // +84
    Ptr32<int (Ptr32<d20b_Node>, int)> set_visible;                      // +88
};
struct d20b_Node { Ptr32<d20b_NodeVtable> vtable; };
struct d20b_WaterTweak {
    unsigned char unknown000[120];
    d20b_Colour colour;                  // +120
    unsigned char unknown124[4];
    d20b_String_8020bb54 mesh_name;      // +128
};
struct d20b_Game { unsigned char unknown000[208]; int mode; };
struct d20b_Water {
    unsigned char unknown000[28];
    Ptr32<d20b_Node> plane;                    // +28
    unsigned char unknown032[4];
    Ptr32<d20b_Node> mesh;                     // +36
    unsigned char unknown040[48];
    d20b_Vec3 ring[20];                  // +88
    unsigned char unknown328[28];
    Ptr32<void> level;                         // +356
    float offset;                        // +360
    unsigned char unknown364[8];
    Ptr32<void> diffuse;                       // +372
};
extern "C" int d20b_handle_load_8015adf4(Ptr32<const d20b_String_8020bb54>, Ptr32<Ptr32<d20b_Node>>, unsigned char);
extern "C" int d20b_setting_read_800fc1b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<void>>);
extern "C" int d20b_setting_find_800fc2b0(Ptr32<Ptr32<const char>>, Ptr32<Ptr32<void>>);
extern "C" int d20b_setting_object_800fc330(Ptr32<Ptr32<void>>, Ptr32<Ptr32<d20b_WaterTweak>>);
extern "C" int d20b_water_build_800c9260(Ptr32<d20b_Water>);
extern "C" int d20b_water_waves_800c96f0(Ptr32<d20b_Water>, Ptr32<d20b_Vec2>, float, float, float, float);
extern "C" Ptr32<void> d20b_as_value_80342a74(Ptr32<void>);
extern "C" float d20b_value_read_80178df0(Ptr32<void>);
extern "C" int d20b_mesh_set_tint_80182178(Ptr32<d20b_Node>, Ptr32<d20b_Tint>);
extern "C" float cosf(float);
extern "C" float sinf(float);
extern Ptr32<d20b_Water> d20b_water_804b1794;
extern Ptr32<d20b_Game> d20b_game_804aaabc;
extern const char d20b_tweak_name_80387b04[];       // "Water.TweakName"

extern "C" void d20b_water_init_800c8e90(Ptr32<d20b_Water> self) {
    d20b_water_804b1794 = self;
    self->offset = 0.0f;
    for (unsigned i = 1; i <= 20; i++) {
        Ptr32<d20b_Vec3> ring = &self->ring[i - 1];
        float angle = (float)i * 6.2831854820251465f / 20.0f;
        float c = cosf(angle);
        float sn = sinf(angle);
        ring->x = c;
        ring->z = sn;
        ring->y = 0.0f;
    }
    if (d20b_game_804aaabc->mode == 7) {
        d20b_String_8020bb54 name("WaterPlane");
        d20b_handle_load_8015adf4(&name, &self->plane, 255);
    } else {
        d20b_String_8020bb54 name("FE.WaterPlane");
        d20b_handle_load_8015adf4(&name, &self->plane, 255);
    }
    Ptr32<const char> level_key = "Water.Level";
    d20b_setting_read_800fc1b0(&level_key, &self->level);
    float zero = 0.0f;
    d20b_Vec2 wave;
    Ptr32<d20b_Vec2> w = &wave;
    wave.x = zero;
    w->y = zero;
    d20b_water_build_800c9260(self);
    d20b_water_waves_800c96f0(self, w, 0.1f, 0.35f, 100.0f, 1.0f);
    d20b_Vec3 scale;
    Ptr32<d20b_Vec3> s = &scale;
    scale.x = 8700.0f;
    s->y = 8700.0f;
    s->z = 8700.0f;
    self->plane->vtable->set_scale(self->plane, s, 0);
    int height = (int)(d20b_value_read_80178df0(d20b_as_value_80342a74(self->level)) * 16.0f);
    d20b_Vec3 pos;
    Ptr32<d20b_Vec3> p = &pos;
    pos.x = zero;
    pos.y = (float)(height | 1) * 0.0625f;
    p->z = zero;
    self->plane->vtable->set_position(self->plane, p, 0);
    Ptr32<const char> diffuse_key = "GlobalLight.Diffuse";
    d20b_setting_read_800fc1b0(&diffuse_key, &self->diffuse);
    Ptr32<d20b_WaterTweak> tweak = 0;
    Ptr32<const char> tweak_key = d20b_tweak_name_80387b04;
    Ptr32<void> found;
    d20b_setting_find_800fc2b0(&tweak_key, &found);
    d20b_setting_object_800fc330(&found, &tweak);
    Ptr32<d20b_WaterTweak> t = tweak;
    d20b_handle_load_8015adf4(&t->mesh_name, &self->mesh, 255);
    d20b_Colour colour = t->colour;
    d20b_Tint tint;
    float red = colour.r;
    const d20b_Colour &c = colour;
    float green = c.g, blue = c.b, alpha = c.a;
    tint.r = red / 255.0f;
    tint.g = green / 255.0f;
    tint.b = blue / 255.0f;
    tint.a = alpha / 255.0f;
    d20b_mesh_set_tint_80182178(self->mesh, &tint);
    self->mesh->vtable->set_position(self->mesh, p, 0);
    pos.x = 0.5f;
    p->y = 0.8f;
    p->z = 0.5f;
    self->mesh->vtable->set_scale(self->mesh, p, 0);
    self->mesh->vtable->set_visible(self->mesh, 1);
}


